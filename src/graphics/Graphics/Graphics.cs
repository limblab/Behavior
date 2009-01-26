using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;
using System.Drawing;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.Xml;
using System.Xml.Serialization;
using Microsoft.DirectX;
using Microsoft.DirectX.Direct3D;
using System.IO;

namespace BehaviorGraphics
{
    public partial class Graphics : Form
    {
        private double x, y;
        private bool connectionLost;
        private bool flashOn;
        private bool fullScreen;

        private int savedWidth = 800;
        private int savedHeight = 600;

        private Device device;
        private Microsoft.DirectX.Direct3D.Font font;
        private Microsoft.DirectX.Direct3D.Font errFont;

        private List<Texture> cursorTextures;
        private Texture activeCursorTexture;
        private CursorDefs cursorDefs;      // List of all cursor definitions (read from xml)
        private CursorDef activeCursor;     // Currently active cursor def
        private int activeCursorIndex = 0;

        private SoundPlayer sp;
        private double tone_id, tone_cnt;

        private Socket server;
        private EndPoint remote;

        private float scale;

        TargetSprite t1, t2;

        // Box variables
        private Box box;
        private CustomVertex.TransformedColored[] boxVertices = new CustomVertex.TransformedColored[5];
        private bool drawBox = true;

        // Other behavior variables
        private float verticalDisplacement;
        private bool keepGraphicsRunning;

        private UpdateForm updateForm;

        public Graphics()
        {
            x = 0; y = 0;
            connectionLost = false;
            flashOn = false;
            fullScreen = false;
            this.scale = 30f;

            this.Box = new Box(-10, -10, 10, 10);
            drawBox = false;

            this.verticalDisplacement = 0.0f;

            // Network
            this.server = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            this.server.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.ReceiveBuffer, 1);
            this.server.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.ReceiveTimeout, 10);
            IPEndPoint sender = new IPEndPoint(IPAddress.Any, 25000);
            this.remote = (EndPoint)sender;
            server.Bind(remote);

            // Sound
            sp = new SoundPlayer(this, SoundPlayer.SoundTheme.Theme1);

            // Load Cursor Definitions
            cursorDefs = CursorDefs.FromXML();

            // Graphics
            InitializeDevice();
            SetCursor(5);
            t1 = new TargetSprite(device);
            t2 = new TargetSprite(device);

            this.keepGraphicsRunning = false;

            updateForm = new UpdateForm();

