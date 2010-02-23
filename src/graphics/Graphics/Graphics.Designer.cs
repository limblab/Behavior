namespace BehaviorGraphics
{
    partial class Graphics
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Graphics));
            this.FrameTimer = new System.Windows.Forms.Timer(this.components);
            this.FlashTimer = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // FrameTimer
            // 
            this.FrameTimer.Enabled = true;
            this.FrameTimer.Interval = 40;
            this.FrameTimer.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // FlashTimer
            // 
            this.FlashTimer.Enabled = true;
            this.FlashTimer.Interval = 300;
            this.FlashTimer.Tick += new System.EventHandler(this.FlashTimer_Tick);
            // 
            // Graphics
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            //this.ClientSize = new System.Drawing.Size(541, 360);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "Graphics";
            this.Text = "Graphics";
            this.Click += new System.EventHandler(this.Graphics_Click);
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Graphics_FormClosing);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Timer FrameTimer;
        private System.Windows.Forms.Timer FlashTimer;
    }
}

