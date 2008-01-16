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

namespace DXCheck
{
    public partial class UpdateForm : Form
    {
        private xPCTarget target;
        private xPCProtocol protocol;
        private bool hasXpcTarget = false;
        private Dictionary<string, string> paramNames;
        private Dictionary<string, string> paramBlocks;
        private Dictionary<string, TextBox> paramTextBoxes;

        // Last BehaviorParameters file written or loaded
        private string filename;

        #region Constructor
        public UpdateForm()
        {
            protocol = new xPCProtocol();
            target = new xPCTarget();

            if (protocol.Init() < 0) {
                MessageBox.Show("Could not load API.\nMake sure xpcapi.dll is in the path.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            } else {
                /* initilize protocol */
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
                    MessageBox.Show("Xpc target not responding: " + protocol.GetxPCErrorMsg(), "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                    return;
                }

                hasXpcTarget = true;
            }

            if (!hasXpcTarget) {
                this.loadModelToolStripMenuItem.Enabled = false;
                this.buttonRefresh.Enabled = false;
            }

            filename = "";

            InitializeComponent();
            SetupParamLists();
        }
        #endregion

        #region ParamList accessors
        private void SetupParamLists()
        {
            paramTextBoxes = new Dictionary<string,TextBox>();
            paramNames = new Dictionary<string,string>();
            paramBlocks = new Dictionary<string,string>();

            // General stuff
            AddParamListItem("Elbow Offset", "Value", "XY Position Subsystem/elbowOffset", this.textBoxElOffset);
            AddParamListItem("Shoulder Offset", "Value", "XY Position Subsystem/shoulderOffset", this.textBoxShOffset);
            AddParamListItem("X Offset", "Value", "XY Position Subsystem/Jacobian-Cartesian Transformation/xoffset", this.textBoxXOffset);
            AddParamListItem("Y Offset", "Value", "XY Position Subsystem/Jacobian-Cartesian Transformation/yoffset", this.textBoxYOffset);
            AddParamListItem("Cursor Rotation", "Value", "XY Position Subsystem/Cursor Rotation/AngleOffset", this.textBoxCursorRotation);
            AddParamListItem("Reward Pulse", "Value", "RewardSbs/Schmidt1/Time", this.textBoxRewardPL);

            // Load
            AddParamListItem("Visc Constant", "Gain", "Force Generator/ViscLoadSubsystem/Gain", this.textBoxVisc);
            AddParamListItem("Curl Angle", "Value", "Force Generator/visAngle", this.textBoxCurlAngle);
            AddParamListItem("Static X Force", "Value", "Force Generator/staticX", this.textBoxLoadX);
            AddParamListItem("Static Y Force", "Value", "Force Generator/staticY", this.textBoxLoadY);
            AddParamListItem("Chaotic Time Constatnt", "Value", "Force Generator/LorentzForce/Lorentz/timescale", this.textBoxTimeConst);
            AddParamListItem("Chaotic Time Constatnt1", "Value", "Force Generator/LorentzForce/Lorentz1/timescale", this.textBoxTimeConst);
            AddParamListItem("Chaotic Time Constatnt2", "Value", "Force Generator/LorentzForce/Lorentz2/timescale", this.textBoxTimeConst);
            AddParamListItem("Chaotic Time Constatnt3", "Value", "Force Generator/LorentzForce/Lorentz3/timescale", this.textBoxTimeConst);
            AddParamListItem("Chaotic Load Gain", "Gain", "Force Generator/LorentzForceGain", this.textBoxChaoticGain);

            /* 
             * Center-Out Parameters 
             */

            // Center-Out timing
            AddParamListItem("CHL", "P4", "Behavior CO", this.textBoxCHL);
            AddParamListItem("CHH", "P5", "Behavior CO", this.textBoxCHH);
            AddParamListItem("DL", "P6", "Behavior CO", this.textBoxDL);
            AddParamListItem("DH", "P7", "Behavior CO", this.textBoxDH);
            AddParamListItem("MT", "P8", "Behavior CO", this.textBoxMT);
            AddParamListItem("OHL", "P9", "Behavior CO", this.textBoxOHL);
            AddParamListItem("OHH", "P10", "Behavior CO", this.textBoxOHH);
            AddParamListItem("IT", "P11", "Behavior CO", this.textBoxID);

            // Center-Out forces
            AddParamListItem("Bump Duration", "P15", "Behavior CO", this.textBoxBumpDuration);
            AddParamListItem("Bump Amplitude", "P14", "Behavior CO", this.textBoxBumpMag);
            AddParamListItem("Catch Trials Pct", "P12", "Behavior CO", this.textBoxCatchPct);

            // Center-Out targets
            AddParamListItem("Target Radius", "P2", "Behavior CO", this.textBoxTgtRadius);
            AddParamListItem("Target Size", "P3", "Behavior CO", this.textBoxTgtSize);

            /* 
             * Random Walk Parameters
             */

            // Random Walk targets
            AddParamListItem("RW Target Size", "P2", "Behavior RW", this.textBoxRWTgtSize);
            AddParamListItem("Work Area Width", "P3", "Behavior RW", this.textBoxWAWidth);
            AddParamListItem("Work Area Height", "P4", "Behavior RW", this.textBoxWAHeight);

            // Random Walk timing
            AddParamListItem("THL", "P5", "Behavior RW", this.textBoxTHL);
            AddParamListItem("THH", "P6", "Behavior RW", this.textBoxTHH);
            AddParamListItem("RW MT", "P7", "Behavior RW", this.textBoxRWMT);
            AddParamListItem("IMT", "P8", "Behavior RW", this.textBoxIMT);
            AddParamListItem("IRW IT", "P9", "Behavior RW", this.textBoxRWIT);

            /* 
             * Forced Choice Parameters
             */

            // Stimulation Parameters
            AddParamListItem("Percent Test Trials", "P2", "Behavior FC", this.textBoxFCPctTestTrials);

            // Forced Choice Timing
            AddParamListItem("FC CHL", "P4", "Behavior FC", this.textBoxFCCHL);
            AddParamListItem("FC CHH", "P5", "Behavior FC", this.textBoxFCCHH);
            AddParamListItem("FC DL", "P6", "Behavior FC", this.textBoxSDL);
            AddParamListItem("FC DH", "P7", "Behavior FC", this.textBoxSDH);
            AddParamListItem("FC MT", "P8", "Behavior FC", this.textBoxFCM);
            AddParamListItem("FC IT", "P9", "Behavior FC", this.textBoxFCI);

            // Forced Choice Targets
            AddParamListItem("FC Target Size", "P10", "Behavior FC", this.textBoxFCTgtSize);
            AddParamListItem("FC Target Distance", "P11", "Behavior FC", this.textBoxFCTgtDist);
        }

        private void AddParamListItem(string short_name, string name, string block, TextBox textbox)
        {
            paramNames.Add(short_name, name);
            paramBlocks.Add(short_name, block);
            if (textbox != null) {
                paramTextBoxes.Add(short_name, textbox);
            }
        }

        private void AddParamListItem(string short_name, string name, string block)
        {
            AddParamListItem(short_name, name, block, null);
        }
        #endregion

        /// <summary>
        /// Updates the status lable in the taskbar to the current status of the target
        /// </summary>
        private void GetStatus()
        {
            if (hasXpcTarget) {
                this.toolStripStatusLabelMdl.Text = "Model: " + target.GetAppName();
            } else {
                this.toolStripStatusLabelMdl.Text = "XPC Target link not connected";
            }
        }

        #region Form Event Callbacks
        private void UpdateForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            this.Hide();
            if (e.CloseReason == CloseReason.UserClosing) {
                e.Cancel = true;
                ((Graphics)this.Owner).RestartTimer();
            } else {
                protocol.Term();
            }
        }

