using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace BehaviorGraphics
{
    public partial class WhichLabForm : Form
    {
        private int lab;

        public WhichLabForm()
        {
            lab = -1;

            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            LabList ll = LabList.FromXML();

            try {
                lab = int.Parse(textBox1.Text);

                foreach (LabSpecification ls in ll) {
                    if (ls.Lab == lab) {
                        RegistryHelper.Lab = lab;
                        this.Close();
                        return;
                    }
                }
            } catch (Exception) {
            }

            MessageBox.Show("Please enter a valid lab number", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        public int Lab
        {
            get { return lab; }
        }

        private void WhichLabForm_Shown(object sender, EventArgs e) {
            try {
                textBox1.Text = RegistryHelper.Lab.ToString();
            } catch (RegistryHelper.RegistryHelperException) {
                textBox1.Text = "";
            }
        }
    }
}
