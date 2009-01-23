using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace BehaviorGraphics
{
    public partial class BoxConfig : Form
    {
        private Box box;

        public BoxConfig()
        {
            InitializeComponent();
        }

        #region Form Event Callbacks
        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
            this.Close();
            this.Dispose();
        }

        private void buttonOk_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.OK;
            this.Close();
            this.Dispose();
        }

        private void textBox_Leave(object sender, EventArgs e)
        {
            float position;
            try {
                TextBox tb = (TextBox)sender;
                position = (float)Double.Parse(tb.Text);

                if (tb.Text.Equals(textBoxTop.Text)) {
                    box.Top = position;
                }
                if (tb.Text.Equals(textBoxBottom.Text)) {
                    box.Bottom = position;
                }
                if (tb.Text.Equals(textBoxLeft.Text)) {
                    box.Left = position;
                }
                if (tb.Text.Equals(textBoxRight.Text)) {
                    box.Right = position;
                }
            } catch {
                MessageBox.Show("Value must be a position in cm", "Format Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }
        #endregion

        #region Public Attributes
        public Box Box
        {
            get
            {
                return box;
            }
            set
            {
                box = value;
                textBoxBottom.Text = String.Format("{0}", box.Bottom);
                textBoxTop.Text = String.Format("{0}", box.Top);
                textBoxLeft.Text = String.Format("{0}", box.Left);
                textBoxRight.Text = String.Format("{0}", box.Right);
            }
        }
        #endregion
    }
}