        private void radioButtonBump_CheckedChanged(object sender, EventArgs e)
        {
            bumpGroup.Enabled = true;
            catchGroup.Enabled = false;
        }

        private void radioButtonCatch_CheckedChanged(object sender, EventArgs e)
        {
            bumpGroup.Enabled = false;
            catchGroup.Enabled = true;
        }

        private void radioButtonNoBump_CheckedChanged(object sender, EventArgs e)
        {
            bumpGroup.Enabled = false;
            catchGroup.Enabled = false;
        }

        private void quitToolStripMenuItem_Click(object sender, EventArgs e)
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
             * Viscus
             * Curl
             * Rotating Curl
             * Chaotic
             */

            labelViscConst.Enabled = ((load == "Viscus") || (load == "Curl") || (load == "Rotating Curl"));
            textBoxVisc.Enabled = ((load == "Viscus") || (load == "Curl") || (load == "Rotating Curl"));

            labelCurlAngle.Enabled = (load == "Curl");
            textBoxCurlAngle.Enabled = (load == "Curl");

            labelStaticX.Enabled = load.Equals("Static");
            labelStaticY.Enabled = (load == "Static");
            textBoxLoadX.Enabled = (load == "Static");
            textBoxLoadY.Enabled = (load == "Static");

            labelChaoticGain.Enabled = (load == "Chaotic");
            textBoxChaoticGain.Enabled = (load == "Chaotic");

