using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Net.Sockets;

namespace BehaviorGraphics
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            try {
                Application.Run(new Graphics());
            } catch (SocketException ex) {
                if (ex.ErrorCode == 10048) {
                    MessageBox.Show("Could not open UDP socket.  Is another copy of this program already running?",
                        "Error opening UDP socket",
                        MessageBoxButtons.OK,
                        MessageBoxIcon.Error);
                } else {
                    MessageBox.Show("Could not open UDP socket.",
                        "Error opening UDP socket",
                        MessageBoxButtons.OK,
                        MessageBoxIcon.Error);
                }
                Application.Exit();
                return;
            }
        }
    }
}