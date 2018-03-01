using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.IO;
using System.Xml;
using System.Xml.Serialization;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using XPCAPICOMLib;
using System.Reflection;
using AngleBox;

namespace BehaviorGraphics
{
    public partial class UpdateForm : Form
    {
        private BehaviorParameters currentBP;
        private bool formWasModified;
        private bool bpWasModified;
        private xPCTarget target;
        private xPCProtocol protocol;
        private bool hasXpcTarget = false;
        private Dictionary<string, string> paramNames;
        private Dictionary<string, string> paramBlocks;
        private Dictionary<string, Control> paramControls;
        //private Dictionary<string, DataGridViewCell> paramCell;

        private const string REG_KEY_PATH = "Software\\Limblab\\BehaviorGraphics";
        private const string REG_KEY_BPDIR = "LastBPDir";
        private const string REG_KEY_MODELDIR = "LastModelDir";

        // Last BehaviorParameters file written or loaded
        private string filename;

        #region Constructor
        public UpdateForm()
        {
            protocol = new xPCProtocol();
            target = new xPCTarget();
            currentBP = new BehaviorParameters();
            bpWasModified = false;
            formWasModified = false;

            if (protocol.Init() < 0) {
                MessageBox.Show("Could not load API.\nMake sure xpcapi.dll is in the path.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            } else {
                /* initialize protocol */
                if (protocol.TcpIpConnect("192.168.0.1", "22222") == 0) {
                    MessageBox.Show("Could not connect to xpc", "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                    return;
                }

                if (protocol.TargetPing() == 0) {
                    MessageBox.Show("Could not ping target", "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                    return;
                }

                if (protocol.TcpIpConnect("192.168.0.1", "22222") == 0) {
                    MessageBox.Show("Could not connect to xpc", "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                    return;
                }

                if (target.Init(protocol) == -1) {
                    string xpcErrorMessage = protocol.GetxPCErrorMsg();
                    if (!xpcErrorMessage.Equals("no error")) {
                        MessageBox.Show("Xpc target not responding: " + xpcErrorMessage, "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                        return;
                    }
                }

                hasXpcTarget = true;
            }

            filename = "";

            InitializeComponent();
            GetStatus();


#if !DEBUG
            if (!hasXpcTarget) {
                this.loadModelToolStripMenuItem.Enabled = false;
                this.buttonRefresh.Enabled = false;
            }
#endif
   
    
            // Setup Anisotropic bump table
            ForceDirections.Rows.Clear();
            ForceDirections.Rows.Add((int)MvNumBumpDirs_ANISO.Value);
            int[] dirs = new int[(int)MvNumBumpDirs_ANISO.Value];

            for (int i = 0; i < MvNumBumpDirs_ANISO.Value; i++)
            {
                dirs[i] = (int)(i * Math.Floor(360 / MvNumBumpDirs_ANISO.Value));
            }
            for (int i = 0; i < MvNumBumpDirs_ANISO.Value; i++)
            {
                ForceDirections.Rows[i].Cells[0].Value = i;
                ForceDirections.Rows[i].Cells[1].Value = dirs[i];
                ForceDirections.Rows[i].Cells[2].Value = 1;
            }
            SetupParamLists();
        }
        #endregion

        #region ParamList accessors
        private void SetupParamLists()
        {
            paramControls = new Dictionary<string, Control>();
            paramNames = new Dictionary<string, string>();
            paramBlocks = new Dictionary<string, string>();

            #region General
            // General stuff
            AddParamListItem("Elbow Offset", "Value", "XY Position Subsystem/elbowOffset", this.textBoxElOffset);
            AddParamListItem("Shoulder Offset", "Value", "XY Position Subsystem/shoulderOffset", this.textBoxShOffset);
            AddParamListItem("X Offset", "Value", "XY Position Subsystem/Jacobian-Cartesian Transformation/xoffset", this.textBoxXOffset);
            AddParamListItem("Y Offset", "Value", "XY Position Subsystem/Jacobian-Cartesian Transformation/yoffset", this.textBoxYOffset);
            AddParamListItem("Cursor Rotation", "Value", "XY Position Subsystem/Cursor Rotation/AngleOffset", this.angleEntryBoxCursorRotation);
            AddParamListItem("Reward Pulse", "Value", "RewardSbs/RewardTime", this.textBoxRewardPL);
            AddParamListItem("Reward Jackpot", "Value", "RewardSbs/RewardJackpot", this.textBoxRewardJackpot);
            AddParamListItem("Reward Jackpot Chance", "Value", "RewardSbs/JackpotChance", this.textBoxJackpotChance);
            AddParamListItem("Recenter Handle", "Value", "Recentering Subsystem/RecenterFlag", this.checkBoxRecenter);
            AddParamListItem("Use Tachs", "Value", "Velocity Calculation/UseTachs", this.checkBoxUseTachs);
            AddParamListItem("Use Neural Control", "Value", "Use Neural Control", this.checkBoxUseNeuralControl);
            AddParamListItem("Disable bounding box", "Value", "BoundingBox/DisableBoundingBox", this.checkBoxGDBB);

            // Load
            AddParamListItem("Visc Constant", "Gain", "Force Generator/ViscLoadSubsystem/Gain", this.textBoxVisc);
            AddParamListItem("Curl Angle", "Value", "Force Generator/visAngle", this.angleEntryBoxCurlAngle);
            AddParamListItem("Static X Force", "Value", "Force Generator/staticX", this.textBoxLoadX);
            AddParamListItem("Static Y Force", "Value", "Force Generator/staticY", this.textBoxLoadY);
            AddParamListItem("Chaotic Time Constatnt", "Value", "Force Generator/LorentzForce/Lorentz/timescale", this.textBoxTimeConst);
            AddParamListItem("Chaotic Time Constatnt1", "Value", "Force Generator/LorentzForce/Lorentz1/timescale", this.textBoxTimeConst);
            AddParamListItem("Chaotic Time Constatnt2", "Value", "Force Generator/LorentzForce/Lorentz2/timescale", this.textBoxTimeConst);
            AddParamListItem("Chaotic Time Constatnt3", "Value", "Force Generator/LorentzForce/Lorentz3/timescale", this.textBoxTimeConst);
            AddParamListItem("Chaotic Load Gain", "Gain", "Force Generator/LorentzForceGain", this.textBoxChaoticGain);
            AddParamListItem("Elastic Load Gain", "Gain", "Force Generator/ElasticLoadSubsystem/Gain", this.textBoxEG);
            AddParamListItem("Elastic Load Angle", "Value", "Force Generator/PosForceAngle", this.textBoxEA);

            // Catch load
            AddParamListItem("Visc Constant Catch", "Gain", "Catch Force Generator/ViscLoadSubsystem/Gain", this.textBoxViscCatch);
            AddParamListItem("Curl Angle Catch", "Value", "Catch Force Generator/visAngle", this.angleEntryBoxCurlAngleCatch);
            AddParamListItem("Static X Force Catch", "Value", "Catch Force Generator/staticX", this.textBoxLoadXCatch);
            AddParamListItem("Static Y Force Catch", "Value", "Catch Force Generator/staticY", this.textBoxLoadYCatch);
            AddParamListItem("Chaotic Time Constatnt Catch", "Value", "Catch Force Generator/LorentzForce/Lorentz/timescale", this.textBoxTimeConstCatch);
            AddParamListItem("Chaotic Time Constatnt1 Catch", "Value", "Catch Force Generator/LorentzForce/Lorentz1/timescale", this.textBoxTimeConstCatch);
            AddParamListItem("Chaotic Time Constatnt2 Catch", "Value", "Catch Force Generator/LorentzForce/Lorentz2/timescale", this.textBoxTimeConstCatch);
            AddParamListItem("Chaotic Time Constatnt3 Catch", "Value", "Catch Force Generator/LorentzForce/Lorentz3/timescale", this.textBoxTimeConstCatch);
            AddParamListItem("Chaotic Load Gain Catch", "Gain", "Catch Force Generator/LorentzForceGain", this.textBoxChaoticGainCatch);
            AddParamListItem("Elastic Load Gain Catch", "Gain", "Catch Force Generator/ElasticLoadSubsystem/Gain", this.textBoxEGC);
            AddParamListItem("Elastic Load Angle Catch", "Value", "Catch Force Generator/PosForceAngle", this.textBoxEAC);

            // Isometric stuff
            AddParamListItem("Isometric Mode", "Value", "XY Position Subsystem/IsometricMode", this.checkBoxIM);
            AddParamListItem("Upside Down Handle", "Value", "XY Position Subsystem/UpsideDownHandle", this.checkBoxUSDH);
            AddParamListItem("Force To Screen Gain", "Value", "XY Position Subsystem/ForceToScreenGain", this.textBoxF2SG);
            AddParamListItem("Cursor Rotation Iso", "Value", "XY Position Subsystem/Cursor Rotation1/AngleOffset", this.angleEntryBoxCursorRotation);
            AddParamListItem("Motor Control Iso", "Value", "Motor Control/IsometricMode", this.checkBoxIM);
            AddParamListItem("Offset reset level", "Value", "XY Position Subsystem/OffsetCalculation/NoiseLevel/Constant", this.textBoxORL);

            #endregion

            #region AnIsoCOBump

            AddParamListItem("COB ctr hold low ANISO", "P3", "Behavior AnIsoCOBump", CTHL_ANISO);
            AddParamListItem("COB ctr hold high ANISO", "P4", "Behavior AnIsoCOBump", CTHH_ANISO);
            AddParamListItem("COB delay hold low ANISO", "P5", "Behavior AnIsoCOBump", CDL_ANISO);
            AddParamListItem("COB delay hold high ANISO", "P6", "Behavior AnIsoCOBump", CDH_ANISO);
            AddParamListItem("COB move time ANISO", "P7", "Behavior AnIsoCOBump", MoveT_ANISO);
            AddParamListItem("COB target hold low ANISO", "P8", "Behavior AnIsoCOBump", THL_ANISO);
            AddParamListItem("COB terget hold high ANISO", "P9", "Behavior AnIsoCOBump", THH_ANISO);

            AddParamListItem("COB bump delay ANISO", "P10", "Behavior AnIsoCOBump", BD_ANISO);
            AddParamListItem("COB bump hold ANISO", "P11", "Behavior AnIsoCOBump", BH_ANISO);
            AddParamListItem("COB intertrial ANISO", "P12", "Behavior AnIsoCOBump", Intertrial_ANISO);
            AddParamListItem("COB penalty time ANISO", "P13", "Behavior AnIsoCOBump", PEN_ANISO);

            AddParamListItem("COB stim delay time ANISO", "P57", "Behavior AnIsoCOBump", StimD_ANISO);

            //target info
            AddParamListItem("COB target size ANISO", "P14", "Behavior AnIsoCOBump", TargetRadius_ANISO);
            AddParamListItem("COB target radius ANISO", "P15", "Behavior AnIsoCOBump", targDist_ANISO);
            AddParamListItem("COB target angle ANISO", "P16", "Behavior AnIsoCOBump", Angle_ANISO);
            AddParamListItem("COB target floor ANISO", "P17", "Behavior AnIsoCOBump", Target_Angle_Floor_ANISO);
            AddParamListItem("COB target ceiling ANISO", "P18", "Behavior AnIsoCOBump", Target_Angle_Ceiling_ANISO);
            AddParamListItem("COB number targets ANISO", "P19", "Behavior AnIsoCOBump", numericNumTargets_ANISO);
            AddParamListItem("COB use random targets ANISO", "P20", "Behavior AnIsoCOBump", Random_Targets_ANISO);
            //cursor info
            AddParamListItem("COB hide cursor ANISO", "P21", "Behavior AnIsoCOBump", Hide_Cursor_ANISO);
            AddParamListItem("COB hide cursor radius min ANISO", "P22", "Behavior AnIsoCOBump", Hide_Cursor_Min_ANISO);
            AddParamListItem("COB hide cursor radius max ANISO", "P23", "Behavior AnIsoCOBump", Hide_Cursor_Max_ANISO);
            //bump info
            AddParamListItem("COB catch rate ANISO", "P24", "Behavior AnIsoCOBump", CatchRate_ANISO);
            AddParamListItem("COB bi directional bumps ANISO", "P25", "Behavior AnIsoCOBump", BidirectionalBumps_ANISO);
            AddParamListItem("COB abort during bump ANISO", "P26", "Behavior AnIsoCOBump", AbortDuringBump_ANISO);
            //center hold bump params
            AddParamListItem("COB CHBump flag ANISO", "P27", "Behavior AnIsoCOBump", CTRHoldCheckbox_ANISO);
            AddParamListItem("COB CHBump rate ANISO", "P28", "Behavior AnIsoCOBump", CHBumpRate_ANISO);
            AddParamListItem("COB CHbump dur ANISO", "P29", "Behavior AnIsoCOBump", CHPeak_Duration_ANISO);
            AddParamListItem("COB CHbump ramp ANISO", "P30", "Behavior AnIsoCOBump", CHRise_Time_ANISO);
            AddParamListItem("COB CHbump mag ANISO", "P31", "Behavior AnIsoCOBump", CHAmplitude_ANISO);
            AddParamListItem("COB CHbumpdir floor ANISO", "P32", "Behavior AnIsoCOBump", CHRandBumpFloor_ANISO);
            AddParamListItem("COB CHbumpdir ceiling ANISO", "P33", "Behavior AnIsoCOBump", CHRandBumpCeil_ANISO);
            AddParamListItem("COB CHbump num dir ANISO", "P34", "Behavior AnIsoCOBump", CHNumBumpDirs_ANISO);
            //delay bump params
            AddParamListItem("COB DPBump flag ANISO", "P35", "Behavior AnIsoCOBump", DelayBump_Check_ANISO);
            AddParamListItem("COB DPBump rate ANISO", "P36", "Behavior AnIsoCOBump", DPBumpRate_ANISO);
            AddParamListItem("COB DPbump dur ANISO", "P37", "Behavior AnIsoCOBump", DPPeakDuration_ANISO);
            AddParamListItem("COB DPbump ramp ANISO", "P38", "Behavior AnIsoCOBump", DPRiseTime_ANISO);
            AddParamListItem("COB DPbump mag ANISO", "P39", "Behavior AnIsoCOBump", DPAmplitude_ANISO);
            AddParamListItem("COB DPbumpdir floor ANISO", "P40", "Behavior AnIsoCOBump", DPRandBumpFloor_ANISO);
            AddParamListItem("COB DPbumpdir ceiling ANISO", "P41", "Behavior AnIsoCOBump", DPRandBumpFloor_ANISO);
            AddParamListItem("COB DPbump num dir ANISO", "P42", "Behavior AnIsoCOBump", DPNumBumpDirs_ANISO);
            //move bump params
            AddParamListItem("COB MBump flag ANISO", "P43", "Behavior AnIsoCOBump", Move_Bump_Check_ANISO);
            AddParamListItem("COB MBump rate ANISO", "P44", "Behavior AnIsoCOBump", MBumpRate_ANISO);
            AddParamListItem("COB Mbump dur ANISO", "P45", "Behavior AnIsoCOBump", MvPeakDuration_ANISO);
            AddParamListItem("COB Mbump ramp ANISO", "P46", "Behavior AnIsoCOBump", MvRiseTime_ANISO);
            AddParamListItem("COB Mbump mag ANISO", "P47", "Behavior AnIsoCOBump", MvAmplitude_ANISO);
            AddParamListItem("COB Mbumpdir floor ANISO", "P48", "Behavior AnIsoCOBump", MvRandBumpFloor_ANISO);
            AddParamListItem("COB Mbumpdir ceiling ANISO", "P49", "Behavior AnIsoCOBump", MvRandBumpCeil_ANISO);
            AddParamListItem("COB Mbumpdir incr ANISO", "P50", "Behavior AnIsoCOBump", MvNumBumpDirs_ANISO);
            //stim info
            AddParamListItem("COB stim prob ANISO", "P51", "Behavior AnIsoCOBump", StimProb_ANISO);
            AddParamListItem("COB stim levels ANISO", "P52", "Behavior AnIsoCOBump", StimLevel_ANISO);
            AddParamListItem("COB stim during bump ANISO", "P55", "Behavior AnIsoCOBump", StimDuringBump_ANISO);
            AddParamListItem("COB stim instead of bump ANISO", "P56", "Behavior AnIsoCOBump", StimInsteadBump_ANISO);

            //extra bump parameter
            AddParamListItem("COB use random bump time ANISO", "P53", "Behavior AnIsoCOBump", RandomBumpTime_ANISO);
            AddParamListItem("COB target relative bumps ANISO", "P54", "Behavior AnIsoCOBump", Target_Relative_Bumps_ANISO);

            //idiot mode checkbox
            AddParamListItem("COB idiot mode ANISO", "P58", "Behavior AnIsoCOBump", Idiot_Mode_ANISO);

            #endregion


        }

        private void AddParamListItem(string short_name, string name, string block, Control control)
        {
            paramNames.Add(short_name, name);
            paramBlocks.Add(short_name, block);
            if (control != null) {
                paramControls.Add(short_name, control);
            }
        }

        private void AddParamListItem(string short_name, string name, string block)
        {
            AddParamListItem(short_name, name, block, null);
        }
        #endregion

        #region Status Helper Functions
        /// <summary>
        /// Updates the status label in the taskbar to the current status of the target
        /// </summary>
        private void GetStatus()
        {
            if (hasXpcTarget) {
                this.toolStripStatusLabelMdl.Text = "Model: " + target.GetAppName();
            } else {
                this.toolStripStatusLabelMdl.Text = "XPC Target link not connected";
            }
        }

        /// <summary>
        /// Updates the titlebar of the update form to include the currently loaded settings file
        /// </summary>
        private void UpdateTitlebarText(string filename)
        {
            string abridgedFilename;
            string formname = "Update Target";

            // Abridge the filename to three path components.
            string[] pathComponents = filename.Split(new char[] { Path.DirectorySeparatorChar });
            if (pathComponents.Length > 3) {
                abridgedFilename = String.Concat(
                    pathComponents[0], "\\...\\",
                    pathComponents[pathComponents.Length - 2], "\\",
                    pathComponents[pathComponents.Length - 1]);
            } else {
                abridgedFilename = filename;
            }

            this.Text = String.Concat(formname, " [", abridgedFilename, "]");
        }

        /// <summary>
        /// Updates the asterisk behind the currently loaded filename to reflect changes (or lack thereof)
        /// </summary>
        private void UpdateTitlebarFileModifiedFlag(bool hasChanges)
        {
            if (hasChanges) {
                /* search for the asterisk. If none exists, add one */
                if (this.Text.EndsWith("]") && !this.Text.EndsWith("*]")) {
                    this.Text = String.Concat(this.Text.Substring(0, this.Text.Length - 1), "*]");
                }
            } else /* (!hasChanges) */ {
                /* search for the asterisk. If it's there, remove it */
                if (this.Text.EndsWith("*]")) {
                    this.Text = String.Concat(this.Text.Substring(0, this.Text.Length - 2), "]");
                }
            }
        }
        #endregion

        #region Form Event Callbacks
        private void UpdateForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            this.Hide();
            if (e.CloseReason == CloseReason.UserClosing) {
                e.Cancel = true;
                ((Graphics)this.Owner).RestartTimer();
            }
        }

        private void UpdateForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            protocol.Term();
        }



        private void quit(object sender, EventArgs e)
        {
            this.Owner.Close();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            ComboBox cb = this.comboBoxLoad;
            string load = cb.Items[cb.SelectedIndex].ToString();

            /* Items:
             * 
             * None
             * Static
             * Viscous
             * Curl
             * Rotating Curl
             * Chaotic
             * Elastic
             */

            labelViscConst.Enabled = ((load == "Viscous") || (load == "Curl") || (load == "Rotating Curl") || (load == "Elastic"));
            textBoxVisc.Enabled = ((load == "Viscous") || (load == "Curl") || (load == "Rotating Curl") || (load == "Elastic"));

            labelCurlAngle.Enabled = (load == "Curl");
            angleEntryBoxCurlAngle.Enabled = (load == "Curl");

            labelStaticX.Enabled = load.Equals("Static");
            labelStaticY.Enabled = (load == "Static");
            textBoxLoadX.Enabled = (load == "Static");
            textBoxLoadY.Enabled = (load == "Static");

            labelChaoticGain.Enabled = (load == "Chaotic");
            textBoxChaoticGain.Enabled = (load == "Chaotic");

            labelTimeConst.Enabled = (load == "Chaotic" || load == "Rotating Curl");
            textBoxTimeConst.Enabled = (load == "Chaotic" || load == "Rotating Curl");

            widget_ValueChanged(sender, e);
        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            ComboBox cb2 = this.comboBoxLoadCatch;
            string catchLoad = cb2.Items[cb2.SelectedIndex].ToString();

            /* Items:
             * 
             * None
             * Static
             * Viscous
             * Curl
             * Rotating Curl
             * Chaotic
             */

            labelViscConstCatch.Enabled = ((catchLoad == "Viscous") || (catchLoad == "Curl") || (catchLoad == "Rotating Curl") || (catchLoad == "Elastic"));
            textBoxViscCatch.Enabled = ((catchLoad == "Viscous") || (catchLoad == "Curl") || (catchLoad == "Rotating Curl") || (catchLoad == "Elastic"));

            labelCurlAngleCatch.Enabled = (catchLoad == "Curl");
            angleEntryBoxCurlAngleCatch.Enabled = (catchLoad == "Curl");

            labelStaticXCatch.Enabled = catchLoad.Equals("Static");
            labelStaticYCatch.Enabled = (catchLoad == "Static");
            textBoxLoadXCatch.Enabled = (catchLoad == "Static");
            textBoxLoadYCatch.Enabled = (catchLoad == "Static");

            labelChaoticGainCatch.Enabled = (catchLoad == "Chaotic");
            textBoxChaoticGainCatch.Enabled = (catchLoad == "Chaotic");

            labelTimeConstCatch.Enabled = (catchLoad == "Chaotic" || catchLoad == "Rotating Curl");
            textBoxTimeConstCatch.Enabled = (catchLoad == "Chaotic" || catchLoad == "Rotating Curl");

            widget_ValueChanged(sender, e);
        }

        private void buttonclear_Click(object sender, EventArgs e)
        {
            double[] oldParam;
            Array newParam = Array.CreateInstance(typeof(double), 1);

            if (!hasXpcTarget) {
                MessageBox.Show("Not connected to XPC Target", "Not connected", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            DialogResult result = MessageBox.Show("This will reset the value of the higher target reached.\nAre you sure you want to procede?", "Clear MVC Target", MessageBoxButtons.YesNo, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2);
            if (result == DialogResult.Yes) {
                /* Get param ID for MVC_clear */
                int paramID = target.GetParamIdx("Behavior WF", "P13");
                if (paramID < 0)
                    paramID = target.GetParamIdx("Behavior MG", "P16");

                /* send the flag */
                if (paramID >= 0) {
                    oldParam = (double[])target.GetParam(paramID);
                    newParam.SetValue(oldParam[0] + 1.0, 0);
                    target.SetParam(paramID, ref newParam);
                }
            }
        }

        private void buttonWFAZ_Click(object sender, EventArgs e)
        {
            if (!hasXpcTarget) {
                MessageBox.Show("Not connected to XPC Target", "Not connected", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            double RawXValue = 0;
            double RawYValue = 0;

            // Get the signal IDs of the raw ADC value
            int XOffsetID = target.GetSignalIdx("CursorPos/PCI-6025E /p1");
            int YOffsetID = target.GetSignalIdx("CursorPos/PCI-6025E /p2");

            // Sample and average the signal value NUM_SAMPLES times
            const int NUM_SAMPLES = 5;
            for (int i = 0; i < NUM_SAMPLES; i++) {
                RawXValue += target.GetSignal(XOffsetID) / NUM_SAMPLES;
                RawYValue += target.GetSignal(YOffsetID) / NUM_SAMPLES;
                System.Threading.Thread.Sleep(1); // sleep 1 ms for next xpc cycle
            }

            // Update text boxes

            widget_ValueChanged(sender, e);
        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            // revert the changes
            BehaviorParameters2Form(this.currentBP);
            this.formWasModified = false;
            UpdateTitlebarFileModifiedFlag(this.formWasModified || this.bpWasModified);
            this.Close();
        }

        private void okButton_Click(object sender, EventArgs e)
        {
            try {
                Form2Target();
                this.currentBP = Form2BehaviorParameters();
                this.bpWasModified = this.bpWasModified || this.formWasModified;
                UpdateTitlebarFileModifiedFlag(this.bpWasModified);
                this.Close();
            } catch (InvalidParameterException) {
                MessageBox.Show("One or more parameters are invalid. Model not updated.", "Invalid Entry", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void buttonRefresh_Click(object sender, EventArgs e)
        {
            Target2Form();
            GetStatus();
        }

        private void tabPageGen_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            MessageBox.Show(System.Reflection.Assembly.GetExecutingAssembly().GetName().Version.ToString());
        }

        private void textBox_TextChanged(object sender, EventArgs e)
        {
            double tmp;

            if (sender.GetType().Name == "TextBox") {
                TextBox tb = (TextBox)sender;
                if (Double.TryParse(tb.Text, out tmp)) {
                    tb.BackColor = SystemColors.Window;
                }
            }
            widget_ValueChanged(sender, e);
        }

        private void widget_ValueChanged(object sender, EventArgs e)
        {
            this.formWasModified = true;
            UpdateTitlebarFileModifiedFlag(true);
        }

        private void table_CellValueChanged(object sender, DataGridViewCellEventArgs e)
        {
            widget_ValueChanged(sender, null);
        }


        private void UpdateForm_Shown(object sender, EventArgs e)
        {
            foreach (CursorDef cd in ((Graphics)this.Owner).CursorDefs) {
                this.comboBoxCursor.Items.Add(cd.Name);
            }

        }

        private void UpdateForm_DragDrop(object sender, DragEventArgs e)
        {
            string[] filenames = (string[])e.Data.GetData(DataFormats.FileDrop);

            BehaviorParameters bp;
            TextReader reader = new StreamReader(filenames[0]);
            XmlSerializer s = new XmlSerializer(typeof(BehaviorParameters));

            try {
                bp = (BehaviorParameters)s.Deserialize(reader);
                // Check version
                if (new Version(bp.Version) < System.Reflection.Assembly.GetExecutingAssembly().GetName().Version) {
                    if (MessageBox.Show("This file was created with an earlier version of the behavior control application.  Some fields may not update correctly.  Do you want to continue loading?", "File out of date", MessageBoxButtons.OKCancel, MessageBoxIcon.Question) == DialogResult.Cancel) {
                        reader.Close();
                        return;
                    }
                }

                BehaviorParameters2Form(bp);
                filename = filenames[0]; ;

            } catch (Exception) {
                MessageBox.Show("The file does not appear to be in the proper format", "Error loading file", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            } finally {
                reader.Close();
            }
        }

        private void UpdateForm_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop, false)) {
                string[] filenames = (string[])e.Data.GetData(DataFormats.FileDrop);
                if (String.Compare(".xml", filenames[0].Substring(filenames[0].Length - 4), true) == 0) {
                    e.Effect = DragDropEffects.All;
                } else {
                    e.Effect = DragDropEffects.None;
                }
            }
        }

        #endregion

        #region MenuCallbacks
        private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            fileSaveAs();
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (filename != "") {
                fileSave();
            } else {
                fileSaveAs();
            }
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            BehaviorParameters bp;
            TextReader reader;
            XmlSerializer s;

            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "XML Parameter files|*.xml";
            ofd.Multiselect = false;
            ofd.InitialDirectory = RegistryHelper.BPDir;

            if (ofd.ShowDialog() == DialogResult.OK) {
                reader = new StreamReader(ofd.FileName);
                s = new XmlSerializer(typeof(BehaviorParameters));
                try {
                    bp = (BehaviorParameters)s.Deserialize(reader);
                    // Check version
                    if (new Version(bp.Version) < System.Reflection.Assembly.GetExecutingAssembly().GetName().Version) {
                        if (MessageBox.Show("This file was created with an earlier version of the behavior control application.  Some fields may not update correctly.  Do you want to continue loading?", "File out of date", MessageBoxButtons.OKCancel, MessageBoxIcon.Question) == DialogResult.Cancel) {
                            reader.Close();
                            return;
                        }
                    }

                    BehaviorParameters2Form(bp);
                    filename = ofd.FileName;

                    // Save file path
                    RegistryHelper.BPDir = Path.GetDirectoryName(ofd.FileName);

                    UpdateTitlebarText(filename);
                    this.currentBP = bp;
                    this.formWasModified = false;
                    this.bpWasModified = false;

                } catch (Exception ex) {
                    MessageBox.Show("The file does not appear to be in the proper format. The parameters may have been partially updated." + ex.Message, "Error loading file", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    this.formWasModified = true;
                    UpdateTitlebarFileModifiedFlag(true);
                } finally {
                    reader.Close();
                }
            }
        }

        private int updateLab()
        {
            // Could not find registry key, ask user which lab we are in
            WhichLabForm wlf = new WhichLabForm();
            wlf.ShowDialog();

            return wlf.Lab;
        }

        private void setLabToolStripMenuItem_Click(object sender, EventArgs e)
        {
            updateLab();
        }

        private void loadModelToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string file, path;

            // Figure out which lab we are running in
            int lab;
            try {
                lab = RegistryHelper.Lab;
            } catch (RegistryHelper.RegistryHelperException) {
                lab = updateLab();
            }

            // Check if we have a connection to the target
            if (!hasXpcTarget) {
                MessageBox.Show("Not connected to XPC Target", "Not connected", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            // Load the model onto the target
            OpenFileDialog ofd = new OpenFileDialog();

            ofd.Filter = "XPC model files|*.dlm";
            ofd.Multiselect = false;
            ofd.InitialDirectory = RegistryHelper.MdlDir;

            if (ofd.ShowDialog() == DialogResult.OK) {
                RegistryHelper.MdlDir = Path.GetDirectoryName(ofd.FileName);
                path = Path.GetDirectoryName(ofd.FileName);
                file = Path.GetFileNameWithoutExtension(ofd.FileName);

                target.LoadApp(path, file);
                target.StartApp();
            }

            // Update lab specific parameters
            LabList ll = LabList.FromXML();
            LabSpecification ls = ll.GetLabSpecification(lab);
            ls.SendToTarget(target);
            // Update the status bar
            GetStatus();            
        }

        private void resetCountersToolStripMenuItem_Click(object sender, EventArgs e)
        {
            double[] oldParam;
            Array newParam = Array.CreateInstance(typeof(double), 1);

            if (!hasXpcTarget) {
                MessageBox.Show("Not connected to XPC Target", "Not connected", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            DialogResult result = MessageBox.Show("This will reset the counters on the target.\nAre you sure you want to procede?", "Reset Target", MessageBoxButtons.YesNo, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2);
            if (result == DialogResult.Yes) {
                /* Get param ID for master reset parameter */
                int paramID = target.GetParamIdx("Behavior CO", "P17");
                if (paramID < 0)
                    paramID = target.GetParamIdx("Behavior RW", "P18");
                if (paramID < 0)
                    paramID = target.GetParamIdx("Behavior BS", "P20");
                if (paramID < 0)
                    paramID = target.GetParamIdx("Behavior MG", "P13");
                if (paramID < 0)
                    paramID = target.GetParamIdx("Behavior FC", "P14");
                if (paramID < 0)
                    paramID = target.GetParamIdx("Behavior WF", "P14");
                if (paramID < 0)
                    paramID = target.GetParamIdx("Behavior BD", "P8");
                if (paramID < 0)
                    paramID = target.GetParamIdx("Behavior BC", "P1");
                if (paramID < 0)
                    paramID = target.GetParamIdx("Behavior VS", "P15");
                if (paramID < 0)
                    paramID = target.GetParamIdx("Behavior BF", "P1");
                if (paramID < 0)
                    paramID = target.GetParamIdx("Behavior 2AFC", "P1");
                if (paramID < 0)
                    paramID = target.GetParamIdx("Behavior Un", "P22");
                if (paramID < 0)
                    paramID = target.GetParamIdx("Behavior 2BC", "P1");
                if (paramID < 0)
                    paramID = target.GetParamIdx("Behavior AT", "P1");
                if (paramID < 0)
                    paramID = target.GetParamIdx("Behavior UF", "P1");
                if (paramID < 0)
                    paramID = target.GetParamIdx("Behavior DCO", "P1");
                if (paramID < 0)
                    paramID = target.GetParamIdx("Behavior UR", "P1");
                if (paramID < 0)
                    paramID = target.GetParamIdx("Behavior RP", "P1");
                if (paramID < 0)
                    paramID = target.GetParamIdx("Behavior Ring Reporting", "P1");

                /* send the flag */
                if (paramID >= 0) {
                    oldParam = (double[])target.GetParam(paramID);
                    newParam.SetValue(oldParam[0] + 1.0, 0);
                    target.SetParam(paramID, ref newParam);
                }
            }
        }

        private void fileSaveAs()
        {
            SaveFileDialog sfd = new SaveFileDialog();
            sfd.InitialDirectory = RegistryHelper.BPDir;
            sfd.Filter = "XML Parameter files|*.xml";

            try {
                if (sfd.ShowDialog() == DialogResult.OK) {
                    RegistryHelper.BPDir = Path.GetDirectoryName(sfd.FileName);

                    filename = sfd.FileName;
                    fileSave();

                    UpdateTitlebarText(filename);
                }
            } catch (InvalidParameterException) {
                MessageBox.Show("One or more parameters are invalid.  File has not been saved.", "Invalid Entry", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        public void fileSave()
        {
            BehaviorParameters bp;
            XmlSerializer s;
            TextWriter writer = new StreamWriter(filename);

            try {
                bp = Form2BehaviorParameters();
                s = new XmlSerializer(typeof(BehaviorParameters));
                s.Serialize(writer, bp);

                UpdateTitlebarText(filename);
                this.currentBP = bp;
                this.formWasModified = false;
                this.bpWasModified = false;
            } catch (InvalidParameterException) {
                MessageBox.Show("One or more parameters are invalid. File not saved.", "Invalid Entry", MessageBoxButtons.OK, MessageBoxIcon.Error);
            } catch (IOException) {
                MessageBox.Show("Could not write file", "File Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            } finally {
                writer.Close();
            }
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //string version = Assembly.GetExecutingAssembly().GetName().Version.ToString();
            new GraphicsAboutBox().Show();
        }

        private void boxToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Turns the Box on or Off
            Graphics owner = (Graphics)this.Owner;

            if (boxToolStripMenuItem.Checked) {
                owner.DrawBox = false;
                boxToolStripMenuItem.Checked = false;
            } else {
                owner.DrawBox = true;
                boxToolStripMenuItem.Checked = true;
            }
        }

        private void boxSettingsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Graphics owner = (Graphics)this.Owner;

            BoxConfig bc = new BoxConfig();
            bc.Box = owner.Box;
            bc.ShowDialog();
            if (bc.DialogResult == DialogResult.OK) {
                owner.Box = bc.Box;
            }
        }

        private void soundThemeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            theme1ToolStripMenuItem.Checked = false;
            theme2ToolStripMenuItem.Checked = false;
            theme3ToolStripMenuItem.Checked = false;
            theme4ToolStripMenuItem.Checked = false;

            SoundPlayer.SoundTheme theme;

            if (sender.Equals(theme2ToolStripMenuItem)) {
                theme = SoundPlayer.SoundTheme.Theme2;
                theme2ToolStripMenuItem.Checked = true;
            } else if (sender.Equals(theme3ToolStripMenuItem)) {
                theme = SoundPlayer.SoundTheme.Theme3;
                theme3ToolStripMenuItem.Checked = true;
            } else if (sender.Equals(theme4ToolStripMenuItem)){
                theme = SoundPlayer.SoundTheme.Theme4;
                theme4ToolStripMenuItem.Checked = true;
            } else {
                theme = SoundPlayer.SoundTheme.Theme1;
                theme1ToolStripMenuItem.Checked = true;
            }

            Graphics owner = (Graphics)this.Owner;
            owner.SoundTheme = theme;
        }

        private void keepGraphicsRunningToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Graphics owner = (Graphics)this.Owner;
            owner.KeepGraphicsRunning = !owner.KeepGraphicsRunning;

            this.keepGraphicsRunningToolStripMenuItem.Checked = owner.KeepGraphicsRunning;
        }
        #endregion

        #region updateParameterFunctions
        /*
         * These methods move the parameters around between the target, 
         * the form, and the backing structure 
         */
        private void Target2Form()
        {
            float total = paramNames.Keys.Count + 7;
            float done = 0f;
            int paramID;
            double[] param;
            double catch_pct;
            double rot_visc;
            double visc_angle;
            double catch_rot_visc;
            double catch_visc_angle;

            if (!hasXpcTarget) return;

            // Two parameters (local to host) are trivial
            Graphics owner = (Graphics)this.Owner;
            this.textBoxScreenWidth.Text = owner.ScreenScale.ToString();
            this.comboBoxCursor.SelectedIndex = owner.CursorDefs.IndexOf(owner.ActiveCursor);
            this.textBoxVerticalDisplacement.Text = owner.VerticalDisplacement.ToString();

            // batched parameters
            foreach (string key in paramNames.Keys) {
                paramID = target.GetParamIdx(paramBlocks[key], paramNames[key]);

                // If we can't find the parameter, ignore it.
                // Otherwise update the control
                if (paramID != -1) {
                    param = (double[])target.GetParam(paramID);

                    if (paramControls[key].GetType() == typeof(TextBox)) {
                        TextBox tb = (TextBox)paramControls[key];
                        tb.Text = param[0].ToString();
                    } else if (paramControls[key].GetType() == typeof(NumericUpDown)) {
                        NumericUpDown nud = (NumericUpDown)paramControls[key];
                        nud.Value = (int)param[0];
                    } else if (paramControls[key].GetType() == typeof(CheckBox)) {
                        CheckBox cb = (CheckBox)paramControls[key];
                        cb.Checked = (param[0] > 0);
                    } else if (paramControls[key].GetType() == typeof(AngleEntryBox)) {
                        AngleEntryBox ab = (AngleEntryBox)paramControls[key];
                        ab.Value = Double.Parse(param[0].ToString());
                    }
                    else if (paramControls[key].GetType() == typeof(RadioButton)) {
                        RadioButton rb = (RadioButton)paramControls[key];
                        rb.Checked = (param[0] > 0);
                    }
                }

                done += 1f;
                this.toolStripProgressBar1.Value = (int)(100f * done / total);
            }

            
            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            // Load type
            paramID = target.GetParamIdx("Force Generator/Load", "Value");
            if (paramID >= 0) {
                param = (double[])target.GetParam(paramID);
                switch ((LoadParam)param[0]) {
                    case LoadParam.None:
                        this.comboBoxLoad.SelectedIndex = (int)LoadType.None;
                        break;
                    case LoadParam.Static:
                        this.comboBoxLoad.SelectedIndex = (int)LoadType.Static;
                        break;
                    case LoadParam.Chaotic:
                        this.comboBoxLoad.SelectedIndex = (int)LoadType.Chaotic;
                        break;
                    case LoadParam.Elastic:
                        this.comboBoxLoad.SelectedIndex = (int)LoadType.Elastic;
                        break;
                    default:
                        paramID = target.GetParamIdx("Value", "Force Generator/DynamicAngle");
                        if (paramID >= 0) {
                            param = (double[])target.GetParam(paramID);
                            rot_visc = param[0];
                        } else {
                            rot_visc = 0;
                        }
                        try {
                            visc_angle = Double.Parse(this.angleEntryBoxCurlAngle.Text);
                        } catch (FormatException) {
                            visc_angle = 0.0;
                        }
                        if (rot_visc > 0) {
                            this.comboBoxLoad.SelectedIndex = (int)LoadType.RotatingCurl;
                        } else if (visc_angle != 0) {
                            this.comboBoxLoad.SelectedIndex = (int)LoadType.Curl;
                        } else {
                            this.comboBoxLoad.SelectedIndex = (int)LoadType.Viscous;
                        }
                        break;
                }
            }
            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            // Catch load type
            paramID = target.GetParamIdx("Catch Force Generator/Load", "Value");
            if (paramID >= 0) {
                param = (double[])target.GetParam(paramID);
                switch ((LoadParam)param[0]) {
                    case LoadParam.None:
                        this.comboBoxLoadCatch.SelectedIndex = (int)LoadType.None;
                        break;
                    case LoadParam.Static:
                        this.comboBoxLoadCatch.SelectedIndex = (int)LoadType.Static;
                        break;
                    case LoadParam.Chaotic:
                        this.comboBoxLoadCatch.SelectedIndex = (int)LoadType.Chaotic;
                        break;
                    case LoadParam.Elastic:
                        this.comboBoxLoadCatch.SelectedIndex = (int)LoadType.Elastic;
                        break;
                    default:
                        paramID = target.GetParamIdx("Value", "Catch Force Generator/DynamicAngle");
                        if (paramID >= 0) {
                            param = (double[])target.GetParam(paramID);
                            catch_rot_visc = param[0];
                        } else {
                            catch_rot_visc = 0;
                        }
                        try {
                            catch_visc_angle = Double.Parse(this.angleEntryBoxCurlAngleCatch.Text);
                        } catch (FormatException) {
                            catch_visc_angle = 0.0;
                        }
                        if (catch_rot_visc > 0) {
                            this.comboBoxLoadCatch.SelectedIndex = (int)LoadType.RotatingCurl;
                        } else if (catch_visc_angle != 0) {
                            this.comboBoxLoadCatch.SelectedIndex = (int)LoadType.Curl;
                        } else {
                            this.comboBoxLoadCatch.SelectedIndex = (int)LoadType.Viscous;
                        }
                        break;
                }
            }
            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            ForceDirections.Rows.Clear();
            ForceDirections.Rows.Add((int)MvNumBumpDirs_ANISO.Value);
            int[] dirs = new int[(int)MvNumBumpDirs_ANISO.Value];

            for (int i = 0; i < MvNumBumpDirs_ANISO.Value; i++)
            {
                dirs[i] = (int)(i * Math.Floor(360 / MvNumBumpDirs_ANISO.Value));
            }
            for (int i = 0; i < MvNumBumpDirs_ANISO.Value; i++)
            {
                ForceDirections.Rows[i].Cells[0].Value = i;
                ForceDirections.Rows[i].Cells[1].Value = dirs[i];
                ForceDirections.Rows[i].Cells[2].Value = 1;
            }
            paramID = target.GetParamIdx("BumpForceTable", "Table");
            if (paramID != -1)
            {
                int[] dims = (int[])target.GetParamDims(paramID);
                int numRows = (int)dims[0];
                int numCols = (int)dims[1];

                param = (double[])target.GetParam(paramID);
                for (int row = 0; row < numRows - 1; row++)
                {
                    for (int col = 0; col < numCols; col++)
                    {
                        double d = param[col * numRows + row];
                        ForceDirections.Rows[col].Cells[row + 1].Value = d.ToString();
                    }
                        
                }
            }
            
            


            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);


            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);


            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);


            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

        }

        private BehaviorParameters Form2BehaviorParameters()
        {
            // Init
            double paramValue;
            bool error = false;
            BehaviorParameters bp = new BehaviorParameters();

            // Dictionary params
            Dictionary<String, double> d = new Dictionary<string, double>();
            foreach (string key in paramNames.Keys) {

                if (paramControls[key].GetType() == typeof(TextBox)) {
                    TextBox tb = (TextBox)paramControls[key];
                    try {
                        paramValue = Double.Parse(tb.Text);
                    } catch (FormatException) {
                        paramValue = 0;
                        error = true;
                        tb.BackColor = Color.Crimson;
                    }
                } else if (paramControls[key].GetType() == typeof(NumericUpDown)) {
                    NumericUpDown nud = (NumericUpDown)paramControls[key];
                    paramValue = (double)nud.Value;
                } else if (paramControls[key].GetType() == typeof(CheckBox)) {
                    CheckBox cb = (CheckBox)paramControls[key];
                    paramValue = (cb.Checked ? 1.0 : 0.0);
                } else if (paramControls[key].GetType() == typeof(AngleEntryBox)) {
                    AngleEntryBox ab = (AngleEntryBox)paramControls[key];
                    paramValue = ab.Value;
                } else if (paramControls[key].GetType() == typeof(RadioButton)) {
                    RadioButton rb = (RadioButton)paramControls[key];
                    paramValue = (rb.Checked ? 1.0 : 0.0);
                } else {
                    paramValue = 0;
                }

                d.Add(key, paramValue);
            }

            bp.Parameters = d;


            // Anisotropic Bumps
            for (int i = 0; i < ForceDirections.Rows.Count; i++) 
            {
                DataGridViewCellCollection cells = ForceDirections.Rows[i].Cells;
                AnIsoForces anIso = new AnIsoForces();
                anIso.number = Int16.Parse(cells[0].Value.ToString());
                anIso.dir = Int16.Parse(cells[1].Value.ToString());
                anIso.force = Double.Parse(cells[2].Value.ToString());
                bp.aniso[i] = anIso;

            }
            // GlyphSet
            // Host Parameters
            try {
                bp.ScreenWidth = Double.Parse(this.textBoxScreenWidth.Text);
            } catch (FormatException) {
                this.textBoxScreenWidth.BackColor = Color.Crimson;
                error = true;
            }

            try {
                bp.VerticalDisplacement = float.Parse(this.textBoxVerticalDisplacement.Text);
            } catch (FormatException) {
                this.textBoxVerticalDisplacement.BackColor = Color.Crimson;
                error = true;
            }

            bp.Cursor = this.comboBoxCursor.SelectedIndex;

            bp.SoundTheme = ((Graphics)this.Owner).SoundTheme;
            bp.GoToneVolume = Int32.Parse(this.textBoxGoToneVolume.Text);

            if (error) throw new InvalidParameterException();
            return bp;
        }

        private void BehaviorParameters2Form(BehaviorParameters bp)
        {
            // Fixed params
            this.comboBoxLoad.SelectedIndex = (int)bp.Load;
            this.comboBoxLoadCatch.SelectedIndex = (int)bp.LoadCatch;

            // Host Parameters
            this.textBoxScreenWidth.Text = bp.ScreenWidth.ToString();
            this.textBoxVerticalDisplacement.Text = bp.VerticalDisplacement.ToString();
            this.comboBoxCursor.SelectedIndex = bp.Cursor;
            
            // Dictionary params
            foreach (string key in bp.Parameters.Keys) {
                try {
                    if (paramControls[key].GetType() == typeof(TextBox)) {
                        TextBox tb = (TextBox)paramControls[key];
                        tb.Text = bp.Parameters[key].ToString();
                    } else if (paramControls[key].GetType() == typeof(NumericUpDown)) {
                        NumericUpDown nud = (NumericUpDown)paramControls[key];
                        nud.Value = Convert.ToDecimal(Convert.ToInt32(bp.Parameters[key]));
                    } else if (paramControls[key].GetType() == typeof(CheckBox)) {
                        CheckBox cb = (CheckBox)paramControls[key];
                        cb.Checked = (bp.Parameters[key] > 0);
                    } else if (paramControls[key].GetType() == typeof(AngleEntryBox)) {
                        AngleEntryBox ab = (AngleEntryBox)paramControls[key];
                        ab.Value = bp.Parameters[key];
                    } else if (paramControls[key].GetType() == typeof(RadioButton)) {
                        RadioButton rb = (RadioButton)paramControls[key];
                        rb.Checked = (bp.Parameters[key] > 0);
                    }
                } catch (KeyNotFoundException) {
                }
            }

            for (int i = 0; i < ForceDirections.RowCount; i++)
            {
                DataGridViewCellCollection cells = ForceDirections.Rows[i].Cells;
                AnIsoForces aif = bp.AnIsotropicForces[i];
                cells[1].Value = aif.getSetNum.ToString();
                cells[2].Value = aif.getSetDir.ToString();
                cells[3].Value = aif.getSetForce.ToString();
            }
            /* Sound theme menu item selection */
            if (!Enum.IsDefined(typeof(SoundPlayer.SoundTheme), bp.SoundTheme))
                bp.SoundTheme = SoundPlayer.SoundTheme.Theme1;
            theme1ToolStripMenuItem.Checked = (bp.SoundTheme == SoundPlayer.SoundTheme.Theme1);
            theme2ToolStripMenuItem.Checked = (bp.SoundTheme == SoundPlayer.SoundTheme.Theme2);
            theme3ToolStripMenuItem.Checked = (bp.SoundTheme == SoundPlayer.SoundTheme.Theme3);
            ((Graphics)this.Owner).SoundTheme = bp.SoundTheme;
            this.textBoxGoToneVolume.Text = bp.GoToneVolume.ToString();
        }

        private void BehaviorParameters2Target(BehaviorParameters bp)
        {
            float total = paramNames.Keys.Count + 7;
            float done = 0f;
            int paramID;
            Array param = Array.CreateInstance(typeof(double), 1);

            /* 
             * Host params
             */
            Graphics owner = (Graphics)this.Owner;
            owner.ScreenScale = (float)bp.ScreenWidth;
            owner.VerticalDisplacement = bp.VerticalDisplacement;
            owner.SetCursor(this.comboBoxCursor.SelectedIndex);
            owner.SoundPlayer.GoToneVolume = bp.GoToneVolume;

            paramID = target.GetParamIdx("Behavior VS", "P4");
            if (paramID >= 0) {
                param.SetValue((double)((Graphics)this.Owner).ActiveGlyphDef.NumGlyphs, 0);
                target.SetParam(paramID, ref param);
            }

            // Stop executing here if we don't have a connection to the target
            if (!hasXpcTarget) return;

            /*
             * Fixed params
             */

            // Bump / Catch
            paramID = target.GetParamIdx("Behavior CO", "P13");
            if (paramID >= 0) {
                if (bp.CenterOutMode == CenterOutMode.Bump) {
                    param.SetValue((int)CenterOutMode.Bump, 0);
                } else {
                    param.SetValue((int)CenterOutMode.Catch, 0);
                }
                target.SetParam(paramID, ref param);
            }
            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            // Load type
            paramID = target.GetParamIdx("Force Generator/Load", "Value");
            if (paramID >= 0) {
                switch (bp.Load) {
                    case LoadType.None:
                        param.SetValue((double)LoadParam.None, 0);
                        break;
                    case LoadType.Static:
                        param.SetValue((double)LoadParam.Static, 0);
                        break;
                    case LoadType.Viscous:
                    case LoadType.Curl:
                    case LoadType.RotatingCurl:
                        param.SetValue((double)LoadParam.Viscous, 0);
                        break;
                    case LoadType.Chaotic:
                        param.SetValue((double)LoadParam.Chaotic, 0);
                        break;
                    case LoadType.Elastic:
                        param.SetValue((double)LoadParam.Elastic, 0);
                        break;
                    default:
                        break;
                }
                target.SetParam(paramID, ref param);
            }
            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            // Catch Load type
            paramID = target.GetParamIdx("Catch Force Generator/Load", "Value");
            if (paramID >= 0) {
                switch (bp.LoadCatch) {
                    case LoadType.None:
                        param.SetValue((double)LoadParam.None, 0);
                        break;
                    case LoadType.Static:
                        param.SetValue((double)LoadParam.Static, 0);
                        break;
                    case LoadType.Viscous:
                    case LoadType.Curl:
                    case LoadType.RotatingCurl:
                        param.SetValue((double)LoadParam.Viscous, 0);
                        break;
                    case LoadType.Chaotic:
                        param.SetValue((double)LoadParam.Chaotic, 0);
                        break;
                    case LoadType.Elastic:
                        param.SetValue((double)LoadParam.Elastic, 0);
                        break;
                    default:
                        break;
                }
                target.SetParam(paramID, ref param);
            }
            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            paramID = target.GetParamIdx("Behavior BD", "P9");
            if (paramID > 0)
            {
                param.SetValue((double)bp.BD_Catch_Block, 0);
                target.SetParam(paramID, ref param);

            }

            /*
             * Dictionary params
             */
            foreach (string key in bp.Parameters.Keys) {
                try {
                    paramID = target.GetParamIdx(paramBlocks[key], paramNames[key]);
                    if (paramID >= 0) {
                        param.SetValue(bp.Parameters[key], 0);
                        target.SetParam(paramID, ref param);
                    }
                } catch (IndexOutOfRangeException) {
                }
                done += 1;
                this.toolStripProgressBar1.Value = (int)(100f * done / total);
            }



            /*
             * MG Targets 
             */
            paramID = target.GetParamIdx("TargetTable", "Table");
            if (paramID >= 0) {
                Array mgTargets = Array.CreateInstance(typeof(double), 80);

                for (int i = 0; i < bp.MGTargets.Count; i++) {
                    mgTargets.SetValue(bp.MGTargets[i].TgtYPos, 5 * i);
                    mgTargets.SetValue(bp.MGTargets[i].TgtHeight, 5 * i + 1);
                    mgTargets.SetValue(bp.MGTargets[i].TgtXPos, 5 * i + 2);
                    mgTargets.SetValue(bp.MGTargets[i].TgtWidth, 5 * i + 3);
                    mgTargets.SetValue(bp.MGTargets[i].yVar_enable, 5 * i + 4);
                }
                target.SetParam(paramID, ref mgTargets);

            }

            done += 1;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);
            /*
             * Anisotropic bumps and forces
             */
            paramID = target.GetParamIdx("BumpForceTable", "Table");
            if (paramID >= 0)
            {
                Array forceDirs = Array.CreateInstance(typeof(double), 48);
                for (int i = 0; i < bp.AnIsotropicForces.Count; i++)
                {
                    forceDirs.SetValue(bp.AnIsotropicForces[i].getSetNum, 3 * i);
                    forceDirs.SetValue(bp.AnIsotropicForces[i].getSetDir, 3 * i + 1);
                    forceDirs.SetValue(bp.AnIsotropicForces[i].getSetForce, 3 * i + 2);
                }
                target.SetParam(paramID, ref forceDirs);
            }
            /*
             * MG Gains
             */
            paramID = target.GetParamIdx("CursorPos/GadgetGain", "Table");
            if (paramID >= 0)
            {
                Array mgGains = Array.CreateInstance(typeof(double), 4);
                mgGains=bp.MGGains;
                target.SetParam(paramID, ref mgGains);
            }

            /*
            * WF Targets 
            */
            paramID = target.GetParamIdx("WFTargetTable", "Table");
            if (paramID >= 0) {
                Array wfTargets = Array.CreateInstance(typeof(double), 96);

                for (int i = 0; i < bp.MGTargets.Count; i++) {
                    wfTargets.SetValue(bp.WFTargets[i].TgtYPos, 6 * i);
                    wfTargets.SetValue(bp.WFTargets[i].TgtHeight, 6 * i + 1);
                    wfTargets.SetValue(bp.WFTargets[i].TgtXPos, 6 * i + 2);
                    wfTargets.SetValue(bp.WFTargets[i].TgtWidth, 6 * i + 3);
                    wfTargets.SetValue(bp.WFTargets[i].xVar_enable, 6 * i + 4);
                    wfTargets.SetValue(bp.WFTargets[i].yVar_enable, 6 * i + 5);
                }
                target.SetParam(paramID, ref wfTargets);
            }

            /* WF master update */
            paramID = target.GetParamIdx("Behavior WF", "P19");
            if (paramID < 0) target.GetParamIdx("Behavior BC", "P15");
            if (paramID >= 0) {
                double[] oldParam;
                Array newParam = Array.CreateInstance(typeof(double), 1);
                oldParam = (double[])target.GetParam(paramID);
                newParam.SetValue(oldParam[0] + 1.0, 0);
                target.SetParam(paramID, ref newParam);
            }

            done += 1;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            /* Bump choice stims */
            paramID = target.GetParamIdx("BCStimTable", "Table");
            if (paramID >= 0)
            {
                Array bcStims = Array.CreateInstance(typeof(double), 32);
                for (int i = 0; i < bp.BCStims.Count; i++)
                {
                    bcStims.SetValue(bp.BCStims[i].StimCodeVar, 2 * i);
                    bcStims.SetValue(bp.BCStims[i].PDVar, 2 * i + 1);
                }
                target.SetParam(paramID, ref bcStims);
            }

            done += 1;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            /* Bump follow stims */
            paramID = target.GetParamIdx("BFStimTable", "Table");
            if (paramID >= 0) {
                Array bfStims = Array.CreateInstance(typeof(double), 32);
                for (int i = 0; i < bp.BFStims.Count; i++) {
                    bfStims.SetValue(bp.BFStims[i].StimCodeVar, 2 * i);
                    bfStims.SetValue(bp.BFStims[i].PDVar, 2 * i + 1);
                }
                target.SetParam(paramID, ref bfStims);
            }

            done += 1;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);


        }

        private void Form2Target()
        {
            BehaviorParameters2Target(Form2BehaviorParameters());
        }
        #endregion

        public Boolean HasUnsavedModifications
        {
            get { return this.formWasModified || this.bpWasModified; }
        }

        public string Filename
        {
            get { return this.filename; }
        }

        public class InvalidParameterException : Exception
        {
            string p;
            public InvalidParameterException(string parameter)
            {
                p = parameter;
            }

            public InvalidParameterException()
            {
                p = "";
            }

            public string ParameterKey
            {
                get { return p; }
            }
        }


        private void groupBox118_Enter(object sender, EventArgs e)
        {

        }

        private void textBox116_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox115_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox118_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox117_TextChanged(object sender, EventArgs e)
        {

        }

        private void groupBox117_Enter(object sender, EventArgs e)
        {

        }

        private void textBox114_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox113_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox122_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox121_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox120_TextChanged(object sender, EventArgs e)
        {

        }

        private void tabPage9_Click(object sender, EventArgs e)
        {

        }

        private void textBox89_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox86_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox88_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox87_TextChanged(object sender, EventArgs e)
        {

        }

        private void checkBox14_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox13_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox25_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void textBox127_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox126_TextChanged(object sender, EventArgs e)
        {

        }

        private void checkBox16_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox15_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void textBox91_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox106_TextChanged(object sender, EventArgs e)
        {

        }

        private void checkBox20_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox19_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox18_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void groupBox116_Enter(object sender, EventArgs e)
        {

        }

        private void checkBox23_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox22_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox21_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void textBox95_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox111_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox107_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox108_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox105_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox103_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox101_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox104_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox102_TextChanged(object sender, EventArgs e)
        {

        }

        private void numericUpDown6_ValueChanged(object sender, EventArgs e)
        {

        }

        private void textBox98_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox96_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox99_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox97_TextChanged(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void groupBox119_Enter(object sender, EventArgs e)
        {

        }

        private void UnstableField_Click(object sender, EventArgs e)
        {

        }

        private void groupBoxDCOT_Enter(object sender, EventArgs e)
        {

        }


    }

}