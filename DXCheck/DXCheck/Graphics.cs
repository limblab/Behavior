using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;
using System.Drawing;
using System.Text;
using System.Net;
using System.Net.Sockets;
using Microsoft.DirectX;
using Microsoft.DirectX.Direct3D;

namespace DXCheck
{
    public partial class Graphics : Form
    {
        private double x, y;
        private bool connectionLost;
        private bool flashOn;

        private Device device;
        private Microsoft.DirectX.Direct3D.Font font;
        private Microsoft.DirectX.Direct3D.Font errFont;
        private Texture cursorTexture;

        private SoundPlayer sp;
        private double tone_id, tone_cnt;

        private Socket server;
        private EndPoint remote;

        private float scale;

        TargetSprite t1, t2;

        private UpdateForm updateForm;

        public Graphics()
        {
            x = 0; y = 0;
            connectionLost = false;
            flashOn = false;
            this.scale = 30f;

            // Network
            this.server = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            this.server.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.ReceiveBuffer, 1);
            this.server.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.ReceiveTimeout, 10);
            IPEndPoint sender = new IPEndPoint(IPAddress.Any, 25000);
            this.remote = (EndPoint)sender;
            server.Bind(remote);
            
            // Sound
            sp = new SoundPlayer(this);

            // Graphics
            InitializeDevice();
            t1 = new TargetSprite(device);
            t2 = new TargetSprite(device);

            updateForm = new UpdateForm();

            InitializeComponent();
        }

        public void InitializeDevice() {
            PresentParameters presentParams = new PresentParameters();
            presentParams.Windowed = true;
            presentParams.SwapEffect = SwapEffect.Discard;

            device = new Device(0, DeviceType.Hardware, this, CreateFlags.SoftwareVertexProcessing, presentParams);
            device.DeviceReset += new EventHandler(OnDeviceReset);

            System.Drawing.Font systemFont = new System.Drawing.Font("Arial", 18);
            font = new Microsoft.DirectX.Direct3D.Font(device, systemFont);

            System.Drawing.Font systemErrFont = new System.Drawing.Font("Arial", 48);
            errFont = new Microsoft.DirectX.Direct3D.Font(device, systemErrFont);
            
            OnDeviceReset(null, EventArgs.Empty);
        }

        private void OnDeviceReset(object sender, EventArgs e)
        {
            // Textures must be recreated whenever a device is reset
            // no matter what pool they are created in.
            System.Reflection.Assembly a = System.Reflection.Assembly.GetExecutingAssembly();
            System.IO.Stream s = a.GetManifestResourceStream("DXCheck.textures.face.tga");
            cursorTexture = TextureLoader.FromStream(device, s);

            device.RenderState.CullMode = Cull.None;
        }

        public void UpdateGraphics()
        {
            Sprite cursor;

            device.Clear(ClearFlags.Target, Color.Black, 1.0f, 0);
            device.BeginScene();
            //string posStr = String.Format("{0:f}\n{1:f}", this.x, this.y);
            string posStr = String.Format("{0:f}\n{1:f}", this.tone_cnt, this.tone_id);
            font.DrawText(null, posStr, new System.Drawing.Point(10, 10), System.Drawing.Color.White);

            if (connectionLost && flashOn)
            {
                errFont.DrawText(null, "Connection Lost", new System.Drawing.Point(30, this.Height - 150), System.Drawing.Color.HotPink);
            }

            // Draw targets
            t1.Draw();
            t2.Draw();

            // Draw yellow circle
            cursor = new Sprite(device);
            cursor.Begin(SpriteFlags.AlphaBlend);
            cursor.Draw(cursorTexture, Rectangle.Empty, new Vector3(15,15,0), cm2screen(this.x, this.y), Color.White);
            cursor.End();

            device.EndScene(); 
            device.Present();

            cursor.Dispose();
        }

        private Vector3 cm2screen(double x, double y)
        {
            float xpos, ypos;
            int dim;

            dim = (this.ClientRectangle.Height > this.ClientRectangle.Width ? this.ClientRectangle.Width : this.ClientRectangle.Height); // min of height and width
            xpos = this.ClientRectangle.Width / 2 + (float)x * dim / scale;
            ypos = this.ClientRectangle.Height / 2 - (float)y * dim / scale;

            return new Vector3(xpos, ypos, 0);
        }

        private void UpdatePosition()
        {
            byte[] data = new byte[1024];

            try
            {
                int recv = server.ReceiveFrom(data, ref remote);
                x = BitConverter.ToDouble(data, 0);
                y = BitConverter.ToDouble(data, 8);

                t1.Type = (TargetSpriteType)(BitConverter.ToDouble(data, 16));
                t1.UL = cm2screen((float)BitConverter.ToDouble(data, 3*8), (float)BitConverter.ToDouble(data, 4*8));
                t1.LR = cm2screen((float)BitConverter.ToDouble(data, 5*8), (float)BitConverter.ToDouble(data, 6*8));

                t2.Type = (TargetSpriteType)(BitConverter.ToDouble(data, 56));
                t2.UL = cm2screen((float)BitConverter.ToDouble(data, 8 * 8), (float)BitConverter.ToDouble(data, 9 * 8));
                t2.LR = cm2screen((float)BitConverter.ToDouble(data, 10 * 8), (float)BitConverter.ToDouble(data, 11 * 8));

                tone_id  = BitConverter.ToDouble(data, 13 * 8);
                double new_tone_cnt = BitConverter.ToDouble(data, 12 * 8);
                if (new_tone_cnt > tone_cnt || 
                    (new_tone_cnt!=tone_cnt && new_tone_cnt == 1.0)/* target restart hack */ ) 
                {
                    tone_cnt = new_tone_cnt;
                    sp.Play((int)tone_id);
                }

                this.connectionLost = false;
            }
            catch (SocketException e)
            {
                if (e.ErrorCode == 10060)
                {
                    this.connectionLost = true;
                }
                else
                {
                    //running = false;
                    FrameTimer.Enabled = false;
                    MessageBox.Show(e.ToString());
                    Application.Exit();
                }
            }
        }

        protected override void OnPaint(System.Windows.Forms.PaintEventArgs e)
        {
            UpdateGraphics();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            UpdatePosition();
            UpdateGraphics();
        }

        private void FlashTimer_Tick(object sender, EventArgs e)
        {
            flashOn = !flashOn;
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Q) {
                sp.Play(SoundPlayer.SoundID.go);
            }
            if (e.KeyCode == Keys.W) {
                sp.Play(SoundPlayer.SoundID.reward);
            }
            if (e.KeyCode == Keys.E) {
                sp.Play(SoundPlayer.SoundID.abort);
            }
        }

        private void Graphics_Click(object sender, EventArgs e)
        {
            if (updateForm.Visible == false) {
                this.FrameTimer.Enabled = false;
                updateForm.Show(this);
            }
        }

        public void RestartTimer()
        {
            this.FrameTimer.Enabled = true;
        }

        public float ScreenScale
        {
            set { scale = value; this.Invalidate(); }
            get { return scale; }
        }
    }
}