            labelTimeConst.Enabled = (load == "Chaotic" || load == "Rotating Curl");
            textBoxTimeConst.Enabled = (load == "Chaotic" || load == "Rotating Curl");
        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void okButton_Click(object sender, EventArgs e)
        {
            try {
                Form2Target();
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

        private void textBox_TextChanged(object sender, EventArgs e)
        {
            double tmp;

            if (sender.GetType().Name == "TextBox") {
                TextBox tb = (TextBox)sender;
                if (Double.TryParse(tb.Text, out tmp)) {
                    tb.BackColor = SystemColors.Window;
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

                } catch (InvalidOperationException) {
                    MessageBox.Show("The file does not appear to be in the propper format", "Error loading file", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                } finally {
                    reader.Close();
                }
            }

        }

        private void loadModelToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string file, path;

            if (!hasXpcTarget) {
                MessageBox.Show("Not connected to XPC Target", "Not connected", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            OpenFileDialog ofd = new OpenFileDialog();

            ofd.Filter = "XPC model files|*.dlm";
            ofd.Multiselect = false;
            if (ofd.ShowDialog() == DialogResult.OK) {
                path = Path.GetDirectoryName(ofd.FileName);
                file = Path.GetFileNameWithoutExtension(ofd.FileName);
                target.LoadApp(path, file);
                target.StartApp();
            }

            GetStatus();
        }

        private void fileSaveAs()
        {
            SaveFileDialog sfd = new SaveFileDialog();

            sfd.Filter = "XML Parameter files|*.xml";
            try {
                if (sfd.ShowDialog() == DialogResult.OK) {
                    filename = sfd.FileName;
                    fileSave();
                }
            } catch (InvalidParameterException) {
                MessageBox.Show("One or more parameters are invalid.  File has not been saved.", "Invalid Entry", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void fileSave()
        {
            BehaviorParameters bp;
            XmlSerializer s;
            TextWriter writer;

            bp = Form2BehaviorParameters();
            s = new XmlSerializer(typeof(BehaviorParameters));
            writer = new StreamWriter(filename);
            s.Serialize(writer, bp);
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

            if (!hasXpcTarget) return;

            // One parameter (local to host) is trivial
            this.textBoxScreenWidth.Text = ((Graphics)this.Owner).ScreenScale.ToString();

            // batched parameters
            foreach (string key in paramNames.Keys) {
                paramID = target.GetParamIdx(paramBlocks[key], paramNames[key]);
                if (paramID == -1) {
                    // If we can't find the parameter, clear the textbox
                    paramTextBoxes[key].Text = "";
                } else {
                    param = (double[])target.GetParam(paramID);
                    paramTextBoxes[key].Text = param[0].ToString();
                }
                done += 1f;
                this.toolStripProgressBar1.Value = (int)(100f * done / total);
            }

            // Idiot mode
            paramID = target.GetParamIdx("Behavior CO", "P16");
            if (paramID > 0) {
                param = (double[])target.GetParam(paramID);
                this.checkBoxIdiot.Checked = (param[0] > 0);
            } else {
                this.checkBoxIdiot.Checked = false;
            }
            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            // Bump / Catch
            paramID = target.GetParamIdx("Behavior CO", "P13");
            if (paramID > 0) {
                param = (double[])target.GetParam(paramID);
                if (param[0] == (int)CenterOutMode.Bump) {
                    // bump mode
                    this.radioButtonBump.Checked = true;
                } else if (param[0] == (int)CenterOutMode.Catch) {
                    // Catch mode
                    try {
                        catch_pct = Double.Parse(this.textBoxCatchPct.Text);
                    } catch (FormatException) {
                        catch_pct = 0.0;
                    }
                    if (catch_pct == 0) {
                        this.radioButtonNoBump.Checked = true;
                    } else {
                        this.radioButtonCatch.Checked = true;
                    }
                } else {
                    // default to none
                    this.radioButtonNoBump.Checked = true;
                }
            } else {
                // Set to none if not C/O
                this.radioButtonNoBump.Checked = true;
            }
            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            // Num targets
            paramID = target.GetParamIdx("Behavior CO", "P1");
            if (paramID > 0) {
                param = (double[])target.GetParam(paramID);
                this.numericUpDownNumTgts.Value = (decimal)param[0];
            }
            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            paramID = target.GetParamIdx("Behavior RW", "P1");
            if (paramID > 0) {
                param = (double[])target.GetParam(paramID);
                this.numericUpDownRWTgts.Value = (decimal)param[0];
            }
            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            // Load type
            paramID = target.GetParamIdx("Force Generator/Load", "Value");
            if (paramID > 0) {
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
                    default:
                        paramID = target.GetParamIdx("Value", "Force Generator/DynamicAngle");
                        if (paramID > 0) {
                            param = (double[])target.GetParam(paramID);
                            rot_visc = param[0];
                        } else {
                            rot_visc = 0;
                        }
                        try {
                            visc_angle = Double.Parse(this.textBoxCurlAngle.Text);
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

            paramID = target.GetParamIdx("Behavior FC", "P1");
            if (paramID > 0) {
                param = (double[])target.GetParam(paramID);
                this.numericUpDownFCStimSteps.Value = (decimal)param[0];
            }
            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            paramID = target.GetParamIdx("Behavior FC", "P3");
            if (paramID > 0) {
                param = (double[])target.GetParam(paramID);
                this.checkBoxFCTrainingMode.Checked = (param[0] == 0.0);
            }
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
                try {
                    paramValue = Double.Parse(paramTextBoxes[key].Text);
                } catch (FormatException) {
                    paramValue = 0;
                    error = true;
                    paramTextBoxes[key].BackColor = Color.Crimson;
                }
                d.Add(key, paramValue);
            }
            bp.Parameters = d;

            // Fixed params
            bp.IdiotMode = this.checkBoxIdiot.Checked;
            bp.TrainingMode = this.checkBoxFCTrainingMode.Checked;
            bp.NumTargetsCO = (int)this.numericUpDownNumTgts.Value;
            bp.NumTargetsRW = (int)this.numericUpDownRWTgts.Value;
            bp.NumGradations = (int)this.numericUpDownFCStimSteps.Value;
            bp.Load = (LoadType)this.comboBoxLoad.SelectedIndex;
            if (this.radioButtonBump.Checked) {
                bp.CenterOutMode = CenterOutMode.Bump;
            } else if (this.radioButtonCatch.Checked) {
                bp.CenterOutMode = CenterOutMode.Catch;
            } else {
                bp.CenterOutMode = CenterOutMode.None;
                bp.Parameters["Catch Trials Pct"] = 0;
            }
            try {
                bp.ScreenWidth = Double.Parse(this.textBoxScreenWidth.Text);
            } catch (FormatException) {
                this.textBoxScreenWidth.BackColor = Color.Crimson;
                error = true;
            }

            if (error) throw new InvalidParameterException();
            return bp;
        }

        private void BehaviorParameters2Form(BehaviorParameters bp)
        {
            // Fixed params
            this.checkBoxIdiot.Checked = bp.IdiotMode;
            this.checkBoxFCTrainingMode.Checked = bp.TrainingMode;
            this.numericUpDownFCStimSteps.Value = (decimal)bp.NumGradations;
            this.numericUpDownNumTgts.Value = (decimal)bp.NumTargetsCO;
            this.numericUpDownRWTgts.Value = (decimal)bp.NumTargetsRW;
            this.comboBoxLoad.SelectedIndex = (int)bp.Load;
            if (bp.CenterOutMode == CenterOutMode.Bump) {
                this.radioButtonBump.Checked = true;
            } else if (bp.CenterOutMode == CenterOutMode.Catch) {
                this.radioButtonCatch.Checked = true;
            } else {
                this.radioButtonNoBump.Checked = true;
            }
            this.textBoxScreenWidth.Text = bp.ScreenWidth.ToString();

            // Dictionary params
            foreach (string key in bp.Parameters.Keys) {
                try {
                    paramTextBoxes[key].Text = bp.Parameters[key].ToString();
                } catch (IndexOutOfRangeException) {
                }
            }
        }

        private void BehaviorParameters2Target(BehaviorParameters bp)
        {
            float total = paramNames.Keys.Count + 7;
            float done = 0f;
            int paramID;
            Array param = Array.CreateInstance(typeof(double), 1);

            if (!hasXpcTarget) return;

            /*
             * Fixed params
             */
            // idiot mode
            paramID = target.GetParamIdx("Behavior CO", "P16");
            if (paramID > 0) {
                param.SetValue((bp.IdiotMode ? 1.0 : 0.0), 0);
                target.SetParam(paramID, ref param);
            }
            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            // training mode
            paramID = target.GetParamIdx("Behavior FC", "P3");
            if (paramID > 0) {
                param.SetValue((bp.TrainingMode ? 1.0 : 0.0), 0);
                target.SetParam(paramID, ref param);
            }
            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            // Bump / Catch
            paramID = target.GetParamIdx("Behavior CO", "P13");
            if (paramID > 0) {
                if (bp.CenterOutMode == CenterOutMode.Bump) {
                    param.SetValue((int)CenterOutMode.Bump, 0);
                } else {
                    param.SetValue((int)CenterOutMode.Catch, 0);
                }
                target.SetParam(paramID, ref param);
            }
            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            // Num targets
            paramID = target.GetParamIdx("Behavior CO", "P1");
            if (paramID > 0) {
                param.SetValue(bp.NumTargetsCO, 0);
                target.SetParam(paramID, ref param);
            }
            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            paramID = target.GetParamIdx("Behavior RW", "P1");
            if (paramID > 0) {
                param.SetValue(bp.NumTargetsRW, 0);
                target.SetParam(paramID, ref param);
            }
            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            // Num gradations (FC)
            paramID = target.GetParamIdx("Behavior FC", "P1");
            if (paramID > 0) {
                param.SetValue(bp.NumGradations, 0);
                target.SetParam(paramID, ref param);
            }
            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            // Load type
            paramID = target.GetParamIdx("Force Generator/Load", "Value");
            if (paramID > 0) {
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
                    default:
                        break;
                }
                target.SetParam(paramID, ref param);
            }
            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            /*
             * Dictionary params
             */
            foreach (string key in bp.Parameters.Keys) {
                try {
                    paramID = target.GetParamIdx(paramBlocks[key], paramNames[key]);
                    if (paramID > 0) {
                        param.SetValue(bp.Parameters[key], 0);
                        target.SetParam(paramID, ref param);
                    }
                } catch (IndexOutOfRangeException) {
                }
                done += 1;
                this.toolStripProgressBar1.Value = (int)(100f * done / total);
            }
        }

        private void Form2Target()
        {
            BehaviorParameters2Target(Form2BehaviorParameters());
        }

        #endregion

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //string version = Assembly.GetExecutingAssembly().GetName().Version.ToString();
            new GraphicsAboutBox().Show();
        }
    }
}