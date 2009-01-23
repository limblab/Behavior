using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace DXCheck
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
    }
}