            InitializeComponent();
        }

        public void SetCursor(int cursorId)
        {
            activeCursorIndex = cursorId;
            activeCursorTexture = cursorTextures[cursorId];
            activeCursor = cursorDefs[cursorId];
        }

        private PresentParameters GetPresentParams()
        {
            PresentParameters presentParams = new PresentParameters();
            if (fullScreen) {
                presentParams.Windowed = false;
                presentParams.BackBufferHeight = device.DisplayMode.Height;
                presentParams.BackBufferWidth = device.DisplayMode.Width;
            } else {
                presentParams.Windowed = true;
                presentParams.BackBufferHeight = this.ClientRectangle.Height;
                presentParams.BackBufferWidth = this.ClientRectangle.Width;
            }

            presentParams.BackBufferFormat = Manager.Adapters[0].CurrentDisplayMode.Format; 
            presentParams.SwapEffect = SwapEffect.Discard;

            return presentParams;
        }

        public void InitializeDevice()
        {
            PresentParameters presentParams = GetPresentParams();

            device = new Device(0, DeviceType.Hardware, this, CreateFlags.SoftwareVertexProcessing, presentParams);
            device.DeviceReset += new EventHandler(OnDeviceReset);
            device.DeviceLost += new EventHandler(OnDeviceLost);

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
            cursorTextures = new List<Texture>();
            foreach (CursorDef cd in cursorDefs) {
                cursorTextures.Add(cd.GetTexture(device));
            }
            activeCursorTexture = cursorTextures[activeCursorIndex];

            device.RenderState.CullMode = Cull.None;
        }

        private void OnDeviceLost(object sender, EventArgs e)
        {
            PresentParameters presentParams = GetPresentParams();

            try {
                device.TestCooperativeLevel(); //let's check what the state of the device is, if we can reset the device or not.
            } catch (DeviceLostException) {
                //We don't do anything, the device is still in a state that we cannot reset it.
            } catch (DeviceNotResetException) { //The device can be reset
                try {
                    device.Reset(presentParams); //Reset the device.
                } catch (DeviceLostException) {
                    //We don't do anything, the device is still in a state that we cannot reset it.
                }
            }
        }

        public void UpdateGraphics()
        {
            Sprite cursor;

            device.Clear(ClearFlags.Target, Color.Black, 1.0f, 0);
            device.BeginScene();
#if DEBUG
            string posStr = String.Format("X: {0:f}\nY: {1:f}", this.x, this.y);
            posStr = posStr + "\n" + String.Format("Tone Count: {0}\nTone ID: {1}", this.tone_cnt, this.tone_id);
            posStr = posStr + "\n" + String.Format("Cursor: {0}\n{1}", this.activeCursorIndex, this.activeCursor);
            font.DrawText(null, posStr, new System.Drawing.Point(10, 10), System.Drawing.Color.White);
#endif
            if (connectionLost && flashOn) {
                System.Drawing.Point p;
                if (fullScreen) {
                    p = new System.Drawing.Point(30, device.DisplayMode.Height - 150);
                } else {
                    p = new System.Drawing.Point(30, this.Height - 150);
                }
                errFont.DrawText(null, "No Position Signal", p, System.Drawing.Color.HotPink);
            }

            // Draw targets
            t1.Draw();
            t2.Draw();

            // Draw yellow circle
            cursor = new Sprite(device);
            cursor.Begin(SpriteFlags.AlphaBlend);
            cursor.Draw(activeCursorTexture, Rectangle.Empty, activeCursor.Center, cm2screen(this.x, this.y), Color.White);
            cursor.End();

            // Draw box if necessary
            if (drawBox) {
                refreshBox();
                device.VertexFormat = CustomVertex.TransformedColored.Format;

                device.DrawUserPrimitives(PrimitiveType.LineStrip, 4, boxVertices);
            }

            device.EndScene();
            try {
                device.Present();
            } catch (DeviceLostException) {
                OnDeviceLost(null, EventArgs.Empty);
            }

            cursor.Dispose();
        }

        private Vector3 cm2screen(double x, double y)
        {
            float xpos, ypos;
            int height, width;
            int dim;

            y = y + verticalDisplacement;

            if (fullScreen) {
                height = this.device.DisplayMode.Height;
                width = this.device.DisplayMode.Width;
            } else {
                height = this.ClientRectangle.Height;
                width = this.ClientRectangle.Width;
            }

            dim = (height > width ? width : height); // min of height and width
            xpos = width / 2 + (float)x * dim / scale;
            ypos = height / 2 - (float)y * dim / scale;
            
            return new Vector3(xpos, ypos, 0);
        }

        public void UpdatePosition()
        {
            byte[] data = new byte[1024];

            try {
                int recv = server.ReceiveFrom(data, ref remote);
                x = BitConverter.ToDouble(data, 0);
                y = BitConverter.ToDouble(data, 8);

                t1.Type = (TargetSpriteType)(BitConverter.ToDouble(data, 16));
                t1.UL = cm2screen((float)BitConverter.ToDouble(data, 3 * 8), (float)BitConverter.ToDouble(data, 4 * 8));
                t1.LR = cm2screen((float)BitConverter.ToDouble(data, 5 * 8), (float)BitConverter.ToDouble(data, 6 * 8));

                t2.Type = (TargetSpriteType)(BitConverter.ToDouble(data, 56));
                t2.UL = cm2screen((float)BitConverter.ToDouble(data, 8 * 8), (float)BitConverter.ToDouble(data, 9 * 8));
                t2.LR = cm2screen((float)BitConverter.ToDouble(data, 10 * 8), (float)BitConverter.ToDouble(data, 11 * 8));

                tone_id = BitConverter.ToDouble(data, 13 * 8);
                double new_tone_cnt = BitConverter.ToDouble(data, 12 * 8);
                if (new_tone_cnt > tone_cnt ||
                    (new_tone_cnt != tone_cnt && new_tone_cnt == 1.0)/* target restart hack */ ) {
                    tone_cnt = new_tone_cnt;
                    sp.Play((int)tone_id);
                }

                this.connectionLost = false;
            } catch (SocketException e) {
                if (e.ErrorCode == 10060) {
                    this.connectionLost = true;
                } else {
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
#if DEBUG
            if (e.KeyCode == Keys.Q) {
                sp.Play(SoundPlayer.SoundID.go);
            }
            if (e.KeyCode == Keys.W) {
                sp.Play(SoundPlayer.SoundID.reward);
            }
            if (e.KeyCode == Keys.E) {
                sp.Play(SoundPlayer.SoundID.abort);
            }
#endif
            if (!fullScreen && e.Alt && e.KeyCode == Keys.Enter) {
                /* Go to full screen mode */
                fullScreen = true;
                this.device.Reset(GetPresentParams());
            }

            if (fullScreen && e.KeyCode == Keys.Escape) {
                /* exit full screen mode */
                fullScreen = false;
                this.device.Reset(GetPresentParams());
                this.TopMost = false;
                this.Size = new Size(800, 600);
                this.FormBorderStyle = FormBorderStyle.Sizable;
            }
        }

        private void Graphics_Click(object sender, EventArgs e)
        {
            if (updateForm.Visible == false) {
                if (!keepGraphicsRunning)
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

        public CursorDefs CursorDefs
        {
            get { return cursorDefs; }
        }

        public CursorDef ActiveCursor
        {
            get { return activeCursor; }
        }

        public Box Box
        {
            get
            {
                return box;
            }
            set
            {
                box = value;
                refreshBox();
            }
        }

        public bool KeepGraphicsRunning
        {
            get { return keepGraphicsRunning; }
            set
            {
                keepGraphicsRunning = value;
                this.FrameTimer.Enabled = keepGraphicsRunning;
            }
        }

        public float VerticalDisplacement
        {
            get { return verticalDisplacement; }
            set { verticalDisplacement = value; }
        }

        private void refreshBox()
        {
            Vector3 p;

            p = cm2screen(box.Left, box.Top);
            boxVertices[0].Position = new Vector4(p.X, p.Y, 0.0f, 1.0f);
            boxVertices[0].Color = Color.White.ToArgb();

            p = cm2screen(box.Right, box.Top);
            boxVertices[1].Position = new Vector4(p.X, p.Y, 0.0f, 1.0f);
            boxVertices[1].Color = Color.Purple.ToArgb();

            p = cm2screen(box.Right, box.Bottom);
            boxVertices[2].Position = new Vector4(p.X, p.Y, 0.0f, 1.0f);
            boxVertices[2].Color = Color.White.ToArgb();

            p = cm2screen(box.Left, box.Bottom);
            boxVertices[3].Position = new Vector4(p.X, p.Y, 0.0f, 1.0f);
            boxVertices[3].Color = Color.Purple.ToArgb();

            p = cm2screen(box.Left, box.Top);
            boxVertices[4].Position = new Vector4(p.X, p.Y, 0.0f, 1.0f);
            boxVertices[4].Color = Color.White.ToArgb();
        }

        public bool DrawBox
        {
            get { return drawBox; }
            set { drawBox = value; }
        }

        public SoundPlayer.SoundTheme SoundTheme
        {
            get { return sp.Theme; }
            set { sp = new SoundPlayer(this, value); }
        }

        public double X
        {
            get { return this.x; }
        }

        public double Y
        {
            get { return this.y; }
        }

    }
}