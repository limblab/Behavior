using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace AngleBox {
    public partial class AngleEntryBox : UserControl {
        private double angle; // stored in radians
        private AngleMode mode;

        public AngleEntryBox() {
            angle = 0;
            mode = AngleMode.Radians;

            InitializeComponent();
            UpdateText();
        }

        public void UpdateText() {
            if (mode == AngleMode.Radians) {
                button1.Text = "Rad";
                textBox1.Text = String.Format("{0:0.##}", angle);
            } else {
                button1.Text = "Deg";
                textBox1.Text = String.Format("{0:0.#}", angle * 360 / 2 / Math.PI);
            }
        }

        private void updateValue() {
            try {
                if (mode == AngleMode.Radians) {
                    angle = Double.Parse(textBox1.Text);
                } else {
                    angle = Double.Parse(textBox1.Text) * Math.PI / 180;
                }
            } catch {
            }
        }

        private void button1_Click(object sender, EventArgs e) {
            this.updateValue();

            if (mode == AngleMode.Radians) {
                mode = AngleMode.Degrees;
            } else {
                mode = AngleMode.Radians;
            }
            this.UpdateText();
        }

        private void textBox1_Leave(object sender, EventArgs e) {
            updateValue();
            UpdateText();
        }

        public double Value {
            get {
                return angle;
            }
            set {
                angle = value;
                UpdateText();
            }
        }


        private enum AngleMode { Degrees, Radians }
    }
}
