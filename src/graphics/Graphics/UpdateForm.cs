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

            // Setup MGTargetGrid
            MGTargetGrid.Rows.Add(16);
            for (int i = 0; i < 16; i++) {
                MGTargetGrid.Rows[i].Cells[0].Value = i + 1;
            }

            // Setup WFTargetGrid
            WFTargetGrid.Rows.Add(16);
            for (int i = 0; i < 16; i++) {

                WFTargetGrid.Rows[i].Cells[0].Value = i + 1;
                for (int j = 1; j < WFTargetGrid.ColumnCount; j++) {
                    WFTargetGrid.Rows[i].Cells[j].Value = 0.0;
                }
            }

            // Setup BCStimTable
            BCStimGrid.Rows.Add(16);
            for (int i = 0; i < 16; i++)
            {
                BCStimGrid.Rows[i].Cells[0].Value = -1;
                BCStimGrid.Rows[i].Cells[1].Value = -1;
            }
            BCStimGrid.Rows[0].DefaultCellStyle.BackColor = Color.Aqua;

            // Setup BFStimTable
            BFStimGrid.Rows.Add(16);
            for (int i = 0; i < 16; i++) {
                BFStimGrid.Rows[i].Cells[0].Value = -1;
                BFStimGrid.Rows[i].Cells[1].Value = -1;
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
            #endregion

            #region Center-Out
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
            AddParamListItem("Delay Bumps", "P18", "Behavior CO", this.checkBoxDelayBumps);

            // Center-Out targets
            AddParamListItem("CO Num Targets", "P1", "Behavior CO", this.numericUpDownNumTgts);
            AddParamListItem("Target Radius", "P2", "Behavior CO", this.textBoxTgtRadius);
            AddParamListItem("Target Size", "P3", "Behavior CO", this.textBoxTgtSize);
            AddParamListItem("Idiot Mode", "P16", "Behavior CO", this.checkBoxIdiot);
            #endregion

            #region Random Walk
            /* 
             * Random Walk Parameters
             */

            // Random Walk targets
            AddParamListItem("RW Num Targets", "P1", "Behavior RW", this.numericUpDownRWTgts);
            AddParamListItem("RW Target Size", "P2", "Behavior RW", this.textBoxRWTgtSize);
            AddParamListItem("Target Tolerance", "P3", "Behavior RW", this.textBoxRWTgtTol);
            AddParamListItem("Left Target Boundary", "P4", "Behavior RW", this.textBoxRWLeftTgtBound);
            AddParamListItem("Right Target Boundary", "P5", "Behavior RW", this.textBoxRWRightTgtBound);
            AddParamListItem("Upper Target Boundary", "P6", "Behavior RW", this.textBoxRWUpperTgtBound);
            AddParamListItem("Lower Target Boundary", "P7", "Behavior RW", this.textBoxRWLowerTgtBound);

            // Random Walk timing
            AddParamListItem("THL", "P8", "Behavior RW", this.textBoxTHL);
            AddParamListItem("THH", "P9", "Behavior RW", this.textBoxTHH);
            AddParamListItem("TDL", "P10", "Behavior RW", this.textBoxTDL);
            AddParamListItem("TDH", "P11", "Behavior RW", this.textBoxTDH);
            AddParamListItem("RW MT", "P12", "Behavior RW", this.textBoxRWMT);
            AddParamListItem("IMT", "P13", "Behavior RW", this.textBoxIMT);
            AddParamListItem("IRW IT", "P14", "Behavior RW", this.textBoxRWIT);

            // Random Walk Anil's Parameters
            AddParamListItem("Minimum Distance", "P15", "Behavior RW", this.textBoxRWMinDistance);
            AddParamListItem("Maximum Distance", "P16", "Behavior RW", this.textBoxRWMaxDistance);
            AddParamListItem("RW Percent Catch Trials", "P17", "Behavior RW", this.textBoxRWPctCatchTrials);

            AddParamListItem("RW Disable Abort", "P19", "Behavior RW", this.checkBoxRWDA);
            AddParamListItem("RW Green Targets", "P20", "Behavior RW", this.checkBoxRWGT);
            AddParamListItem("RW Cumulative Hold", "P21", "Behavior RW", this.checkBoxRWCH);

            #endregion

            #region Forced Choice
            /* 
             * Forced Choice Parameters
             */

            // Stimulation Parameters
            AddParamListItem("FC Num Steps", "P1", "Behavior FC", this.numericUpDownFCStimSteps);
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

            // Misc
            AddParamListItem("FC Training Mode", "P3", "Behavior FC", this.checkBoxFCTrainingMode);
            AddParamListItem("FC Reward All Test Trials", "P12", "Behavior FC", this.checkBoxFCRAT);
            AddParamListItem("FC Reward Threshold", "P13", "Behavior FC", this.textBoxFCRewardThreshold);
            #endregion

            #region Bump-stim
            /* 
             * Bump-stim Parameters 
             */

            // Num Steps
            AddParamListItem("BS Num Steps", "", "Behavior BS", this.numericUpDownBSBumpSteps);

            // Bump-stim timing
            AddParamListItem("BS OHL", "P5", "Behavior BS", this.textBoxBSOHL);
            AddParamListItem("BS OHH", "P6", "Behavior BS", this.textBoxBSOHH);
            AddParamListItem("BS DL", "P7", "Behavior BS", this.textBoxBSDL);
            AddParamListItem("BS DH", "P8", "Behavior BS", this.textBoxBSDH);
            AddParamListItem("BS M", "P9", "Behavior BS", this.textBoxBSM);
            AddParamListItem("BS DHL", "P10", "Behavior BS", this.textBoxBSDHL);
            AddParamListItem("BS DHH", "P11", "Behavior BS", this.textBoxBSDHH);
            AddParamListItem("BS I", "P12", "Behavior BS", this.textBoxBSI);

            // Bump-stim bump
            AddParamListItem("BS Stim Trials Pct", "P13", "Behavior BS", this.textBoxBSPctStimTrials);
            AddParamListItem("BS Bump Trials Pct", "P14", "Behavior BS", this.textBoxBSPctBumpTrials);
            AddParamListItem("BS Bump Step Magnitude", "P15", "Behavior BS", this.textBoxBSBumpStepMag);
            AddParamListItem("BS Bump Duration", "P16", "Behavior BS", this.textBoxBSBumpDur);
            AddParamListItem("BS Num Bump Steps", "P17", "Behavior BS", this.numericUpDownBSBumpSteps);
            AddParamListItem("BS Num Stim Steps", "P18", "Behavior BS", this.numericUpDownBSStimSteps);
            AddParamListItem("BS Bump Displacement", "P22", "Behavior BS", this.textBoxBSBumpDisp);
            AddParamListItem("BS Stim Displacement", "P23", "Behavior BS", this.textBoxBSStimDisp);

            // Bump-stim targets
            AddParamListItem("BS Target Angle", "P1", "Behavior BS", this.textBoxBSTgtAngle);
            AddParamListItem("BS Target Num", "P19", "Behavior BS", this.textBoxBSNumTargetsSeq);
            AddParamListItem("BS Target Radius", "P2", "Behavior BS", this.textBoxBSTgtRadius);
            AddParamListItem("BS Target Size", "P3", "Behavior BS", this.textBoxBSTgtSize);
            AddParamListItem("BS Window Diameter", "P4", "Behavior BS", this.textBoxBSWindowDiameter);
            AddParamListItem("BS Num Target Positions", "P21", "Behavior BS", this.textBoxBSNumAngles);
            #endregion

            #region Multi-Gadget
            // Targets
            AddParamListItem("MGTargets", "P1", "Behavior MG", this.numericUpDownMGTargets);

            // Timing
            AddParamListItem("MGTPL", "P2", "Behavior MG", this.textBoxMGTPL);
            AddParamListItem("MGTPH", "P3", "Behavior MG", this.textBoxMGTPH);
            AddParamListItem("MGDL", "P4", "Behavior MG", this.textBoxMGDL);
            AddParamListItem("MGDH", "P5", "Behavior MG", this.textBoxMGDH);
            AddParamListItem("MGRT", "P6", "Behavior MG", this.textBoxMGRT);
            AddParamListItem("MGTH", "P7", "Behavior MG", this.textBoxMGTH);
            AddParamListItem("MGI", "P8", "Behavior MG", this.textBoxMGI);

            // Gadgets used
            AddParamListItem("MG0", "P9", "Behavior MG", this.checkBoxMG0);
            AddParamListItem("MG1", "P10", "Behavior MG", this.checkBoxMG1);
            AddParamListItem("MG2", "P11", "Behavior MG", this.checkBoxMG2);
            AddParamListItem("MG3", "P12", "Behavior MG", this.checkBoxMG3);

            // Options
            //param 13 = master_reset
            AddParamListItem("MGIM", "P14", "Behavior MG", this.checkBoxMGIM);
            AddParamListItem("MGMT", "P15", "Behavior MG", this.checkBoxMGMT);
            //param 16 = clear_MVC_tgts
            AddParamListItem("MGCatchTrials", "P17", "Behavior MG", this.textBoxMGCT);

            //Gadget Gains
            //MGGains = new double[4];
            //double[] MGGains = {Double.Parse(this.MGGain0.Text),
            //                    Double.Parse(this.MGGain1.Text),
            //                    Double.Parse(this.MGGain2.Text),
            //                    Double.Parse(this.MGGain3.Text)};
            //AddParamListItem("MGGains", "table", "CursorPos/GadgetGains", MGGains);
            //AddParamListItem("MGGain0", "table(1)","CursorPos/GadgetGains", this.MGGain0);
            //AddParamListItem("MGGain1", "table(2)","CursorPos/GadgetGains", this.MGGain1);
            //AddParamListItem("MGGain2", "table(3)","CursorPos/GadgetGains", this.MGGain2);
            //AddParamListItem("MGGain3", "table(4)","CursorPos/GadgetGains", this.MGGain3);


            #endregion

            #region Ball-Drop

            // Timing
            AddParamListItem("BDTPL", "P1", "Behavior BD", this.textBoxBDTPL);
            AddParamListItem("BDTPH", "P2", "Behavior BD", this.textBoxBDTPH);
            AddParamListItem("BDDL", "P3", "Behavior BD", this.textBoxBDDL);
            AddParamListItem("BDDH", "P4", "Behavior BD", this.textBoxBDDH);
            AddParamListItem("BDPT", "P5", "Behavior BD", this.textBoxBDPT);
            AddParamListItem("BDDT", "P6", "Behavior BD", this.textBoxBDDT);
            AddParamListItem("BDIT", "P7", "Behavior BD", this.textBoxBDI);

            // Options
            //param 8 = master_reset
            // now catch trial is a comboBox
            //AddParamListItem("BDCatchTrials", "P9", "Behavior BD", this.textBoxBDCT);


            #endregion

            #region Wrist Flexion
            //Targets
            AddParamListItem("WFTargets", "P1", "Behavior WF", this.numericUpDownWFTargets);

            //Timing
            AddParamListItem("WFRT", "P2", "Behavior WF", this.textBoxWFRT);
            AddParamListItem("WFTH", "P3", "Behavior WF", this.textBoxWFTH);
            AddParamListItem("WFCHL", "P4", "Behavior WF", this.textBoxWFCHL);
            AddParamListItem("WFCHH", "P20", "Behavior WF", this.textBoxWFCHH);
            AddParamListItem("WFI", "P5", "Behavior WF", this.textBoxWFI);
            AddParamListItem("WFCDL", "P10", "Behavior WF", this.textBoxWFCDL);
            AddParamListItem("WFCDH", "P11", "Behavior WF", this.textBoxWFCDH);

            //Center
            AddParamListItem("WFX", "P6", "Behavior WF", this.textBoxWFX);
            AddParamListItem("WFY", "P7", "Behavior WF", this.textBoxWFY);
            AddParamListItem("WFH", "P8", "Behavior WF", this.textBoxWFH);
            AddParamListItem("WFW", "P9", "Behavior WF", this.textBoxWFW);

            //Options
            AddParamListItem("WFIM", "P12", "Behavior WF", this.checkBoxWFIM);
            // param 13 = clear_MVC_Targets
            // param 14 = master_reset
            AddParamListItem("WFCatchTrials", "P15", "Behavior WF", this.textBoxWFCT);
            
            //Input Type
            AddParamListItem("EncodersOn", "Value", "CursorPos/EnableEncoders", this.checkBoxWFEncodersOn);

            // Rotation
            AddParamListItem("WFRotation", "P16", "Behavior WF", this.textBoxWFRot);
            AddParamListItem("WFRotationInc", "P17", "Behavior WF", this.textBoxWFRotInc);
            AddParamListItem("WFRotationMax", "P18", "Behavior WF", this.textBoxWFRotMax);
            // param 19 = update_count

            //Cursor Overload
            AddParamListItem("WFGX", "Gain", "CursorPos/GainX", this.textBoxWFGX);
            AddParamListItem("WFGY", "Gain", "CursorPos/GainY", this.textBoxWFGY);
            AddParamListItem("WFOffsetX", "Value", "CursorPos/OffsetX", this.textBoxWFOX);
            AddParamListItem("WFOffsetY", "Value", "CursorPos/OffsetY", this.textBoxWFOY);

            // Software Filter
            AddParamListItem("WFFiltEnable", "Value", "CursorPos/EnablePosFilter", this.checkBoxWFFILT);

            // Integration
            AddParamListItem("WFIntegration", "Value", "CursorPos/EnableIntegrator", this.checkBoxWFIntegrate);
            AddParamListItem("WFIntegratMax", "UpperSaturationLimit", "CursorPos/Integrator", this.textBoxWFIntMax);
            AddParamListItem("WFIntegratMin", "LowerSaturationLimit", "CursorPos/Integrator", this.textBoxWFIntMin);

            // Neural Control
            AddParamListItem("WFNeuralControl", "Value", "CursorPos/NeuralControlPct", this.textBoxWFNC);

            #endregion

            #region Bump-choice
            /* 
             * Bump-choice Parameters 
             */
            // Bump-choice targets
            AddParamListItem("BC Target Radius", "P3", "Behavior BC", this.textBoxBCTgtRadius);
            AddParamListItem("BC Target Size", "P4", "Behavior BC", this.textBoxBCTgtSize);
            AddParamListItem("BC Window Diameter", "P5", "Behavior BC", this.textBoxBCWindowDiameter);

            // Bump-choice bump
            AddParamListItem("BC Num Bump Steps", "P6", "Behavior BC", this.numericUpDownBCBumpSteps);
            AddParamListItem("BC Bump Magnitude Min", "P7", "Behavior BC", this.textBoxBCBumpMagMin);
            AddParamListItem("BC Bump Magnitude Max", "P8", "Behavior BC", this.textBoxBCBumpMagMax);
            AddParamListItem("BC Bump Duration", "P9", "Behavior BC", this.textBoxBCBumpDur);

            // Bump-choice timing
            AddParamListItem("BC OHL", "P10", "Behavior BC", this.textBoxBCOHL);
            AddParamListItem("BC OHH", "P11", "Behavior BC", this.textBoxBCOHH);
            AddParamListItem("BC M", "P12", "Behavior BC", this.textBoxBCM);
            AddParamListItem("BC IR", "P13", "Behavior BC", this.textBoxBCIR);
            AddParamListItem("BC IF", "P14", "Behavior BC", this.textBoxBCIF);
            AddParamListItem("BC IA", "P15", "Behavior BC", this.textBoxBCIA);

            // Training trials
            AddParamListItem("BC Pct Training Trials", "P16", "Behavior BC", this.textBoxBCPctTraining);  
   
            // Stimulation parameters
            AddParamListItem("BC Pct Stimulation Trials", "P17", "Behavior BC", this.textBoxBCPctStimTrials);
                        
            // Bump and stim
            AddParamListItem("BC Bump and Stim", "P18", "Behavior BC", this.checkBoxBCBumpAndStim);

            // Center target off on go cue
            AddParamListItem("BC Center Target Off", "P19", "Behavior BC", this.checkBoxBCCenterTargetOff);

            // Outer target(s) on on center hold
            AddParamListItem("BC Outer Target On", "P20", "Behavior BC", this.checkBoxBCOuterTargetOn);

            // Go tone on bump
            AddParamListItem("BC Go Tone On Bump", "P21", "Behavior BC", this.checkBoxBCGoToneOnBump);

            // Target directions from stim table
            AddParamListItem("BC Target Directions From Stim Table", "P22", "Behavior BC", this.checkBoxBCTargetDirectionsStim);

            // Number of outer targets
            AddParamListItem("BC Num Outer Targets", "P23", "Behavior BC", this.numericUpDownBCNumOuterTargets);

            // Bump delay 
            AddParamListItem("BC Bump Delay Low", "P24", "Behavior BC", this.textBoxBCBDL);
            AddParamListItem("BC Bump Delay High", "P25", "Behavior BC", this.textBoxBCBDH);

            // Abort/fail distance to target
            AddParamListItem("BC Abort Distance", "P26", "Behavior BC", this.textBoxBCAbortDistance);

            // Reward minimum and maximum
            AddParamListItem("BC Reward Min", "P27", "Behavior BC", this.textBoxBCRewardMin);
            AddParamListItem("BC Reward Max", "P28", "Behavior BC", this.textBoxBCRewardMax);

            // Reward/punishment multipliers for special cases (no stim/no bump)
            AddParamListItem("BC Reward Multiplier", "P29", "Behavior BC", this.textBoxBCRewardMultiplier);
            AddParamListItem("BC Fail Wait Multiplier", "P30", "Behavior BC", this.textBoxBCFailMultiplier);
            AddParamListItem("BC Bump Multiplier", "P31", "Behavior BC", this.checkBoxBCZeroBumpMultiplier);

            AddParamListItem("BC Random bump direction", "P32", "Behavior BC", this.checkBoxBCRandomBump);
            AddParamListItem("BC Target Color", "P33", "Behavior BC", this.textBoxBCTargetColor);

            AddParamListItem("BC Bump magnitude zero", "P34", "Behavior BC", this.checkBoxBCBumpMagZero);
            AddParamListItem("BC First stim repeat", "P35", "Behavior BC", this.textBoxBCStim1Repeat);
                        
            #endregion

            #region Visual Search
            /* 
             * Visual Search Parameters 
             */

            // Visual Search targets
            AddParamListItem("VS Num Targets", "P1", "Behavior VS", this.numericUpDownVSNumTarg);
            AddParamListItem("VS Target Radius", "P2", "Behavior VS", this.textBoxVSTR);
            AddParamListItem("VS Target Size", "P3", "Behavior VS", this.textBoxVSTS);

            // Visual Search timing
            AddParamListItem("VS Center Hold Low", "P5", "Behavior VS", this.textBoxVSCHL);
            AddParamListItem("VS Center Hold High", "P6", "Behavior VS", this.textBoxVSCHH);
            AddParamListItem("VS Search Time", "P7", "Behavior VS", this.textBoxVSST);
            AddParamListItem("VS Reach Time", "P8", "Behavior VS", this.textBoxVSRT);
            AddParamListItem("VS Outer Hold Low", "P9", "Behavior VS", this.textBoxVSOHL);
            AddParamListItem("VS Outer Hold High", "P10", "Behavior VS", this.textBoxVSOHH);
            AddParamListItem("VS Abort Timeout", "P11", "Behavior VS", this.textBoxVSATO);
            AddParamListItem("VS Fail Timeout", "P12", "Behavior VS", this.textBoxVSFTO);
            AddParamListItem("VS Incomplete Timeout", "P13", "Behavior VS", this.textBoxVSITO);
            AddParamListItem("VS Reward Timeout", "P14", "Behavior VS", this.textBoxVSRTO);

            AddParamListItem("VS Disable Abort", "P16", "Behavior VS", this.checkBoxVSDA);
            AddParamListItem("VS Green Targets", "P17", "Behavior VS", this.checkBoxVSGT);

            #endregion

            #region Uncertainty
            /* 
             * Uncertainty 1D Parameters 
             */

            // Uncertainty Timing
            AddParamListItem("UCHL", "P2", "Behavior Un1d", this.textBoxUCHL);
            AddParamListItem("UCHH", "P3", "Behavior Un1d", this.textBoxUCHH);
            AddParamListItem("UDL", "P4", "Behavior Un1d", this.textBoxUDL);
            AddParamListItem("UDH", "P5", "Behavior Un1d", this.textBoxUDH);
            AddParamListItem("UOHL", "P6", "Behavior Un1d", this.textBoxUOHL);
            AddParamListItem("UOHH", "P7", "Behavior Un1d", this.textBoxUOHH);
            AddParamListItem("UIT", "P8", "Behavior Un1d", this.textBoxUID);
            AddParamListItem("UMT", "P9", "Behavior Un1d", this.textBoxUMT);
            AddParamListItem("UFLT", "P10", "Behavior Un1d", this.textBoxUFLT);

            // Uncertainty Forces

            // Uncertainty Targets
            AddParamListItem("Un Target Angle", "P11", "Behavior Un1d", this.numericUpDownUTgtAngDeg);
            AddParamListItem("Un Target Radius", "P12", "Behavior Un1d", this.textBoxUTgtRadius);
            AddParamListItem("Un Target Size", "P13", "Behavior Un1d", this.textBoxUTgtSize);
            AddParamListItem("Un Error Targets On", "P14", "Behavior Un1d", this.checkBoxUErrorTgtsOn);

            // Uncertainty Displacement Parameters
            AddParamListItem("Un Disp Mean", "P15", "Behavior Un1d", this.textBoxUDispMean);
            AddParamListItem("Un Disp Var", "P16", "Behavior Un1d", this.textBoxUDispVar);
            AddParamListItem("Un Block Win Start", "P17", "Behavior Un1d", this.textBoxUBlockWinStart);
            AddParamListItem("Un Block Win End", "P18", "Behavior Un1d", this.textBoxUBlockWinEnd);

            // Uncertainty Feedback Parameters
            AddParamListItem("Un Cloud Var", "P19", "Behavior Un1d", this.textBoxUFbVar);
            AddParamListItem("Un Cloud Var 2", "P20", "Behavior Un1d", this.textBoxUFbVar2);
            AddParamListItem("Un Cloud Var 3", "P21", "Behavior Un1d", this.textBoxUFbVar3);
            AddParamListItem("Un Cloud Var 4", "P22", "Behavior Un1d", this.textBoxUFbVar4);

            AddParamListItem("Un Cloud Frq", "P23", "Behavior Un1d", this.textBoxUFbFrq);
            AddParamListItem("Un Cloud Frq 2", "P24", "Behavior Un1d", this.textBoxUFbFrq2);
            AddParamListItem("Un Cloud Frq 3", "P25", "Behavior Un1d", this.textBoxUFbFrq3);
            AddParamListItem("Un Cloud Frq 4", "P26", "Behavior Un1d", this.textBoxUFbFrq4);

            AddParamListItem("Un Cloud One Block", "P27", "Behavior Un1d", this.checkBoxUCloudOneBlock);

            AddParamListItem("Un Feedback Start", "P28", "Behavior Un1d", this.textBoxUFbStart);
            AddParamListItem("Un Feedback End", "P29", "Behavior Un1d", this.textBoxUFbEnd);
            AddParamListItem("Un Dot Size", "P30", "Behavior Un1d", this.textBoxUDotSize);
            AddParamListItem("Un Num Dots", "P31", "Behavior Un1d", this.numericUUpDownDotNum);

            AddParamListItem("Un Timed Feedback On", "P32", "Behavior Un1d", this.checkBoxUTimedFeedbackOn);
            AddParamListItem("Un Feedback Time", "P33", "Behavior Un1d", this.textBoxUFbTime);
            AddParamListItem("Un Feedback Loc", "P34", "Behavior Un1d", this.textBoxUFbLoc);

            AddParamListItem("Un Center Offset", "P35", "Behavior Un1d", this.textBoxUCenterOffset);
            #endregion

            #region Bump-follow
            /* 
             * Bump-follow Parameters 
             */
            // Bump-follow targets
            AddParamListItem("BF Arc Radius", "P2", "Behavior BF", this.textBoxBFArcRadius);
            AddParamListItem("BF Arc Thickness", "P3", "Behavior BF", this.textBoxBFAT);
            AddParamListItem("BF Arc Length", "P4", "Behavior BF", this.textBoxBFAL);
            AddParamListItem("BF Target Size", "P5", "Behavior BF", this.textBoxBFTgtSize);
            AddParamListItem("BF Window Diameter", "P6", "Behavior BF", this.textBoxBFWindowRadius);

            // Bump-choice bump
            AddParamListItem("BF Num Bump Steps", "P7", "Behavior BF", this.numericUpDownBFBumpSteps);
            AddParamListItem("BF Bump Magnitude Min", "P8", "Behavior BF", this.textBoxBFBumpMagMin);
            AddParamListItem("BF Bump Magnitude Max", "P9", "Behavior BF", this.textBoxBFBumpMagMax);
            AddParamListItem("BF Bump Duration", "P10", "Behavior BF", this.textBoxBFBumpDur);

            // Bump-choice timing
            AddParamListItem("BF OHL", "P11", "Behavior BF", this.textBoxBFOHL);
            AddParamListItem("BF OHH", "P12", "Behavior BF", this.textBoxBFOHH);
            AddParamListItem("BF M", "P13", "Behavior BF", this.textBoxBFM);
            AddParamListItem("BF I", "P14", "Behavior BF", this.textBoxBFI);
            AddParamListItem("BF IF", "P15", "Behavior BF", this.textBoxBFIF);

            // Training trials
            AddParamListItem("BF Pct Training Trials", "P16", "Behavior BF", this.textBoxBFPctTraining);

            // Stimulation parameters
            AddParamListItem("BF Pct Stimulation Trials", "P17", "Behavior BF", this.textBoxBFPctStimTrials);

            #endregion

            #region Two-alternative forced choice
            /* 
             * Two-alternative forced choice Parameters 
             */
            // Two-alternative forced choice targets
            AddParamListItem("2AFC Target Radius", "P3", "Behavior 2AFC", this.textBox2AFCTgtRadius);
            AddParamListItem("2AFC Target Size", "P4", "Behavior 2AFC", this.textBox2AFCTgtSize);
            AddParamListItem("2AFC Window Diameter", "P5", "Behavior 2AFC", this.textBox2AFCWindowRadius);
            
            // Two-alternative forced choice timing
            AddParamListItem("2AFC OHL", "P6", "Behavior 2AFC", this.textBox2AFCOHL);
            AddParamListItem("2AFC OHH", "P7", "Behavior 2AFC", this.textBox2AFCOHH);
            AddParamListItem("2AFC M", "P8", "Behavior 2AFC", this.textBox2AFCM);
            AddParamListItem("2AFC IL", "P9", "Behavior 2AFC", this.textBox2AFCIL);
            AddParamListItem("2AFC IS", "P10", "Behavior 2AFC", this.textBox2AFCIS);
            AddParamListItem("2AFC II", "P11", "Behavior 2AFC", this.textBox2AFCII);
            AddParamListItem("2AFC IR", "P12", "Behavior 2AFC", this.textBox2AFCIR);
            AddParamListItem("2AFC IF", "P13", "Behavior 2AFC", this.textBox2AFCIF);
            AddParamListItem("2AFC IA", "P14", "Behavior 2AFC", this.textBox2AFCIA);
            AddParamListItem("2AFC SDL", "P15", "Behavior 2AFC", this.textBox2AFCSDL);
            AddParamListItem("2AFC SDH", "P16", "Behavior 2AFC", this.textBox2AFCSDH);

            // Training trials
            AddParamListItem("2AFC Pct Training Trials", "P17", "Behavior 2AFC", this.textBox2AFCPercentTraining);
            AddParamListItem("2AFC CT Color Change", "P18", "Behavior 2AFC", this.checkBox2AFCCTColorChange);
            
            // Left target parameters
            AddParamListItem("2AFC T1 Tone", "P19", "Behavior 2AFC", this.checkBox2AFCLTTC);
            AddParamListItem("2AFC T1 ICMS", "P20", "Behavior 2AFC", this.checkBox2AFCLTI);
            AddParamListItem("2AFC T1 Bump", "P21", "Behavior 2AFC", this.checkBox2AFCLTB);
            AddParamListItem("2AFC T1 ICMS codes", "P22", "Behavior 2AFC", this.numericUpDown2AFCLTNSC);
            AddParamListItem("2AFC T1 Bump steps", "P23", "Behavior 2AFC", this.numericUpDown2AFCLTNBS);
            AddParamListItem("2AFC T1 Bump mag min", "P24", "Behavior 2AFC", this.textBox2AFCLTBMMin);
            AddParamListItem("2AFC T1 Bump mag max", "P25", "Behavior 2AFC", this.textBox2AFCLTBMMax);
            AddParamListItem("2AFC T1 Bump direction", "P26", "Behavior 2AFC", this.textBox2AFCLTBDir);
            AddParamListItem("2AFC T1 Bump duration", "P27", "Behavior 2AFC", this.textBox2AFCLTBDur);

            // Right target parameters
            AddParamListItem("2AFC T2 Tone", "P28", "Behavior 2AFC", this.checkBox2AFCRTTC);
            AddParamListItem("2AFC T2 ICMS", "P29", "Behavior 2AFC", this.checkBox2AFCRTI);
            AddParamListItem("2AFC T2 Bump", "P30", "Behavior 2AFC", this.checkBox2AFCRTB);
            AddParamListItem("2AFC T2 ICMS codes", "P31", "Behavior 2AFC", this.numericUpDown2AFCRTNSC);
            AddParamListItem("2AFC T2 Bump steps", "P32", "Behavior 2AFC", this.numericUpDown2AFCRTNBS);
            AddParamListItem("2AFC T2 Bump mag min", "P33", "Behavior 2AFC", this.textBox2AFCRTBMMin);
            AddParamListItem("2AFC T2 Bump mag max", "P34", "Behavior 2AFC", this.textBox2AFCRTBMMax);
            AddParamListItem("2AFC T2 Bump direction", "P35", "Behavior 2AFC", this.textBox2AFCRTBDir);
            AddParamListItem("2AFC T2 Bump duration", "P36", "Behavior 2AFC", this.textBox2AFCRTBDur);
            #endregion

            #region Attention
            /* 
             * Attention Parameters 
             */
            
            // Timing
            AddParamListItem("AT CHL", "P2", "Behavior AT", this.textBoxATCHL);
            AddParamListItem("AT CHH", "P3", "Behavior AT", this.textBoxATCHH);
            AddParamListItem("AT IBL", "P4", "Behavior AT", this.textBoxATIBL);
            AddParamListItem("AT IBH", "P5", "Behavior AT", this.textBoxATIBH);
            AddParamListItem("AT M", "P6", "Behavior AT", this.textBoxATM);
            AddParamListItem("AT RW", "P7", "Behavior AT", this.textBoxATRW);
            AddParamListItem("AT FW", "P8", "Behavior AT", this.textBoxATFW);
            AddParamListItem("AT AW", "P9", "Behavior AT", this.textBoxATAW);
            AddParamListItem("AT OTD", "P10", "Behavior AT", this.textBoxATOTD);

            // Targets
            AddParamListItem("AT TS", "P11", "Behavior AT", this.textBoxATTS);
            AddParamListItem("AT TR", "P12", "Behavior AT", this.textBoxATTR);
            AddParamListItem("AT VTD", "P13", "Behavior AT", this.textBoxATVTD);
            AddParamListItem("AT IVT", "P14", "Behavior AT", this.textBoxATIVT);

            // Trial types
            AddParamListItem("AT PVT", "P15", "Behavior AT", this.textBoxATPVT);
            AddParamListItem("AT PPT", "P16", "Behavior AT", this.textBoxATPPT);
            AddParamListItem("AT TBS", "P17", "Behavior AT", this.textBoxATTBS);
            AddParamListItem("AT PTT", "P18", "Behavior AT", this.textBoxATPTT);
            AddParamListItem("AT PCT", "P19", "Behavior AT", this.textBoxATPCT);
            AddParamListItem("AT BD", "P20", "Behavior AT", this.checkBoxATBP);
            AddParamListItem("AT BDirs", "P21", "Behavior AT", this.numericUpDownATND);
            AddParamListItem("AT FBD", "P22", "Behavior AT", this.textBoxATFBD);
            
            // Visual targets or proprioceptive parameters
            AddParamListItem("AT VNS", "P23", "Behavior AT", this.numericUpDownATVNS);
            AddParamListItem("AT VTMinR", "P24", "Behavior AT", this.textBoxATVTMinR);
            AddParamListItem("AT VTMaxR", "P25", "Behavior AT", this.textBoxATVTMaxR);
            AddParamListItem("AT NBM", "P26", "Behavior AT", this.numericUpDownATNBM);
            AddParamListItem("AT BMMin", "P27", "Behavior AT", this.textBoxATBMMin);
            AddParamListItem("AT BMMax", "P28", "Behavior AT", this.textBoxATBMMax);
            AddParamListItem("AT BDur", "P29", "Behavior AT", this.textBoxATBD);
            AddParamListItem("AT S", "P30", "Behavior AT", this.checkBoxATS);
            AddParamListItem("AT SR", "P31", "Behavior AT", this.numericUpDownATSR);
            
            // Bias force
            AddParamListItem("AT BFM", "P32", "Behavior AT", this.textBoxATBFM);
            AddParamListItem("AT BFD", "P33", "Behavior AT", this.textBoxATBFD);
            AddParamListItem("AT BFR", "P34", "Behavior AT", this.textBoxATBFR);  
            
            #endregion

            #region Bump direction psychophysics
            // Timing
            AddParamListItem("2BC CT Hold", "P10", "Behavior 2BC", textBox2BCCTH);
            AddParamListItem("2BC CT Delay", "P11", "Behavior 2BC", textBox2BCCTD);
            AddParamListItem("2BC Bump Hold", "P12", "Behavior 2BC", textBox2BCBH);
            AddParamListItem("2BC intertrial", "P13", "Behavior 2BC", textBox2BCInt);

            // Bump
            AddParamListItem("2BC Bump Mag", "P7", "Behavior 2BC", textBox2BCBA);
            AddParamListItem("2BC Bump Dur", "P8", "Behavior 2BC", textBox2BCPD);
            AddParamListItem("2BC Bump RT", "P9", "Behavior 2BC", textBox2BCRT);

            // Staircase
            AddParamListItem("2BC SC Run", "P14", "Behavior 2BC", checkBox2BCRS);
            AddParamListItem("2BC SC Step", "P15", "Behavior 2BC", textBox2BCSCStep);
            AddParamListItem("2BC SC Use Bottom", "P16", "Behavior 2BC", checkBox2BCBS);
            AddParamListItem("2BC SC Reset", "P2", "Behavior 2BC", numericUpDown2BCSCR);
            AddParamListItem("2BC SC Limits", "P19", "Behavior 2BC", checkBox2BCSCLimit);

            // Targets
            AddParamListItem("2BC Targ Rad", "P3", "Behavior 2BC", textBox2BCTR);
            AddParamListItem("2BC Targ Dist", "P4", "Behavior 2BC", textBox2BCTD);
            AddParamListItem("2BC Targ Grow", "P5", "Behavior 2BC", textBox2BCBTR);
            AddParamListItem("2BC Targ Ang", "P6", "Behavior 2BC", angleEntryBox2BCAng);
            AddParamListItem("2BC Targ Green", "P17", "Behavior 2BC", checkBox2BCGT);
            AddParamListItem("2BC Hide Cursor", "P18", "Behavior 2BC", checkBox2BCHC);

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

        private void radioButtonBump_CheckedChanged(object sender, EventArgs e)
        {
            bumpGroup.Enabled = true;
            catchGroup.Enabled = false;

            widget_ValueChanged(sender, e);
        }

        private void radioButtonCatch_CheckedChanged(object sender, EventArgs e)
        {
            bumpGroup.Enabled = false;
            catchGroup.Enabled = true;

            widget_ValueChanged(sender, e);
        }

        private void radioButtonNoBump_CheckedChanged(object sender, EventArgs e)
        {
            bumpGroup.Enabled = false;
            catchGroup.Enabled = false;

            widget_ValueChanged(sender, e);
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
            textBoxWFOX.Text = String.Format("{0:f5}", -RawXValue);
            textBoxWFOY.Text = String.Format("{0:f5}", -RawYValue);

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

        private void checkBoxFCRAT_CheckedChanged(object sender, EventArgs e)
        {
            textBoxFCRewardThreshold.Enabled = !checkBoxFCRAT.Checked;

            widget_ValueChanged(sender, e);
        }

        private void UpdateForm_Shown(object sender, EventArgs e)
        {
            foreach (CursorDef cd in ((Graphics)this.Owner).CursorDefs) {
                this.comboBoxCursor.Items.Add(cd.Name);
            }

            foreach (GlyphDef gd in ((Graphics)this.Owner).GlyphDefs) {
                this.comboBoxGlyphSelect.Items.Add(gd.Name);
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

            SoundPlayer.SoundTheme theme;

            if (sender.Equals(theme2ToolStripMenuItem)) {
                theme = SoundPlayer.SoundTheme.Theme2;
                theme2ToolStripMenuItem.Checked = true;
            } else if (sender.Equals(theme3ToolStripMenuItem)) {
                theme = SoundPlayer.SoundTheme.Theme3;
                theme3ToolStripMenuItem.Checked = true;
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
                }

                done += 1f;
                this.toolStripProgressBar1.Value = (int)(100f * done / total);
            }

            #region BD_Catch
            paramID = target.GetParamIdx("Behavior BD", "P9");
            if (paramID >= 0)
            {
                param = (double[])target.GetParam(paramID);
                switch ((BD_Catch_List)param[0])
                {
                    case BD_Catch_List.None:
                        this.comboBoxBDCT.SelectedIndex = 0;
                        break;
                    case BD_Catch_List.pct5:
                        this.comboBoxBDCT.SelectedIndex = 1;
                        break;
                    case BD_Catch_List.pct10:
                        this.comboBoxBDCT.SelectedIndex = 2;
                        break;
                    case BD_Catch_List.pct14:
                        this.comboBoxBDCT.SelectedIndex = 3;
                        break;
                    case BD_Catch_List.pct20:
                        this.comboBoxBDCT.SelectedIndex = 4;
                        break;
                    case BD_Catch_List.pct25:
                        this.comboBoxBDCT.SelectedIndex = 5;
                        break;
                    case BD_Catch_List.pct33:
                        this.comboBoxBDCT.SelectedIndex = 6;
                        break;
                    default:
                        this.comboBoxBDCT.SelectedIndex = 7;
                        break;
                }
            }
            #endregion
            
            // Bump / Catch
            paramID = target.GetParamIdx("Behavior CO", "P13");
            if (paramID >= 0) {
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

            // MultiGadget Targets
            paramID = target.GetParamIdx("TargetTable", "table");
            if (paramID != -1) {
                // Get Dimensions               
                int[] dims = (int[])target.GetParamDims(paramID);
                int numRows = (int)dims[0];
                int numCols = (int)dims[1];

                param = (double[])target.GetParam(paramID);
                for (int row = 0; row < numRows - 1; row++) { // Rows -1 because we don't need to update y_var
                    for (int col = 0; col < numCols; col++) {
                        double d = param[col * numRows + row];
                        MGTargetGrid.Rows[col].Cells[row + 1].Value = d.ToString();
                    }
                }
            }
            
            //MG-Gains
            paramID = target.GetParamIdx("CursorPos/GadgetGain", "table");
            if (paramID != -1) {
                param = (double[])target.GetParam(paramID);
                MGGain0.Text = param[0].ToString();
                MGGain1.Text = param[1].ToString();
                MGGain2.Text = param[2].ToString();
                MGGain3.Text = param[3].ToString();
            }


            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            // Wrist Flexion Targets
            paramID = target.GetParamIdx("WFTargetTable", "table");
            if (paramID != -1) {
                // Get Dimensions               
                int[] dims = (int[])target.GetParamDims(paramID);
                int numRows = (int)dims[0];
                int numCols = (int)dims[1];

                param = (double[])target.GetParam(paramID);
                for (int row = 0; row < numRows - 2; row++) { // Rows - 2 because we don't need to update x_var and y_var enable check boxes
                    for (int col = 0; col < numCols; col++) {
                        double d = param[col * numRows + row];
                        WFTargetGrid.Rows[col].Cells[row + 1].Value = d.ToString();
                    }
                }
            }

            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            // Bump choice stimulation table
            paramID = target.GetParamIdx("BCStimTable", "table");
            if (paramID != -1)
            {
                param = (double[])target.GetParam(paramID);
                BCStimGrid.RowCount = 16;
                for (int row = 0; row < 16; row++)
                {
                    double d = param[row*2];
                    BCStimGrid.Rows[row].Cells[0].Value = d.ToString();
                    d = param[row*2+1];
                    BCStimGrid.Rows[row].Cells[1].Value = d.ToString();
                }
                //if (checkBoxBCNewsome.Checked)
                //    BCStimGrid.RowCount = 1;

            }

            done += 1f;
            this.toolStripProgressBar1.Value = (int)(100f * done / total);

            // Bump follow stimulation table
            paramID = target.GetParamIdx("BFStimTable", "table");
            if (paramID != -1) {
                param = (double[])target.GetParam(paramID);
                for (int row = 0; row < 16; row++) {
                    double d = param[row * 2];
                    BFStimGrid.Rows[row].Cells[0].Value = d.ToString();
                    d = param[row * 2 + 1];
                    BFStimGrid.Rows[row].Cells[1].Value = d.ToString();
                }
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
                } else {
                    paramValue = 0;
                }

                d.Add(key, paramValue);
            }

            bp.Parameters = d;

            // Fixed params
            bp.Load = (LoadType)this.comboBoxLoad.SelectedIndex;
            bp.LoadCatch = (LoadType)this.comboBoxLoadCatch.SelectedIndex;
            if (this.radioButtonBump.Checked) {
                bp.CenterOutMode = CenterOutMode.Bump;
            } else if (this.radioButtonCatch.Checked) {
                bp.CenterOutMode = CenterOutMode.Catch;
            } else {
                bp.CenterOutMode = CenterOutMode.None;
                bp.Parameters["Catch Trials Pct"] = 0;
            }

            #region BD_Catch
            switch ((BD_Catch_Index)this.comboBoxBDCT.SelectedIndex)
            {   //set length of block of trials based on catch %
                case BD_Catch_Index.None:
                    bp.BD_Catch_Block = (int)BD_Catch_List.None;
                    break;
                case BD_Catch_Index.pct5:
                    bp.BD_Catch_Block = (int)BD_Catch_List.pct5;
                    break;
                case BD_Catch_Index.pct10:
                    bp.BD_Catch_Block = (int)BD_Catch_List.pct10;
                    break;
                case BD_Catch_Index.pct14:
                    bp.BD_Catch_Block = (int)BD_Catch_List.pct14;
                    break;
                case BD_Catch_Index.pct20:
                    bp.BD_Catch_Block = (int)BD_Catch_List.pct20;
                    break;
                case BD_Catch_Index.pct25:
                    bp.BD_Catch_Block = (int)BD_Catch_List.pct25;
                    break;
                case BD_Catch_Index.pct33:
                    bp.BD_Catch_Block = (int)BD_Catch_List.pct33;
                    break;
                default:
                    bp.BD_Catch_Block = (int)BD_Catch_List.None;
                    break;
            }
            #endregion

            // MG-TargetList
            for (int i = 0; i < MGTargetGrid.Rows.Count; i++) {
                DataGridViewCellCollection cells = MGTargetGrid.Rows[i].Cells;
                MultiGadgetTarget mgt = new MultiGadgetTarget();
                mgt.TgtYPos = (cells[1].Value == null ? 0.0 : Double.Parse(cells[1].Value.ToString()));
                mgt.TgtHeight = (cells[2].Value == null ? 0.0 : Double.Parse(cells[2].Value.ToString()));
                mgt.TgtXPos = (cells[3].Value == null ? 0.0 : Double.Parse(cells[3].Value.ToString()));
                mgt.TgtWidth = (cells[4].Value == null ? 0.0 : Double.Parse(cells[4].Value.ToString()));
                mgt.yVar_enable = (cells[5].Value == null ? 0 : Int16.Parse(cells[5].Value.ToString()));
                bp.MGTargets[i] = mgt;
            }

            //MG-Gains
            double[] mgg = {Double.Parse(this.MGGain0.Text),
                                Double.Parse(this.MGGain1.Text),
                                Double.Parse(this.MGGain2.Text),
                                Double.Parse(this.MGGain3.Text)};
            bp.MGGains = mgg;
     
            // WF-TargetList
            for (int i = 0; i < WFTargetGrid.Rows.Count; i++) {
                DataGridViewCellCollection cells = WFTargetGrid.Rows[i].Cells;
                MultiGadgetTarget wft = new MultiGadgetTarget();
                wft.TgtYPos = (cells[1].Value == null ? 0.0 : Double.Parse(cells[1].Value.ToString()));
                wft.TgtHeight = (cells[2].Value == null ? 0.0 : Double.Parse(cells[2].Value.ToString()));
                wft.TgtXPos = (cells[3].Value == null ? 0.0 : Double.Parse(cells[3].Value.ToString()));
                wft.TgtWidth = (cells[4].Value == null ? 0.0 : Double.Parse(cells[4].Value.ToString()));
                wft.xVar_enable = (cells[5].Value == null ? 0 : Int16.Parse(cells[5].Value.ToString()));
                wft.yVar_enable = (cells[6].Value == null ? 0 : Int16.Parse(cells[6].Value.ToString()));
                bp.WFTargets[i] = wft;
            }

            // BCStimGrid
            for (int i = 0; i < BCStimGrid.Rows.Count; i++)
            {
                DataGridViewCellCollection cells = BCStimGrid.Rows[i].Cells;
                BumpChoiceStim bcs = new BumpChoiceStim();
                bcs.StimCodeVar = Int16.Parse(cells[0].Value.ToString());
                bcs.PDVar = Double.Parse(cells[1].Value.ToString());
                bp.BCStims[i] = bcs;
            }

            // BFStimGrid
            for (int i = 0; i < BFStimGrid.Rows.Count; i++) {
                DataGridViewCellCollection cells = BFStimGrid.Rows[i].Cells;
                BumpChoiceStim bfs = new BumpChoiceStim();
                bfs.StimCodeVar = Int16.Parse(cells[0].Value.ToString());
                bfs.PDVar = Double.Parse(cells[1].Value.ToString());
                bp.BFStims[i] = bfs;
            }

            // GlyphSet
            bp.GlyphSet = this.comboBoxGlyphSelect.SelectedIndex;

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
            if (bp.CenterOutMode == CenterOutMode.Bump) {
                this.radioButtonBump.Checked = true;
            } else if (bp.CenterOutMode == CenterOutMode.Catch) {
                this.radioButtonCatch.Checked = true;
            } else {
                this.radioButtonNoBump.Checked = true;
            }

            #region BD_Catch
            switch ((BD_Catch_List)bp.BD_Catch_Block)
            {   //length of block of trials based on catch %
                case BD_Catch_List.None:
                    this.comboBoxBDCT.SelectedIndex = 0;
                    break;
                case BD_Catch_List.pct5:
                    this.comboBoxBDCT.SelectedIndex = 1;
                    break;
                case BD_Catch_List.pct10:
                    this.comboBoxBDCT.SelectedIndex = 2;
                    break;
                case BD_Catch_List.pct14:
                    this.comboBoxBDCT.SelectedIndex = 3;
                    break;
                case BD_Catch_List.pct20:
                    this.comboBoxBDCT.SelectedIndex = 4;
                    break;
                case BD_Catch_List.pct25:
                    this.comboBoxBDCT.SelectedIndex = 5;
                    break;
                case BD_Catch_List.pct33:
                    this.comboBoxBDCT.SelectedIndex = 6;
                    break;
                default:
                    this.comboBoxBDCT.SelectedIndex = 0;
                    break;
            }
            #endregion

            // Host Parameters
            this.textBoxScreenWidth.Text = bp.ScreenWidth.ToString();
            this.textBoxVerticalDisplacement.Text = bp.VerticalDisplacement.ToString();
            this.comboBoxCursor.SelectedIndex = bp.Cursor;
            this.comboBoxGlyphSelect.SelectedIndex = bp.GlyphSet;
            
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
                    }
                } catch (KeyNotFoundException) {
                }
            }

            // MultiGadget Target Parameters
            for (int i = 0; i < MGTargetGrid.RowCount; i++) {
                DataGridViewCellCollection cells = MGTargetGrid.Rows[i].Cells;
                MultiGadgetTarget mgt = bp.MGTargets[i];
                if (mgt.TgtHeight == 0 && mgt.TgtWidth == 0) {
                    cells[1].Value = null;
                    cells[2].Value = null;
                    cells[3].Value = null;
                    cells[4].Value = null;
                } else {
                    cells[1].Value = mgt.TgtYPos.ToString();
                    cells[2].Value = mgt.TgtHeight.ToString();
                    cells[3].Value = mgt.TgtXPos.ToString();
                    cells[4].Value = mgt.TgtWidth.ToString();
                }
                cells[5].Value = mgt.yVar_enable;
            }

            //MultiGadget Gain
            this.MGGain0.Text = bp.MGGains[0].ToString();
            this.MGGain1.Text = bp.MGGains[1].ToString();
            this.MGGain2.Text = bp.MGGains[2].ToString();
            this.MGGain3.Text = bp.MGGains[3].ToString();

            // Wrist Flexion Target Parameters
            for (int i = 0; i < WFTargetGrid.RowCount; i++) {
                DataGridViewCellCollection cells = WFTargetGrid.Rows[i].Cells;
                MultiGadgetTarget wft = bp.WFTargets[i];
                if (wft.TgtHeight == 0 && wft.TgtWidth == 0) {
                    cells[1].Value = null;
                    cells[2].Value = null;
                    cells[3].Value = null;
                    cells[4].Value = null;
                } else {
                    cells[1].Value = wft.TgtYPos.ToString();
                    cells[2].Value = wft.TgtHeight.ToString();
                    cells[3].Value = wft.TgtXPos.ToString();
                    cells[4].Value = wft.TgtWidth.ToString();
                }
                cells[5].Value = wft.xVar_enable;
                cells[6].Value = wft.yVar_enable;
            }

            // Bump choice stim list parameters
            for (int i = 0; i < BCStimGrid.RowCount; i++)
            {
                DataGridViewCellCollection cells = BCStimGrid.Rows[i].Cells;
                BumpChoiceStim bcs = bp.BCStims[i];
                cells[0].Value = bcs.StimCodeVar.ToString();
                cells[1].Value = bcs.PDVar.ToString();
            }

            // Bump follow stim list parameters
            for (int i = 0; i < BFStimGrid.RowCount; i++) {
                DataGridViewCellCollection cells = BFStimGrid.Rows[i].Cells;
                BumpChoiceStim bfs = bp.BFStims[i];
                cells[0].Value = bfs.StimCodeVar.ToString();
                cells[1].Value = bfs.PDVar.ToString();
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
            owner.SetGlyphSet(this.comboBoxGlyphSelect.SelectedIndex);
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
            paramID = target.GetParamIdx("TargetTable", "table");
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
             * MG Gains
             */
            paramID = target.GetParamIdx("CursorPos/GadgetGain", "table");
            if (paramID >= 0)
            {
                Array mgGains = Array.CreateInstance(typeof(double), 4);
                mgGains=bp.MGGains;
                target.SetParam(paramID, ref mgGains);
            }

            /*
            * WF Targets 
            */
            paramID = target.GetParamIdx("WFTargetTable", "table");
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
            paramID = target.GetParamIdx("BCStimTable", "table");
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
            paramID = target.GetParamIdx("BFStimTable", "table");
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

        private void checkBoxWFIntegrate_CheckedChanged(object sender, EventArgs e)
        {
            if (!checkBoxWFIntegrate.Checked) {
                textBoxWFIntMin.Hide();
                textBoxWFIntMax.Hide();
                labelWFIntMin.Hide();
                labelWFIntMax.Hide();
            } else {
                textBoxWFIntMin.Show();
                textBoxWFIntMax.Show();
                labelWFIntMin.Show();
                labelWFIntMax.Show();
            }
            widget_ValueChanged(sender, e);
        }

     
    }

}