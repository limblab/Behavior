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

            #region Defend Center

            AddParamListItem("DC Target Size", "P3", "Behavior Defend Center", textboxDC_target_size);
            AddParamListItem("DC Target Size Big", "P4", "Behavior Defend Center", textboxDC_target_size_big);
            AddParamListItem("DC Bump Magnitude", "P5", "Behavior Defend Center", textboxDC_bump_magnitude);
            AddParamListItem("DC Bump Duration", "P6", "Behavior Defend Center", textboxDC_bump_duration);
            AddParamListItem("DC Bump Ramp", "P7", "Behavior Defend Center", textboxDC_bump_ramp);
            AddParamListItem("DC Center Hold Time", "P8", "Behavior Defend Center", textboxDC_center_hold);
            AddParamListItem("DC Bump Delay Time", "P9", "Behavior Defend Center", textboxDC_bump_delay);
            AddParamListItem("DC Bump Delay Random", "P10", "Behavior Defend Center", textboxDC_bump_delay_rand);
            AddParamListItem("DC Bump Hold Time", "P11", "Behavior Defend Center", textboxDC_bump_hold_time);
            AddParamListItem("DC Inter Trial Time", "P12", "Behavior Defend Center", textboxDC_inter_trial_time);
            AddParamListItem("DC Hide Cursor", "P13", "Behavior Defend Center", checkboxDC_hide_cursor);
            AddParamListItem("DC Stim Prob", "P14", "Behavior Defend Center", textboxDC_stim_prob);
            AddParamListItem("DC Penalty Time", "P15", "Behavior Defend Center", textboxDC_penalty_time);
            AddParamListItem("DC Bump Floor", "P16", "Behavior Defend Center", textboxDC_bump_floor);
            AddParamListItem("DC Bump Ceiling", "P17", "Behavior Defend Center", textboxDC_bump_ceiling);
            AddParamListItem("DC Bump Increment", "P18", "Behavior Defend Center", textboxDC_bump_increment);
            AddParamListItem("DC Stim Levels", "P19", "Behavior Defend Center", textboxDC_stim_levels);

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
            AddParamListItem("Movement Bumps", "P19", "Behavior CO", this.checkBoxMovementBumps);
            AddParamListItem("Center Hold Bumps", "P20", "Behavior CO", this.checkBoxCHB);

            // Center-Out targets
            AddParamListItem("CO Num Targets", "P1", "Behavior CO", this.numericUpDownNumTgts);
            AddParamListItem("Target Radius", "P2", "Behavior CO", this.textBoxTgtRadius);
            AddParamListItem("Target Size", "P3", "Behavior CO", this.textBoxTgtSize);
            AddParamListItem("Idiot Mode", "P16", "Behavior CO", this.checkBoxIdiot);
            AddParamListItem("First Target Shift", "P21", "Behavior CO", this.angleEntryBox_CO_FTS);
            AddParamListItem("Default Target Range", "P22", "Behavior CO", this.angleEntryBox_CO_DTR);
            AddParamListItem("Bump Delay Low", "P23", "Behavior CO", this.textBoxBumpDelayLow);
            AddParamListItem("Bump Delay High", "P24", "Behavior CO", this.textBoxBumpDelayHigh);
            
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
            // Forced Choice Targets
            AddParamListItem("FC Target Size", "P3", "Behavior FC", this.textBoxFCTargetSize);
            AddParamListItem("FC Target Distance", "P4", "Behavior FC", this.textBoxFCTargetDistance);
            AddParamListItem("FC Target Angle", "P5", "Behavior FC", this.textBoxFCTargetAngle);
            AddParamListItem("FC Random Targets", "P6", "Behavior FC", this.checkBoxFCRandomTgt);
            AddParamListItem("FC Show During Bump", "P7", "Behavior FC", this.checkBoxFCShowTgts);
            //Bump parameters
            AddParamListItem("FC Bump Probability", "P8", "Behavior FC", this.textBoxFCBumpProb);
            AddParamListItem("FC Bump direction", "P9", "Behavior FC", this.textBoxFCBumpDirection);
            AddParamListItem("FC Bump magnitude floor", "P10", "Behavior FC", this.textBoxFCBumpMagFloor);
            AddParamListItem("FC Bump magnitude ceiling", "P11", "Behavior FC", this.textBoxFCBumpMagCeiling);
            AddParamListItem("FC Bump magnitude step", "P12", "Behavior FC", this.textBoxFCBumpMagStep);
            AddParamListItem("FC Bump duration", "P13", "Behavior FC", this.textBoxFCBumpDuration);
            AddParamListItem("FC Bump rise", "P14", "Behavior FC", this.textBoxFCBumpRamp);
            // Forced Choice Timing

            AddParamListItem("FC Center hold time", "P15", "Behavior FC", this.textBoxFCCtrHold);
            AddParamListItem("FC bump delay low", "P16", "Behavior FC", this.textBoxFCBumpDelayLow);
            AddParamListItem("FC bump delay high", "P17", "Behavior FC", this.textBoxFCBumpDelayHigh);
            AddParamListItem("FC bump hold", "P18", "Behavior FC", this.textBoxFCBumpHold);
            AddParamListItem("FC reaction time", "P19", "Behavior FC", this.textBoxFCReactionTime);

            AddParamListItem("FC intertrial", "P20", "Behavior FC", this.textBoxFCIntertrial);

            AddParamListItem("FC Penalty", "P21", "Behavior FC", this.textBoxFCPenaltyTime);
            //Cursor parameters
            AddParamListItem("FC Hide Cursor During Bump", "P22", "Behavior FC", this.checkBoxFCHideCursorDuringBumps);
            AddParamListItem("FC Recenter Cursor After Bump", "P23", "Behavior FC", this.checkBoxFCRecenterAfterBumps);
            // Stimulation Parameters
            AddParamListItem("FC Stim Probability", "P24", "Behavior FC", this.textBoxFCStimProb);
            AddParamListItem("FC Num Stim Levels", "P25", "Behavior FC", this.textBoxFCStimLevels);
            // Misc
            AddParamListItem("FC Training frequency", "P26", "Behavior FC", this.textBoxFCTrainingTrialFreq);
            AddParamListItem("FC Abort During Bump", "P27", "Behavior FC", this.checkBoxFCAbortDuringBumps);
            AddParamListItem("FC Force Reaction", "P28", "Behavior FC", this.checkBoxFCForceReactionTime);
            AddParamListItem("FC Use Staircase", "P29", "Behavior FC", this.checkBoxFCUseStaircase);
            AddParamListItem("FC Stim Code Low", "P30", "Behavior FC", this.textBoxFCStimCodeLow);
            
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
            //AddParamListItem("MGGains", "Table", "CursorPos/GadgetGains", MGGains);
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
            AddParamListItem("WFI", "P5", "Behavior WF", this.textBoxWFI);
            AddParamListItem("WFCDL", "P10", "Behavior WF", this.textBoxWFCDL);
            AddParamListItem("WFCDH", "P11", "Behavior WF", this.textBoxWFCDH);
            AddParamListItem("WFCHH", "P20", "Behavior WF", this.textBoxWFCHH);

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
            AddParamListItem("WFNeuralControlCatchTrial", "P21", "Behavior WF", this.radioButtonWFCTNC);

            // Ramp of catch trials
            AddParamListItem("WFCatchTrialRamp", "P22", "Behavior WF", this.checkBoxWFCTRamp);
            AddParamListItem("WFCatchTrialSlope", "P23", "Behavior WF", this.textBoxWFCTSlope);
            AddParamListItem("WFAdapCatchTrials", "P24", "Behavior WF", this.WFckboxAdaptCatch);


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

            AddParamListItem("BC fast abort", "P36", "Behavior BC", this.checkBoxBCFA);

            AddParamListItem("BC post stim delay", "P37", "Behavior BC", this.textBoxBCPSD);
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

            #region Uncertainty1D
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
            AddParamListItem("Un Disp Std", "P16", "Behavior Un1d", this.textBoxUDispStd);
            AddParamListItem("Un Block Win Start", "P17", "Behavior Un1d", this.textBoxUBlockWinStart);
            AddParamListItem("Un Block Win End", "P18", "Behavior Un1d", this.textBoxUBlockWinEnd);

            // Uncertainty Feedback Parameters
            AddParamListItem("Un Cloud Std", "P19", "Behavior Un1d", this.textBoxUFbStd);
            AddParamListItem("Un Cloud Std 2", "P20", "Behavior Un1d", this.textBoxUFbStd2);
            AddParamListItem("Un Cloud Std 3", "P21", "Behavior Un1d", this.textBoxUFbStd3);
            AddParamListItem("Un Cloud Std 4", "P22", "Behavior Un1d", this.textBoxUFbStd4);

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

            AddParamListItem("Un Max Speed Threshold", "P35", "Behavior Un1d", this.textBoxUMaxSpeedThreshold);
            AddParamListItem("Un Center Offset X", "P36", "Behavior Un1d", this.textBoxUCenterOffsetX);
            AddParamListItem("Un Center Offset Y", "P37", "Behavior Un1d", this.textBoxUCenterOffsetY);
            AddParamListItem("Un Training Feedback Mode", "P38", "Behavior Un1d", this.checkBoxUTrainingFeedbackMode);
            AddParamListItem("Un Toggle Cloud 1D", "P39", "Behavior Un1d", this.checkBoxUToggleCloud1D);
            AddParamListItem("Un 1D Cloud Jitter", "P40", "Behavior Un1d", this.textBoxUJitterValue);


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
            AddParamListItem("2AFC Center Hold Low", "P3", "Behavior 2AFC", this.textBox2AFC_centerHoldLow);
            AddParamListItem("2AFC Center Hold High", "P4", "Behavior 2AFC", this.textBox2AFC_centerHoldHigh);
            AddParamListItem("2AFC Delay Period Low", "P5", "Behavior 2AFC", this.textBox2AFC_delayPeriodLow);
            AddParamListItem("2AFC Delay Period High", "P6", "Behavior 2AFC", this.textBox2AFC_delayPeriodHigh);
            AddParamListItem("2AFC Movement Time", "P7", "Behavior 2AFC", this.textBox2AFC_moveTime);
            AddParamListItem("2AFC Target Hold Low", "P8", "Behavior 2AFC", this.textBox2AFC_targetHoldLow);
            AddParamListItem("2AFC Target Hold High", "P9", "Behavior 2AFC", this.textBox2AFC_targetHoldHigh);
            AddParamListItem("2AFC Bump Delay Time", "P10", "Behavior 2AFC", this.textBox2AFC_bumpDelayTime);
            AddParamListItem("2AFC Bump Hold Time", "P11", "Behavior 2AFC", this.textBox2AFC_bumpHoldTime);
            AddParamListItem("2AFC Intertrial Time", "P12", "Behavior 2AFC", this.textBox2AFC_intertrialTime);
            AddParamListItem("2AFC Penalty Time", "P13", "Behavior 2AFC", this.textBox2AFC_penaltyTime);
            
            AddParamListItem("2AFC Target Size", "P14", "Behavior 2AFC", this.textBox2AFC_targetSize);
            AddParamListItem("2AFC Target Radius", "P15", "Behavior 2AFC", this.textBox2AFC_targetRadius);
            AddParamListItem("2AFC Target Angle", "P16", "Behavior 2AFC", this.textBox2AFC_targetAngle);
            AddParamListItem("2AFC Hide Cursor", "P17", "Behavior 2AFC", this.checkBox2AFC_hideCursor);
            AddParamListItem("2AFC Abort During Bump", "P18", "Behavior 2AFC", this.checkBox2AFC_abortDuringBump);
            
            AddParamListItem("2AFC Cue 1 Bump Dir", "P19", "Behavior 2AFC", this.textBox2AFC_cue1BumpDir);
            AddParamListItem("2AFC Cue 2 Bump Dir", "P20", "Behavior 2AFC", this.textBox2AFC_cue2BumpDir);

            AddParamListItem("2AFC Bump Peak Time", "P21", "Behavior 2AFC", this.textBox2AFC_bumpPeakTime);
            AddParamListItem("2AFC Bump Ramp Time", "P22", "Behavior 2AFC", this.textBox2AFC_bumpRampTime);
            AddParamListItem("2AFC Bump Magnitude", "P23", "Behavior 2AFC", this.textBox2AFC_bumpMagnitude);

            AddParamListItem("2AFC Cue 1 Stim Prob", "P24", "Behavior 2AFC", this.textBox2AFC_cue1StimProb);
            AddParamListItem("2AFC Cue 1 Stim Level Low", "P25", "Behavior 2AFC", this.textBox2AFC_cue1StimCodeLow);
            AddParamListItem("2AFC Cue 1 Stim Level High", "P26", "Behavior 2AFC", this.textBox2AFC_cue1StimLevelHigh);

            AddParamListItem("2AFC Cue 2 Stim Prob", "P27", "Behavior 2AFC", this.textBox2AFC_cue2StimProb);
            AddParamListItem("2AFC Cue 2 Stim Level Low", "P28", "Behavior 2AFC", this.textBox2AFC_cue2StimLevelLow);
            AddParamListItem("2AFC Cue 2 Stim Level High", "P29", "Behavior 2AFC", this.textBox2AFC_cue2StimLevelHigh);

            AddParamListItem("2AFC Same Cue Prob", "P30", "Behavior 2AFC", this.textBox2AFC_sameCueProb);

            AddParamListItem("2AFC Period Duration", "P31", "Behavior 2AFC", this.textBox2AFC_periodDuration);
            AddParamListItem("2AFC Interperiod Duration", "P32", "Behavior 2AFC", this.textBox2AFC_interperiodDuration);

            AddParamListItem("2AFC Same Target Right", "P33", "Behavior 2AFC", this.checkBox2AFC_sameTargetRight);
            AddParamListItem("2AFC Idiot Mode", "P34", "Behavior 2AFC", this.checkBox2AFC_idiotMode);
            AddParamListItem("2AFC Big Target Size", "P35", "Behavior 2AFC", this.textBox2AFC_bigTargetSize);

            AddParamListItem("2AFC Training Trial Frequency", "P36", "Behavior 2AFC", this.textBox2AFC_trainingTrialFrequency);

            #endregion

            #region Attention
            /* 
             * Attention Parameters 
             */
            
            // Timing
            AddParamListItem("AT CHL", "P2", "Behavior AT", this.textBoxATCHL);
            AddParamListItem("AT CHH", "P3", "Behavior AT", this.textBoxATCHH);            
            AddParamListItem("AT M", "P4", "Behavior AT", this.textBoxATM);
            AddParamListItem("AT RW", "P5", "Behavior AT", this.textBoxATRW);
            AddParamListItem("AT FW", "P6", "Behavior AT", this.textBoxATFW);
            AddParamListItem("AT AW", "P7", "Behavior AT", this.textBoxATAW);
            
            // Targets
            AddParamListItem("AT TS", "P8", "Behavior AT", this.textBoxATTS);
            AddParamListItem("AT TR", "P9", "Behavior AT", this.textBoxATTR);           
            
            // Trial types
            AddParamListItem("AT PVT", "P10", "Behavior AT", this.textBoxATPVT);
            AddParamListItem("AT PPT", "P11", "Behavior AT", this.textBoxATPPT);
            AddParamListItem("AT TBS", "P12", "Behavior AT", this.textBoxATTBS);
            AddParamListItem("AT PTT", "P13", "Behavior AT", this.textBoxATPTT);
            AddParamListItem("AT PCT", "P14", "Behavior AT", this.textBoxATPCT);
            AddParamListItem("AT BDirs", "P15", "Behavior AT", this.checkBoxATBDirs);
            AddParamListItem("AT BDiff", "P16", "Behavior AT", this.checkBoxATBDiff);
            AddParamListItem("AT NumDirs", "P17", "Behavior AT", this.numericUpDownATND);
            AddParamListItem("AT FMD", "P18", "Behavior AT", this.angleEntryBoxATFMD);

            // Moving dots
            AddParamListItem("AT MDD", "P19", "Behavior AT", this.textBoxATMDD);
            AddParamListItem("AT MDTS", "P20", "Behavior AT", this.textBoxATMDTS);
            AddParamListItem("AT MDC", "P21", "Behavior AT", this.textBoxATMDC);
            AddParamListItem("AT MDS", "P22", "Behavior AT", this.textBoxATMDS);
            AddParamListItem("AT MDND", "P23", "Behavior AT", this.textBoxATMDND);
            AddParamListItem("AT MDDR", "P24", "Behavior AT", this.textBoxATMDDR);
            AddParamListItem("AT MDMT", "P25", "Behavior AT", this.checkBoxATMDMT);
            AddParamListItem("AT MDEMinS", "P26", "Behavior AT", this.angleEntryBoxATMDEMinS);
            AddParamListItem("AT MDEMaxS", "P27", "Behavior AT", this.angleEntryBoxATMDEMaxS);
            AddParamListItem("AT MDNS", "P28", "Behavior AT", this.numericUpDownATMDNS);
            AddParamListItem("AT MDHMinS", "P29", "Behavior AT", this.angleEntryBoxATMDHMinS);
            AddParamListItem("AT MDHMaxS", "P30", "Behavior AT", this.angleEntryBoxATMDHMaxS);

            // Bumps
            AddParamListItem("AT BDur", "P31", "Behavior AT", this.textBoxATBD);            
            AddParamListItem("AT BNS", "P32", "Behavior AT", this.numericUpDownATBNS);
            AddParamListItem("AT BEMinS", "P33", "Behavior AT", this.angleEntryBoxATBEMinS);
            AddParamListItem("AT BEMaxS", "P34", "Behavior AT", this.angleEntryBoxATBEMaxS);
            AddParamListItem("AT BHMinS", "P35", "Behavior AT", this.angleEntryBoxATBHMinS);
            AddParamListItem("AT BHMaxS", "P36", "Behavior AT", this.angleEntryBoxATBHMaxS);
            AddParamListItem("AT BMag", "P37", "Behavior AT", this.textBoxATBM);
            
            // Staircases
            AddParamListItem("AT S", "P38", "Behavior AT", this.checkBoxATS);
            AddParamListItem("AT SR", "P39", "Behavior AT", this.numericUpDownATSR);
            
            // Bias force
            AddParamListItem("AT BFM", "P40", "Behavior AT", this.textBoxATBFM);
            AddParamListItem("AT BFD", "P41", "Behavior AT", this.textBoxATBFD);
            AddParamListItem("AT BFR", "P42", "Behavior AT", this.textBoxATBFR);  

            // More training stuff
            AddParamListItem("AT PTS", "P43", "Behavior AT", this.textBoxATPTS);
            AddParamListItem("AT CC", "P44", "Behavior AT", this.checkBoxATCC);

            // Velocity bump stuff            
            AddParamListItem("AT PGV", "P45", "Behavior AT", this.textBoxATPGV);
            AddParamListItem("AT PGP", "P46", "Behavior AT", this.textBoxATPGP);
            AddParamListItem("AT FB", "P47", "Behavior AT", this.checkBoxATFB);
            AddParamListItem("AT BV", "P48", "Behavior AT", this.textBoxATBV);
            AddParamListItem("AT VF", "P49", "Behavior AT", this.textBoxATVF);
            AddParamListItem("AT PF", "P50", "Behavior AT", this.textBoxATPF);

            // Recording stuff
            AddParamListItem("AT SRec", "P51", "Behavior AT", this.checkBoxRecord);
            AddParamListItem("AT RecFor", "P52", "Behavior AT", this.textBoxRecordFor);

            #endregion

            #region Bump direction psychophysics
            // Timing
            AddParamListItem("2BC CT Hold",                 "P10", "Behavior 2BC", textBox2BCCTH);
            AddParamListItem("2BC Bump Delay",              "P11", "Behavior 2BC", textBox2BC_bump_delay);
            AddParamListItem("2BC Bump Hold",               "P12", "Behavior 2BC", textBox2BCBH);
            AddParamListItem("2BC intertrial",              "P13", "Behavior 2BC", textBox2BCInt);
            AddParamListItem("2BC penalty",                 "P17", "Behavior 2BC", textBox2BCPenalty);
            AddParamListItem("2BC Recenter cursor",         "P18", "Behavior 2BC", checkBox2BCRecenter);

            // Bump
            AddParamListItem("2BC Bump Mag",                "P7", "Behavior 2BC", textBox2BCBA);
            AddParamListItem("2BC Bump Dur",                "P8", "Behavior 2BC", textBox2BCPD);
            AddParamListItem("2BC Bump RT",                 "P9", "Behavior 2BC", textBox2BCRT);
            AddParamListItem("2BC Rand Bump Floor",         "P23", "Behavior 2BC", textBox2BC_rand_bump_floor);
            AddParamListItem("2BC Rand Bump Ceil",          "P24", "Behavior 2BC", textBox2BC_rand_bump_ceil);
            AddParamListItem("2BC Bump Angle Increment",    "P26", "Behavior 2BC", textBox2BC_bump_incr);
            AddParamListItem("2BC Catch Rate",              "P28", "Behavior 2BC", textBox2BC_catch_rate);
            AddParamListItem("2BC Abort During Bump",       "P29", "Behavior 2BC", checkBox2BC_abort_during_bump);

            // Stim
            AddParamListItem("2BC Stim Prob",               "P16", "Behavior 2BC", textBox2BCStimProb);
            AddParamListItem("2BC Stim levels",             "P27", "Behavior 2BC", textBox2BC_stim_levels);

            // Targets
            AddParamListItem("2BC Targ Rad",                "P3", "Behavior 2BC", textBox2BCTR);
            AddParamListItem("2BC Targ Dist",               "P4", "Behavior 2BC", textBox2BCTD);
            AddParamListItem("2BC Targ Grow",               "P5", "Behavior 2BC", textBox2BCBTR);
            AddParamListItem("2BC Targ Ang",                "P6", "Behavior 2BC", angleEntryBox2BCAng);
            AddParamListItem("2BC Targ Green",              "P14", "Behavior 2BC", checkBox2BCGT);
            AddParamListItem("2BC Hide Cursor",             "P15", "Behavior 2BC", checkBox2BCHC);
            AddParamListItem("2BC Use Random Targets",      "P20","Behavior 2BC", checkBox2BC_rand_tgts);
            AddParamListItem("2BC Rand Targ Floor",         "P21", "Behavior 2BC", textBox2BC_rand_tgt_floor);
            AddParamListItem("2BC Rand Targ Ceil",          "P22", "Behavior 2BC", textBox2BC_rand_tgt_ceil);
            AddParamListItem("2BC show tgt during bump",    "P25", "Behavior 2BC", checkBox2BC_showtgt_bump);
            AddParamListItem("2BC training freq",           "P19", "Behavior 2BC", textBox2BC_training_freq);

            AddParamListItem("2BC number targets", "P30", "Behavior 2BC", textBox2BC_numTargets);
            AddParamListItem("2BC angle tolerance", "P31", "Behavior 2BC", textBox2BC_angle_tolerance);

            AddParamListItem("2BC use bump mapping", "P32", "Behavior 2BC", checkBox2BC_use_bump_mapping);
            AddParamListItem("2BC p1", "P33", "Behavior 2BC", textBox2BC_p1);
            AddParamListItem("2BC p2", "P34", "Behavior 2BC", textBox2BC_p2);
            AddParamListItem("2BC p3", "P35", "Behavior 2BC", textBox2BC_p3);
            AddParamListItem("2BC p4", "P36", "Behavior 2BC", textBox2BC_p4);
            AddParamListItem("2BC p5", "P37", "Behavior 2BC", textBox2BC_p5);
            AddParamListItem("2BC p6", "P38", "Behavior 2BC", textBox2BC_p6);
            AddParamListItem("2BC show ring prob", "P39", "Behavior 2BC", textBox2BC_show_ring_prob);
            AddParamListItem("2BC axis angle max", "P40", "Behavior 2BC", angleEntryBox2BCAngMax);
            AddParamListItem("2BC num axes", "P41", "Behavior 2BC", textBox2BC_num_axes);
            
            #endregion

            #region Stim Angle psychopysics
            //targets
            AddParamListItem("Stim Angle TS", "P3", "Behavior Stim Angle", textBox_SA_tgtSize);
            AddParamListItem("Stim Angle BT", "P4", "Behavior Stim Angle", textBox_SA_bigTarget);
            AddParamListItem("Stim Angle TR", "P5", "Behavior Stim Angle", textBox_SA_tgtRadius);

            //cursor
            AddParamListItem("Stim Angle HDB", "P6", "Behavior Stim Angle", checkBox_SA_hideDuringBump);
            AddParamListItem("Stim Angle RAB", "P7", "Behavior Stim Angle", checkBox_SA_recenterAfterBump);
            AddParamListItem("Stim Angle ADB", "P8", "Behavior Stim Angle", checkBox_SA_abortDuringBump);
            
            //Timing
            AddParamListItem("Stim Angle CTH", "P9", "Behavior Stim Angle", textBox_SA_CThold);
            AddParamListItem("Stim Angle BD", "P10", "Behavior Stim Angle", textBox_SA_bumpDelay);
            AddParamListItem("Stim Angle BH", "P11", "Behavior Stim Angle", textBox_SA_bumpHold);
            AddParamListItem("Stim Angle I", "P12", "Behavior Stim Angle", textBox_SA_intertrial);
            AddParamListItem("Stim Angle PT", "P13", "Behavior Stim Angle", textBox_SA_penaltyTime);

            //Control Bump
            AddParamListItem("Stim Angle CBPD", "P14", "Behavior Stim Angle", textBox_SA_controlBumpPeakDuration);
            AddParamListItem("Stim Angle CBRT", "P15", "Behavior Stim Angle", textBox_SA_controlBumpRiseTime);
            AddParamListItem("Stim Angle CBA", "P16", "Behavior Stim Angle", textBox_SA_controlBumpAmplitude);

            //Ref Bump
            AddParamListItem("Stim Angle RBPD", "P17", "Behavior Stim Angle", textBox_SA_refBumpPeakDuration);
            AddParamListItem("Stim Angle RBRT", "P18", "Behavior Stim Angle", textBox_SA_refBumpRiseTime);
            AddParamListItem("Stim Angle RBA", "P19", "Behavior Stim Angle", textBox_SA_refBumpAmplitude);

            //Electrodes
            AddParamListItem("Stim Angle SF", "P20", "Behavior Stim Angle", textBox_SA_stimFreq);
            AddParamListItem("Stim Angle UE1", "P21", "Behavior Stim Angle", checkBox_SA_useElec1);
            AddParamListItem("Stim Angle E1PD", "P22", "Behavior Stim Angle", textBox_SA_elec1PD);
            
            AddParamListItem("Stim Angle UE2", "P23", "Behavior Stim Angle", checkBox_SA_useElec2);
            AddParamListItem("Stim Angle E2PD", "P24", "Behavior Stim Angle", textBox_SA_elec2PD);

            AddParamListItem("Stim Angle UE3", "P25", "Behavior Stim Angle", checkBox_SA_useElec3);
            AddParamListItem("Stim Angle E3PD", "P26", "Behavior Stim Angle", textBox_SA_elec3PD);

            AddParamListItem("Stim Angle UE4", "P27", "Behavior Stim Angle", checkBoxSA_useElec4);
            AddParamListItem("Stim Angle E4PD", "P28", "Behavior Stim Angle", textBox_SA_elec4PD);

            AddParamListItem("Stim Angle UE5", "P29", "Behavior Stim Angle", checkBoxSA_useElec5);
            AddParamListItem("Stim Angle E5PD", "P30", "Behavior Stim Angle", textBox_SA_elec5PD);

            AddParamListItem("Stim Angle UE6", "P31", "Behavior Stim Angle", checkBoxSA_useElec6);
            AddParamListItem("Stim Angle E6PD", "P32", "Behavior Stim Angle", textBox_SA_elec6PD);

            AddParamListItem("Stim Angle UE7", "P33", "Behavior Stim Angle", checkBox_SA_useElec7);
            AddParamListItem("Stim Angle E7PD", "P34", "Behavior Stim Angle", textBox_SA_elec7PD);

            AddParamListItem("Stim Angle UE8", "P35", "Behavior Stim Angle", checkBox_SA_useElec8);
            AddParamListItem("Stim Angle E8PD", "P36", "Behavior Stim Angle", textBox_SA_elec8PD);

            //Staircases
            AddParamListItem("Stim Angle SS", "P37", "Behavior Stim Angle", textBox_SA_stepSize);
            AddParamListItem("Stim Angle CA", "P38", "Behavior Stim Angle", textBox_SA_centerAngle);
            AddParamListItem("Stim Angle UL", "P39", "Behavior Stim Angle", checkBox_SA_useLimits);
            AddParamListItem("Stim Angle RSC1", "P40", "Behavior Stim Angle", checkBox_SA_runSC1);
            AddParamListItem("Stim Angle SC1S", "P41", "Behavior Stim Angle", textBox_SA_SC1start);
            AddParamListItem("Stim Angle SC1R", "P42", "Behavior Stim Angle", textBox_SA_SC1ratio);
            AddParamListItem("Stim Angle SC1LL", "P43", "Behavior Stim Angle", textBox_SA_SC1lowlim);
            AddParamListItem("Stim Angle SC1HL", "P44", "Behavior Stim Angle", textBox_SA_SC1highlim);
            
            AddParamListItem("Stim Angle RSC2", "P45", "Behavior Stim Angle", checkBox_SA_runSC2);
            AddParamListItem("Stim Angle SC2S", "P46", "Behavior Stim Angle", textBox_SA_SC2start);
            AddParamListItem("Stim Angle SC2R", "P47", "Behavior Stim Angle", textBox_SA_SC2ratio);
            AddParamListItem("Stim Angle SC2LL", "P48", "Behavior Stim Angle", textBox_SA_SC2lowlim);
            AddParamListItem("Stim Angle SC2HL", "P49", "Behavior Stim Angle", textBox_SA_SC2highlim);

            AddParamListItem("Stim Angle RSC3", "P50", "Behavior Stim Angle", checkBox_SA_runSC3);
            AddParamListItem("Stim Angle SC3S", "P51", "Behavior Stim Angle", textBox_SA_SC3start);
            AddParamListItem("Stim Angle SC3R", "P52", "Behavior Stim Angle", textBox_SA_SC3ratio);
            AddParamListItem("Stim Angle SC3LL", "P53", "Behavior Stim Angle", textBox_SA_SC3lowlim);
            AddParamListItem("Stim Angle SC3HL", "P54", "Behavior Stim Angle", textBox_SA_SC3highlim);

            AddParamListItem("Stim Angle RSC4", "P55", "Behavior Stim Angle", checkBox_SA_runSC4);
            AddParamListItem("Stim Angle SC4S", "P56", "Behavior Stim Angle", textBox_SA_SC4start);
            AddParamListItem("Stim Angle SC4R", "P57", "Behavior Stim Angle", textBox_SA_SC4ratio);
            AddParamListItem("Stim Angle SC4LL", "P58", "Behavior Stim Angle", textBox_SA_SC4lowlim);
            AddParamListItem("Stim Angle SC4HL", "P59", "Behavior Stim Angle", textBox_SA_SC4highlim);

            #endregion

            #region CO Bump
            //basic trial timing
            AddParamListItem("COB ctr hold low",            "P3", "Behavior CO Bump", textBox_ctr_out_bump_CTHoldLow);
            AddParamListItem("COB ctr hold high",           "P4", "Behavior CO Bump", textBox_ctr_out_bump_CTHoldHigh);
            AddParamListItem("COB delay hold low",          "P5", "Behavior CO Bump", textBox_ctr_out_bump_DelayHoldLow);
            AddParamListItem("COB delay hold high",         "P6", "Behavior CO Bump", textBox_ctr_out_bump_DelayHoldHigh);
            AddParamListItem("COB move time",               "P7", "Behavior CO Bump", textBox_ctr_out_bump_MoveTime);
            AddParamListItem("COB target hold low",         "P8", "Behavior CO Bump", textBox_ctr_out_bump_targetHoldLow);
            AddParamListItem("COB terget hold high",        "P9", "Behavior CO Bump", textBox_ctr_out_bump_targetHoldHigh);
                        
            AddParamListItem("COB bump delay",              "P10", "Behavior CO Bump", textBox_ctr_out_bump_BumpDelay);
            AddParamListItem("COB bump hold",               "P11", "Behavior CO Bump", textBox_ctr_out_bump_BumpHold);
            AddParamListItem("COB intertrial",              "P12", "Behavior CO Bump", textBox_ctr_out_bump_intertrial);
            AddParamListItem("COB penalty time",            "P13", "Behavior CO Bump", textBox_ctr_out_bump_penalty);

            AddParamListItem("COB stim delay time", "P57", "Behavior CO Bump", textBox_ctr_out_bump_StimDelay);
            
            //target info
            AddParamListItem("COB target size",             "P14", "Behavior CO Bump", textBox_ctr_out_bump_TargetRadius);
            AddParamListItem("COB target distance min",           "P15", "Behavior CO Bump", textBox_ctr_out_bump_TargetDistanceMin);
            AddParamListItem("COB target angle",            "P16", "Behavior CO Bump", textBox_ctr_out_bump_targetAngle);
            AddParamListItem("COB target floor",            "P17", "Behavior CO Bump", textBox_ctr_out_bump_TargetAngleFloor);
            AddParamListItem("COB target ceiling",          "P18", "Behavior CO Bump", textBox_ctr_out_bump_TargetAngleCeiling);
            AddParamListItem("COB number targets",          "P19", "Behavior CO Bump", numericUpDown_ctr_out_bump_NumberTargets);
            AddParamListItem("COB use random targets",      "P20", "Behavior CO Bump", checkBox_ctr_out_bump_RandomTargets);
            //cursor info
            AddParamListItem("COB hide cursor",             "P21", "Behavior CO Bump", checkBox_ctr_out_bump_HideCursor);
            AddParamListItem("COB hide cursor radius min",  "P22", "Behavior CO Bump", textBox_ctr_out_bump_HideCursorRadiusMin);
            AddParamListItem("COB hide cursor radius max",  "P23", "Behavior CO Bump", textBox_ctr_out_bump_HideCursorRadiusMax);
            //bump info
            AddParamListItem("COB catch rate",              "P24", "Behavior CO Bump", textBox_ctr_out_bump_CatchRate);
            AddParamListItem("COB bi directional bumps",    "P25", "Behavior CO Bump", checkBox_ctr_out_bump_BiDirectionalBumps);
            AddParamListItem("COB abort during bump",       "P26", "Behavior CO Bump", checkBox_ctr_out_bump_AbortDuringBump);
            //center hold bump params
            AddParamListItem("COB CHBump flag",             "P27", "Behavior CO Bump", checkBox_ctr_out_bump_CHBump);
            AddParamListItem("COB CHBump rate",             "P28", "Behavior CO Bump", textBox_ctr_out_bump_CHBumpRate);
            AddParamListItem("COB CHbump dur",              "P29", "Behavior CO Bump", textBox_ctr_out_bump_CHPeakDuration);
            AddParamListItem("COB CHbump ramp",             "P30", "Behavior CO Bump", textBox_ctr_out_bump_CHRiseTime);
            AddParamListItem("COB CHbump mag",              "P31", "Behavior CO Bump", textBox_ctr_out_bump_CHAmplitude);
            AddParamListItem("COB CHbumpdir floor",         "P32", "Behavior CO Bump", textBox_ctr_out_bump_CHRandBumpFloor);
            AddParamListItem("COB CHbumpdir ceiling",       "P33", "Behavior CO Bump", textBox_ctr_out_bump_CHRandBumpCeiling);
            AddParamListItem("COB CHbump num dir",          "P34", "Behavior CO Bump", numericUpDown_ctr_out_bump_NumberCHBumpDirections);
                //delay bump params
            AddParamListItem("COB DPBump flag",             "P35", "Behavior CO Bump", checkBox_ctr_out_bump_DPBump);
            AddParamListItem("COB DPBump rate",             "P36", "Behavior CO Bump", textBox_ctr_out_bump_DPBumpRate);
            AddParamListItem("COB DPbump dur",              "P37", "Behavior CO Bump", textBox_ctr_out_bump_DPPeakDuration);
            AddParamListItem("COB DPbump ramp",             "P38", "Behavior CO Bump", textBox_ctr_out_bump_DPRiseTime);
            AddParamListItem("COB DPbump mag",              "P39", "Behavior CO Bump", textBox_ctr_out_bump_DPAmplitude);
            AddParamListItem("COB DPbumpdir floor",         "P40", "Behavior CO Bump", textBox_ctr_out_bump_DPRandBumpFloor);
            AddParamListItem("COB DPbumpdir ceiling",       "P41", "Behavior CO Bump", textBox_ctr_out_bump_DPRandBumpCeiling);
            AddParamListItem("COB DPbump num dir",          "P42", "Behavior CO Bump", numericUpDown_ctr_out_bump_NumberDPBumpDirections);
                //move bump params
            AddParamListItem("COB MBump flag",              "P43", "Behavior CO Bump", checkBox_ctr_out_bump_MBump);
            AddParamListItem("COB MBump rate",              "P44", "Behavior CO Bump", textBox_ctr_out_bump_MBumpRate);
            AddParamListItem("COB Mbump dur",               "P45", "Behavior CO Bump", textBox_ctr_out_bump_MPeakDuration);
            AddParamListItem("COB Mbump ramp",              "P46", "Behavior CO Bump", textBox_ctr_out_bump_MRiseTime);
            AddParamListItem("COB Mbump mag",               "P47", "Behavior CO Bump", textBox_ctr_out_bump_MAmplitude);
            AddParamListItem("COB Mbumpdir floor",          "P48", "Behavior CO Bump", textBox_ctr_out_bump_MRandBumpFloor);
            AddParamListItem("COB Mbumpdir ceiling",        "P49", "Behavior CO Bump", textBox_ctr_out_bump_MRandBumpCeiling);
            AddParamListItem("COB Mbumpdir incr",           "P50", "Behavior CO Bump", numericUpDown_ctr_out_bump_NumberMBumpDirections);
            //stim info
            AddParamListItem("COB stim prob",               "P51", "Behavior CO Bump", textBox_ctr_out_bump_StimProb);
            AddParamListItem("COB stim levels",             "P52", "Behavior CO Bump", textBox_ctr_out_bump_StimLevels);
            AddParamListItem("COB stim during bump", "P55", "Behavior CO Bump", checkBox_ctr_out_bump_StimDuringBump);
            AddParamListItem("COB stim instead of bump", "P56", "Behavior CO Bump", checkBox_ctr_out_bump_StimInsteadOfBump);

            //extra bump parameter
            AddParamListItem("COB use random bump time",    "P53", "Behavior CO Bump", checkBox_ctr_out_bump_randomBumpTime);
            AddParamListItem("COB target relative bumps",    "P54", "Behavior CO Bump", checkBox_ctr_out_bump_targetRelativeBumps);

            //idiot mode checkbox
            AddParamListItem("COB idiot mode", "P58", "Behavior CO Bump", checkBox_ctr_out_bump_idiotMode);


            AddParamListItem("COB target radius max", "P59", "Behavior CO Bump", textBox_ctr_out_bump_TargetDistanceMax);
            #endregion

            #region Unstable Field
            // Timing
            AddParamListItem("UF FRU", "P2", "Behavior UF", this.textBoxUFFRU);
            AddParamListItem("UF FHL", "P3", "Behavior UF", this.textBoxUFFHL);
            AddParamListItem("UF FHH", "P4", "Behavior UF", this.textBoxUFFHH);
            AddParamListItem("UF RW", "P5", "Behavior UF", this.textBoxUFRW);
            AddParamListItem("UF AW", "P6", "Behavior UF", this.textBoxUFAW);

            // Target and workspace
            AddParamListItem("UF TD", "P7", "Behavior UF", this.textBoxUFTD);
            AddParamListItem("UF WD", "P8", "Behavior UF", this.textBoxUFWD);

            // Unstable field
            AddParamListItem("UF NS", "P9", "Behavior UF", this.textBoxUFNS);
            AddParamListItem("UF PS", "P10", "Behavior UF", this.textBoxUFPS);
            AddParamListItem("UF FA", "P11", "Behavior UF", this.angleEntryBoxUFFFA);
            AddParamListItem("UF XPO", "P12", "Behavior UF", this.textBoxUFXPO);
            AddParamListItem("UF YPO", "P13", "Behavior UF", this.textBoxUFYPO);
            AddParamListItem("UF BFM", "P14", "Behavior UF", this.textBoxUFBFM);
            AddParamListItem("UF BFA", "P15", "Behavior UF", this.angleEntryBoxUFFBFA);

            // Bumps
            AddParamListItem("UF BD", "P16", "Behavior UF", this.textBoxUFBD);
            AddParamListItem("UF BV", "P17", "Behavior UF", this.textBoxUFBV);
            AddParamListItem("UF ND", "P18", "Behavior UF", this.numericUpDownUFND);
            AddParamListItem("UF FD", "P19", "Behavior UF", this.angleEntryBoxUFFD);

            // Unstable field again
            AddParamListItem("UF NO", "P20", "Behavior UF", this.numericUpDownUFNO);
            AddParamListItem("UF FBL", "P21", "Behavior UF", this.textBoxUFFBL);

            // Force target
            AddParamListItem("UF FTD", "P22", "Behavior UF", this.textBoxUFFTD);

            // Velocity bump controller
            AddParamListItem("UF PG", "P23", "Behavior UF", this.textBoxUFPG);
            AddParamListItem("UF DR", "P24", "Behavior UF", this.textBoxUFDR);
            AddParamListItem("UF M", "P25", "Behavior UF", this.textBoxUFM);
            AddParamListItem("UF PGP", "P26", "Behavior UF", this.textBoxUFPGP);

            //Field damping
            AddParamListItem("UF FDamp", "P27", "Behavior UF", this.textBoxUFFDamp);

            // Bump type
            AddParamListItem("UF BType", "P28", "Behavior UF", this.checkBoxUFFB);
            AddParamListItem("UF BMag", "P29", "Behavior UF", this.textBoxUFBM);

            // More bias force stuff
            AddParamListItem("UF NBF", "P30", "Behavior UF", this.numericUpDownUFNBFA);
            AddParamListItem("UF BAS", "P31", "Behavior UF", this.angleEntryBoxUFBAS);

            // More bump stuff
            AddParamListItem("UF IBD", "P32", "Behavior UF", this.textBoxUFIBD);

            // More field stuff
            AddParamListItem("UF VF", "P33", "Behavior UF", this.textBoxUFVF);
            AddParamListItem("UF PF", "P34", "Behavior UF", this.textBoxUFPF);

            // Recording stuff
            AddParamListItem("UF SRec", "P35", "Behavior UF", this.checkBoxRecord);
            AddParamListItem("UF RecFor", "P36", "Behavior UF", this.textBoxRecordFor);

            // Cursor stuff
            AddParamListItem("UF PC", "P37", "Behavior UF", this.checkBoxUFPC);

            // More target stuff
            AddParamListItem("UF LTH", "P38", "Behavior UF", this.checkBoxUFLTH);
            AddParamListItem("UF LTD", "P39", "Behavior UF", this.textBoxUFLTD);
            AddParamListItem("UF MBH", "P40", "Behavior UF", this.textBoxUFMBH);

            // Stiff trials
            AddParamListItem("UF ST", "P41", "Behavior UF", this.checkBoxUFST);
            #endregion

            #region UncertaintyTarget1D
            /* 
             * UncertaintyTarget1D Parameters 
             */

            // Timing
            AddParamListItem("UT1D CHL", "P2", "Behavior UnTarget1d", this.textBoxUT1DCHL);
            AddParamListItem("UT1D CHH", "P3", "Behavior UnTarget1d", this.textBoxUT1DCHH);
            AddParamListItem("UT1D DL",  "P4", "Behavior UnTarget1d", this.textBoxUT1DDL);
            AddParamListItem("UT1D DH",  "P5", "Behavior UnTarget1d", this.textBoxUT1DDH);
            AddParamListItem("UT1D OHL", "P6", "Behavior UnTarget1d", this.textBoxUT1DOHL);
            AddParamListItem("UT1D OHH", "P7", "Behavior UnTarget1d", this.textBoxUT1DOHH);
            AddParamListItem("UT1D ITI", "P8", "Behavior UnTarget1d", this.textBoxUT1DITI);
            AddParamListItem("UT1D MT",  "P9", "Behavior UnTarget1d", this.textBoxUT1DMT);
            AddParamListItem("UT1D FLT", "P10", "Behavior UnTarget1d", this.textBoxUT1DFLT);

            // Uncertainty General Settings
            AddParamListItem("UT1D Target Angle", "P11", "Behavior UnTarget1d", this.numericUpDownUT1DTargetAngle);
            AddParamListItem("UT1D Movement Length", "P12", "Behavior UnTarget1d", this.textBoxUT1DMovementLen);
            AddParamListItem("UT1D Target Diameter", "P13", "Behavior UnTarget1d", this.textBoxUT1DTargetSize);
            AddParamListItem("UT1D Center X Offset", "P14", "Behavior UnTarget1d", this.textBoxUT1DCenterXOffset);
            AddParamListItem("UT1D Center Y Offset", "P15", "Behavior UnTarget1d", this.textBoxUT1DCenterYOffset);

            // Uncertainty Target Shift Parameters
            AddParamListItem("UT1D Shift Mean", "P16", "Behavior UnTarget1d", this.textBoxUT1DShiftMean);
            AddParamListItem("UT1D Shift Stdev", "P17", "Behavior UnTarget1d", this.textBoxUT1DShiftStdev);
            AddParamListItem("UT1D Block Window Start", "P18", "Behavior UnTarget1d", this.textBoxUT1DBlockWindowStart);
            AddParamListItem("UT1D Block Window End", "P19", "Behavior UnTarget1d", this.textBoxUT1DBlockWindowEnd);

            // Uncertainty Target Cloud Parameters
            AddParamListItem("UT1D Cloud 1 Stdev", "P20", "Behavior UnTarget1d", this.textBoxUT1DCloud1Stdev);
            AddParamListItem("UT1D Cloud 2 Stdev", "P21", "Behavior UnTarget1d", this.textBoxUT1DCloud2Stdev);
            AddParamListItem("UT1D Cloud 3 Stdev", "P22", "Behavior UnTarget1d", this.textBoxUT1DCloud3Stdev);
            AddParamListItem("UT1D Cloud 4 Stdev", "P23", "Behavior UnTarget1d", this.textBoxUT1DCloud4Stdev);

            AddParamListItem("UT1D Cloud 1 Freq", "P24", "Behavior UnTarget1d", this.textBoxUT1DCloud1Freq);
            AddParamListItem("UT1D Cloud 2 Freq", "P25", "Behavior UnTarget1d", this.textBoxUT1DCloud2Freq);
            AddParamListItem("UT1D Cloud 3 Freq", "P26", "Behavior UnTarget1d", this.textBoxUT1DCloud3Freq);
            AddParamListItem("UT1D Cloud 4 Freq", "P27", "Behavior UnTarget1d", this.textBoxUT1DCloud4Freq);

            AddParamListItem("UT1D Cloud 1 Blank",  "P28", "Behavior UnTarget1d", this.checkBoxUT1DCloud1Blank);

            AddParamListItem("UT1D Slice Size",     "P29", "Behavior UnTarget1d", this.textBoxUT1DSliceSize);
            AddParamListItem("UT1D Slice Number",   "P30", "Behavior UnTarget1d", this.numericUpDownUT1DSliceNumber);
            AddParamListItem("UT1D Feedback Start", "P31", "Behavior UnTarget1d", this.textBoxUT1DFeedbackStart);
            AddParamListItem("UT1D Feedback End",   "P32", "Behavior UnTarget1d", this.textBoxUT1DFeedbackEnd);

            AddParamListItem("UT1D Cloud Jitter", "P33", "Behavior UnTarget1d", this.textBoxUT1DCloudJitter);

            AddParamListItem("UT1D Use Timed", "P34", "Behavior UnTarget1d", this.checkBoxUT1DUseTimed);
            AddParamListItem("UT1D Timed Duration", "P35", "Behavior UnTarget1d", this.textBoxUT1DTimedDuration);
            AddParamListItem("UT1D Timed Location", "P36", "Behavior UnTarget1d", this.textBoxUT1DTimedLocation);
            AddParamListItem("UT1D Target Delay Mode", "P37", "Behavior UnTarget1d", this.checkBoxUT1DTargetDelayMode);

            #endregion

            #region UncertaintyTarget2D
            /* 
             * UncertaintyTarget2D Parameters 
             */

            // Timing
            AddParamListItem("UT2D CHL", "P2", "Behavior UnTarget2d", this.textBoxUT2DCHL);
            AddParamListItem("UT2D CHH", "P3", "Behavior UnTarget2d", this.textBoxUT2DCHH);
            AddParamListItem("UT2D DL", "P4", "Behavior UnTarget2d", this.textBoxUT2DDL);
            AddParamListItem("UT2D DH", "P5", "Behavior UnTarget2d", this.textBoxUT2DDH);
            AddParamListItem("UT2D OHL", "P6", "Behavior UnTarget2d", this.textBoxUT2DOHL);
            AddParamListItem("UT2D OHH", "P7", "Behavior UnTarget2d", this.textBoxUT2DOHH);
            AddParamListItem("UT2D ITI", "P8", "Behavior UnTarget2d", this.textBoxUT2DITI);
            AddParamListItem("UT2D MT", "P9", "Behavior UnTarget2d", this.textBoxUT2DMT);
            AddParamListItem("UT2D FLT", "P10", "Behavior UnTarget2d", this.textBoxUT2DFLT);

            // Uncertainty General Settings
            AddParamListItem("UT2D Outer Target Size", "P11", "Behavior UnTarget2d", this.textBoxUT2DOTSize);
            AddParamListItem("UT2D Movement Length", "P12", "Behavior UnTarget2d", this.textBoxUT2DMovementLen);
            AddParamListItem("UT2D Target Diameter", "P13", "Behavior UnTarget2d", this.textBoxUT2DTargetSize);
            AddParamListItem("UT2D Center X Offset", "P14", "Behavior UnTarget2d", this.textBoxUT2DCenterXOffset);
            AddParamListItem("UT2D Center Y Offset", "P15", "Behavior UnTarget2d", this.textBoxUT2DCenterYOffset);

            // Uncertainty Target Shift Parameters
            AddParamListItem("UT2D Shift Mean", "P16", "Behavior UnTarget2d", this.textBoxUT2DShiftMean);
            AddParamListItem("UT2D Shift Stdev", "P17", "Behavior UnTarget2d", this.textBoxUT2DShiftStdev);
            AddParamListItem("UT2D Block Window Start", "P18", "Behavior UnTarget2d", this.textBoxUT2DBlockWindowStart);
            AddParamListItem("UT2D Block Window End", "P19", "Behavior UnTarget2d", this.textBoxUT2DBlockWindowEnd);

            // Uncertainty Target Cloud Parameters
            AddParamListItem("UT2D Cloud 1 Stdev", "P20", "Behavior UnTarget2d", this.textBoxUT2DCloud1Stdev);
            AddParamListItem("UT2D Cloud 2 Stdev", "P21", "Behavior UnTarget2d", this.textBoxUT2DCloud2Stdev);
            AddParamListItem("UT2D Cloud 3 Stdev", "P22", "Behavior UnTarget2d", this.textBoxUT2DCloud3Stdev);
            AddParamListItem("UT2D Cloud 4 Stdev", "P23", "Behavior UnTarget2d", this.textBoxUT2DCloud4Stdev);

            AddParamListItem("UT2D Cloud 1 Freq", "P24", "Behavior UnTarget2d", this.textBoxUT2DCloud1Freq);
            AddParamListItem("UT2D Cloud 2 Freq", "P25", "Behavior UnTarget2d", this.textBoxUT2DCloud2Freq);
            AddParamListItem("UT2D Cloud 3 Freq", "P26", "Behavior UnTarget2d", this.textBoxUT2DCloud3Freq);
            AddParamListItem("UT2D Cloud 4 Freq", "P27", "Behavior UnTarget2d", this.textBoxUT2DCloud4Freq);

            AddParamListItem("UT2D Cloud 1 Blank", "P28", "Behavior UnTarget2d", this.checkBoxUT2DCloud1Blank);

            AddParamListItem("UT2D Slice Size", "P29", "Behavior UnTarget2d", this.textBoxUT2DSliceSize);
            AddParamListItem("UT2D Slice Number", "P30", "Behavior UnTarget2d", this.numericUpDownUT2DSliceNumber);
            AddParamListItem("UT2D Feedback Start", "P31", "Behavior UnTarget2d", this.textBoxUT2DFeedbackStart);
            AddParamListItem("UT2D Feedback End", "P32", "Behavior UnTarget2d", this.textBoxUT2DFeedbackEnd);

            AddParamListItem("UT2D Cloud Jitter", "P33", "Behavior UnTarget2d", this.textBoxUT2DCloudJitter);

            AddParamListItem("UT2D Use Timed", "P34", "Behavior UnTarget2d", this.checkBoxUT2DUseTimed);
            AddParamListItem("UT2D Timed Duration", "P35", "Behavior UnTarget2d", this.textBoxUT2DTimedDuration);
            AddParamListItem("UT2D Timed Location", "P36", "Behavior UnTarget2d", this.textBoxUT2DTimedLocation);
            AddParamListItem("UT2D Target Delay Mode", "P37", "Behavior UnTarget2d", this.checkBoxUT2DTargetDelayMode);

            AddParamListItem("UT2D Outer Target Depth", "P38", "Behavior UnTarget2d", this.textBoxUT2DOTdepth);

            AddParamListItem("UT2D Show Prior", "P39", "Behavior UnTarget2d", this.checkBoxUT2Dshowprior);

            AddParamListItem("UT2D Delay Catch Freq", "P40", "Behavior UnTarget2d", this.textBoxUT2D_DelayCatchFreq);
            AddParamListItem("UT2D Delay Catch Low", "P41", "Behavior UnTarget2d", this.textBoxUT2D_DelayCatchLow);
            AddParamListItem("UT2D Delay Catch High", "P42", "Behavior UnTarget2d", this.textBoxUT2D_DelayCatchHigh);

            AddParamListItem("UT2D COHack Mode", "P43", "Behavior UnTarget2d", this.checkBoxUT2D_COHackMode);
            AddParamListItem("UT2D COHack TgtNum", "P44", "Behavior UnTarget2d", this.numericUpDownUT2D_COHackTgtNum);
            AddParamListItem("UT2D COHack Rot", "P45", "Behavior UnTarget2d", this.textBoxUT2D_COHackRot);

            AddParamListItem("UT2D reward perc", "P46", "Behavior UnTarget2d", this.textBoxUT2Drewardperc);
            
            AddParamListItem("UT2D Target Circle Color", "P47", "Behavior UnTarget2d", this.numericUD_TargetCircleColor);
            AddParamListItem("UT2D Cloud 1 Color", "P48", "Behavior UnTarget2d", this.numericUD_TargetColor_1);
            AddParamListItem("UT2D Cloud 2 Color", "P49", "Behavior UnTarget2d", this.numericUD_TargetColor_2);
            AddParamListItem("UT2D Cloud 3 Color", "P50", "Behavior UnTarget2d", this.numericUD_TargetColor_3);
            AddParamListItem("UT2D Cloud 4 Color", "P51", "Behavior UnTarget2d", this.numericUD_TargetColor_4);
            AddParamListItem("UT2D Prior Marker Color", "P52", "Behavior UnTarget2d", this.numericUD_PriorColor);

            AddParamListItem("UT2D reveal cloud 1", "P53", "Behavior UnTarget2d", this.checkBoxUT2Dreveal1);
            AddParamListItem("UT2D reveal cloud 2", "P54", "Behavior UnTarget2d", this.checkBoxUT2Dreveal2);
            AddParamListItem("UT2D reveal cloud 3", "P55", "Behavior UnTarget2d", this.checkBoxUT2Dreveal3);
            AddParamListItem("UT2D reveal cloud 4", "P56", "Behavior UnTarget2d", this.checkBoxUT2Dreveal4);

            AddParamListItem("UT2D show co locs", "P57", "Behavior UnTarget2d", this.checkBoxUT2Dshow_co_targs);
            #endregion

            #region Dynamic Center Out
            // Timing
            AddParamListItem("DCO CHL", "P2", "Behavior DCO", this.textBoxDCOCHL);
            AddParamListItem("DCO CHH", "P3", "Behavior DCO", this.textBoxDCOCHH);
            AddParamListItem("DCO OH", "P4", "Behavior DCO", this.textBoxDCOOH);
            AddParamListItem("DCO RW", "P5", "Behavior DCO", this.textBoxDCORW);
            AddParamListItem("DCO AW", "P6", "Behavior DCO", this.textBoxDCOAW);
            AddParamListItem("DCO FW", "P7", "Behavior DCO", this.textBoxDCOFW);
            AddParamListItem("DCO MT", "P8", "Behavior DCO", this.textBoxDCOMT);

            // Cursor
            AddParamListItem("DCO CR", "P9", "Behavior DCO", this.textBoxDCOCR);
            AddParamListItem("DCO BC", "P10", "Behavior DCO", this.checkBoxDCOBC);

            // Targets
            AddParamListItem("DCO CTR", "P11", "Behavior DCO", this.textBoxDCOCTR);
            AddParamListItem("DCO OTR", "P12", "Behavior DCO", this.textBoxDCOOTR);
            AddParamListItem("DCO OTS", "P13", "Behavior DCO", this.angleEntryBoxDCOOTS);
            AddParamListItem("DCO OTT", "P14", "Behavior DCO", this.textBoxDCOOTT);
            AddParamListItem("DCO NT", "P15", "Behavior DCO", this.textBoxDCONT);
            AddParamListItem("DCO NTS", "P16", "Behavior DCO", this.textBoxDCONTS);
            AddParamListItem("DCO TSMin", "P17", "Behavior DCO", this.textBoxDCOTSMin);
            AddParamListItem("DCO TSMax", "P18", "Behavior DCO", this.textBoxDCOTSMax);
            AddParamListItem("DCO NTF", "P19", "Behavior DCO", this.textBoxDCONTF);
            AddParamListItem("DCO TFMin", "P20", "Behavior DCO", this.textBoxDCOTFMin);
            AddParamListItem("DCO TFMax", "P21", "Behavior DCO", this.textBoxDCOTFMax);
            AddParamListItem("DCO TFW", "P22", "Behavior DCO", this.textBoxDCOTFW);

            // Controller
            AddParamListItem("DCO D", "P23", "Behavior DCO", this.textBoxDCOD);
            AddParamListItem("DCO VF", "P24", "Behavior DCO", this.textBoxDCOVF);
            AddParamListItem("DCO PF", "P25", "Behavior DCO", this.textBoxDCOPF);

            // Cerebus recording
            AddParamListItem("DCO SRec", "P26", "Behavior DCO", this.checkBoxRecord);
            AddParamListItem("DCO RecFor", "P27", "Behavior DCO", this.textBoxRecordFor);

            // More target stuff
            AddParamListItem("DCO STIF", "P28", "Behavior DCO", this.checkBoxDCOSTIF);

            // Isometric mode stuff
            AddParamListItem("DCO FCG", "P29", "Behavior DCO", this.textBoxDCOFCG);

            // More target stuff
            AddParamListItem("DCO SFT", "P30", "Behavior DCO", this.checkBoxDCOSFT);
            AddParamListItem("DCO TS", "P31", "Behavior DCO", this.angleEntryBoxDCOTS);
            AddParamListItem("DCO FTD", "P32", "Behavior DCO", this.angleEntryBoxDCOFTD);
            AddParamListItem("DCO STL", "P33", "Behavior DCO", this.checkBoxDCOSTL);

            #endregion

            #region UnCisek
            /* 
             * UnCisek Parameters 
             */

            // Timing
            AddParamListItem("UCK CHL", "P2", "Behavior UnCisek", this.textBoxUCK_CHLo);
            AddParamListItem("UCK CHH", "P3", "Behavior UnCisek", this.textBoxUCK_CHHi);
            AddParamListItem("UCK OCDL", "P4", "Behavior UnCisek", this.textBoxUCK_OCDLo);
            AddParamListItem("UCK OCDH", "P5", "Behavior UnCisek", this.textBoxUCK_OCDHi);
            AddParamListItem("UCK CMDL", "P6", "Behavior UnCisek", this.textBoxUCK_CMDLo);
            AddParamListItem("UCK CMDH", "P7", "Behavior UnCisek", this.textBoxUCK_CMDHi);
            AddParamListItem("UCK CCDL", "P8", "Behavior UnCisek", this.textBoxUCK_CCDLo);
            AddParamListItem("UCK CCDH", "P9", "Behavior UnCisek", this.textBoxUCK_CCDHi);
            AddParamListItem("UCK OHL", "P10", "Behavior UnCisek", this.textBoxUCK_OHLo);
            AddParamListItem("UCK OHH", "P11", "Behavior UnCisek", this.textBoxUCK_OHHi);
            AddParamListItem("UCK ITI", "P12", "Behavior UnCisek", this.textBoxUCK_ITI);
            AddParamListItem("UCK MMT", "P13", "Behavior UnCisek", this.textBoxUCK_MMT);
            AddParamListItem("UCK FPL", "P14", "Behavior UnCisek", this.textBoxUCK_FPL);

            // General Parameters     
            AddParamListItem("UCK Move Length", "P15", "Behavior UnCisek", this.textBoxUCK_MLen);
            AddParamListItem("UCK Center Size", "P16", "Behavior UnCisek", this.textBoxUCK_CTS);
            AddParamListItem("UCK Outer Size", "P17", "Behavior UnCisek", this.textBoxUCK_OTS);
            AddParamListItem("UCK Target Angle Diff", "P18", "Behavior UnCisek", this.numericUD_UCK_TAD);
            AddParamListItem("UCK Cue One R", "P19", "Behavior UnCisek", this.textBoxUCK_Cue1ColR);
            AddParamListItem("UCK Cue One G", "P20", "Behavior UnCisek", this.textBoxUCK_Cue1ColG);
            AddParamListItem("UCK Cue One B", "P21", "Behavior UnCisek", this.textBoxUCK_Cue1ColB);
            AddParamListItem("UCK Cue Two R", "P22", "Behavior UnCisek", this.textBoxUCK_Cue2ColR);
            AddParamListItem("UCK Cue Two G", "P23", "Behavior UnCisek", this.textBoxUCK_Cue2ColG);
            AddParamListItem("UCK Cue Two B", "P24", "Behavior UnCisek", this.textBoxUCK_Cue2ColB);
            AddParamListItem("UCK Default R", "P25", "Behavior UnCisek", this.textBoxUCK_DefColR);
            AddParamListItem("UCK Default G", "P26", "Behavior UnCisek", this.textBoxUCK_DefColG);
            AddParamListItem("UCK Default B", "P27", "Behavior UnCisek", this.textBoxUCK_DefColB);
            AddParamListItem("UCK Cue One Rate", "P28", "Behavior UnCisek", this.textBoxUCK_Cue1Rate);
            AddParamListItem("UCK Cue Two Rate", "P29", "Behavior UnCisek", this.textBoxUCK_Cue2Rate);
            AddParamListItem("UCK CO Mode", "P30", "Behavior UnCisek", this.checkBoxUCK_COMode);
            AddParamListItem("UCK Match Mode", "P31", "Behavior UnCisek", this.checkBoxUCK_MMode);

            AddParamListItem("UCK Cue Offset", "P32", "Behavior UnCisek", this.textBoxUCK_CueOffset);
            AddParamListItem("UCK Center Color Mode", "P33", "Behavior UnCisek", this.checkBoxUCK_TargetColorMode);
            AddParamListItem("UCK Target Cue Choice Mode", "P34", "Behavior UnCisek", this.checkBoxUCK_OnlyCue);
            AddParamListItem("UCK Target True Choice Mode", "P35", "Behavior UnCisek", this.checkBoxUCK_OnlyTrue);
            AddParamListItem("UCK Skip Center Cue", "P36", "Behavior UnCisek", this.checkBoxUCK_catchmode);
            AddParamListItem("UCK Catch Pct", "P37", "Behavior UnCisek", this.textBoxUCK_catchpct);

            AddParamListItem("UCK CO percentage", "P38", "Behavior UnCisek", this.textBoxUCK_copercentage);
            AddParamListItem("UCK num targest", "P39", "Behavior UnCisek", this.numericUD_UCK_numtargs);

            AddParamListItem("UCK static colors", "P40", "Behavior UnCisek", this.checkBoxUCK_staticcolor);
            AddParamListItem("UCK color training", "P41", "Behavior UnCisek", this.checkBoxUCK_colortraining);

            AddParamListItem("UCK no fail", "P42", "Behavior UnCisek", this.checkBoxUCK_nofail);
            #endregion

            #region Unstable Reach
            // Timing
            AddParamListItem("UR CHL", "P2", "Behavior UR", this.textBoxURCHL);
            AddParamListItem("UR CHH", "P3", "Behavior UR", this.textBoxURCHH);
            AddParamListItem("UR OH", "P4", "Behavior UR", this.textBoxUROH);
            AddParamListItem("UR RW", "P5", "Behavior UR", this.textBoxURRW);
            AddParamListItem("UR AW", "P6", "Behavior UR", this.textBoxURAW);
            AddParamListItem("UR FW", "P7", "Behavior UR", this.textBoxURFW);
            AddParamListItem("UR MT", "P8", "Behavior UR", this.textBoxURMT);

            // Cursor
            AddParamListItem("UR BC", "P9", "Behavior UR", this.checkBoxURBC);

            // Targets
            AddParamListItem("UR TR", "P10", "Behavior UR", this.textBoxURTR);
            AddParamListItem("UR MD", "P11", "Behavior UR", this.textBoxURMD);
            AddParamListItem("UR CC", "P12", "Behavior UR", this.checkBoxURCC);

            // Force field
            AddParamListItem("UR FS1", "P13", "Behavior UR", this.textBoxURFS1);
            AddParamListItem("UR FS2", "P14", "Behavior UR", this.textBoxURFS2);
            AddParamListItem("UR FS3", "P15", "Behavior UR", this.textBoxURFS3);
            AddParamListItem("UR PS1", "P16", "Behavior UR", this.textBoxURPS1);
            AddParamListItem("UR PS2", "P17", "Behavior UR", this.textBoxURPS2);
            AddParamListItem("UR D", "P18", "Behavior UR", this.textBoxURD);
            AddParamListItem("UR FMD", "P19", "Behavior UR", this.angleEntryBoxURFMD);
            AddParamListItem("UR NMD", "P20", "Behavior UR", this.textBoxURNMD);
            AddParamListItem("UR TBS", "P21", "Behavior UR", this.textBoxURTBS);
            
            // Velocity controller
            AddParamListItem("UR VF", "P22", "Behavior UR", this.textBoxURVF);
            AddParamListItem("UR PF", "P23", "Behavior UR", this.textBoxURPF);
            
            // Cerebus recording
            AddParamListItem("UR SRec", "P24", "Behavior UR", this.checkBoxRecord);
            AddParamListItem("UR RecFor", "P25", "Behavior UR", this.textBoxRecordFor);

            // More force field
            AddParamListItem("UR MinCD", "P26", "Behavior UR", this.textBoxURMinCD);
            AddParamListItem("UR MaxCD", "P27", "Behavior UR", this.textBoxURMaxCD);
            AddParamListItem("UR NumCD", "P28", "Behavior UR", this.textBoxURNCD);

            // Bumps
            AddParamListItem("UR PBT", "P29", "Behavior UR", this.textBoxURPBT);
            AddParamListItem("UR BM", "P30", "Behavior UR", this.textBoxURBM);
            AddParamListItem("UR BD", "P31", "Behavior UR", this.textBoxURBD);
            AddParamListItem("UR BV", "P32", "Behavior UR", this.textBoxURBV);
            AddParamListItem("UR VG", "P33", "Behavior UR", this.textBoxURVG);
            AddParamListItem("UR PG", "P34", "Behavior UR", this.textBoxURPG);
            AddParamListItem("UR FB", "P35", "Behavior UR", this.checkBoxURFB);

            AddParamListItem("UR SD", "P36", "Behavior UR", this.textBoxURSD);

            #endregion

            #region Resist perturbations
            // Timing
            AddParamListItem("RP CHL", "P2", "Behavior RP", this.textBoxRPCHL);
            AddParamListItem("RP CHH", "P3", "Behavior RP", this.textBoxRPCHH);
            AddParamListItem("RP PHL", "P4", "Behavior RP", this.textBoxRPPHL);
            AddParamListItem("RP PHH", "P5", "Behavior RP", this.textBoxRPPHH);
            AddParamListItem("RP RW", "P6", "Behavior RP", this.textBoxRPRW);
            AddParamListItem("RP AW", "P7", "Behavior RP", this.textBoxRPAW);
            AddParamListItem("RP FW", "P8", "Behavior RP", this.textBoxRPFW);

            // Cursor
            AddParamListItem("RP BC", "P9", "Behavior RP", this.checkBoxRPBC);

            // Targets
            AddParamListItem("RP TR", "P10", "Behavior RP", this.textBoxRPTR);
            AddParamListItem("RP FVF", "P11", "Behavior RP", this.checkBoxRPFVF);

            // Perturbations
            AddParamListItem("RP FAL", "P12", "Behavior RP", this.textBoxRPFAL);
            AddParamListItem("RP FAH", "P13", "Behavior RP", this.textBoxRPFAH);
            AddParamListItem("RP NFA", "P14", "Behavior RP", this.textBoxRPNFA);
            AddParamListItem("RP FFL", "P15", "Behavior RP", this.textBoxRPFFL);
            AddParamListItem("RP FFH", "P16", "Behavior RP", this.textBoxRPFFH);
            AddParamListItem("RP NFF", "P17", "Behavior RP", this.textBoxRPNFF);
            AddParamListItem("RP FBS", "P18", "Behavior RP", this.textBoxRPFBS);
            AddParamListItem("RP FFD", "P19", "Behavior RP", this.angleEntryBoxRPFFD);
            AddParamListItem("RP NFD", "P20", "Behavior RP", this.textBoxRPNFD);
            AddParamListItem("RP BFD", "P21", "Behavior RP", this.checkBoxRPBFD);
            AddParamListItem("RP TRB", "P22", "Behavior RP", this.checkBoxRPTRB);
            AddParamListItem("RP PT", "P23", "Behavior RP", this.textBoxRPPT);

            // Velocity controller
            AddParamListItem("RP VF", "P24", "Behavior RP", this.textBoxRPVF);
            AddParamListItem("RP PF", "P25", "Behavior RP", this.textBoxRPPF);

            // Cerebus recording
            AddParamListItem("RP SRec", "P26", "Behavior RP", this.checkBoxRecord);
            AddParamListItem("RP RecFor", "P27", "Behavior RP", this.textBoxRecordFor);

            // Bumps
            AddParamListItem("RP NBD", "P28", "Behavior RP", this.textBoxRPNBD);
            AddParamListItem("RP FBD", "P29", "Behavior RP", this.angleEntryBoxRPFBD);
            AddParamListItem("RP PBT", "P30", "Behavior RP", this.textBoxRPPBT);
            AddParamListItem("RP BM", "P31", "Behavior RP", this.textBoxRPBM);
            AddParamListItem("RP BD", "P32", "Behavior RP", this.textBoxRPBD);
            AddParamListItem("RP BV", "P33", "Behavior RP", this.textBoxRPBV);
            AddParamListItem("RP VG", "P34", "Behavior RP", this.textBoxRPVG);
            AddParamListItem("RP PG", "P35", "Behavior RP", this.textBoxRPPG);
            AddParamListItem("RP FB", "P36", "Behavior RP", this.checkBoxRPFB);

            // Stabilizing field
            AddParamListItem("RP S", "P37", "Behavior RP", this.textBoxRPS);
            AddParamListItem("RP D", "P38", "Behavior RP", this.textBoxRPD);

            // More target stuff
            AddParamListItem("RP HTR", "P39", "Behavior RP", this.textBoxRPHTR);

            // More bump stuff
            AddParamListItem("RP PEB", "P40", "Behavior RP", this.textBoxRPPEB);      
      
            // Co-contraction stuff
            AddParamListItem("RP CCL", "P41", "Behavior RP", this.textBoxRPCCL);
            AddParamListItem("PR CCH", "P42", "Behavior RP", this.textBoxRPCCH);
            AddParamListItem("RP NCCL", "P43", "Behavior RP", this.textBoxRPNCCL);
            AddParamListItem("RP CCW", "P44", "Behavior RP", this.textBoxRPCCW);
            AddParamListItem("RP CR", "P45", "Behavior RP", this.textBoxRPCR);
            AddParamListItem("RP CCT", "P46", "Behavior RP", this.checkBoxRPCCT);

            // More target stuff
            AddParamListItem("RP STIF", "P47", "Behavior RP", this.checkBoxRPSTIF);

            // More perturbation stuff
            AddParamListItem("RP PRD", "P48", "Behavior RP", this.textBoxRPPRD);

            #endregion

            #region Cue Comb
            // Timing
            AddParamListItem("CC CHL", "P2", "Behavior Cue Comb", this.textBoxCC_CHL);
            AddParamListItem("CC CHH", "P3", "Behavior Cue Comb", this.textBoxCC_CHH);
            AddParamListItem("CC CDL", "P4", "Behavior Cue Comb", this.textBoxCC_CDL);
            AddParamListItem("CC CDH", "P5", "Behavior Cue Comb", this.textBoxCC_CDH);
            AddParamListItem("CC intertrial", "P6", "Behavior Cue Comb", this.textBoxCC_intertrial);
            AddParamListItem("CC MT", "P7", "Behavior Cue Comb", this.textBoxCC_movementTime);
            AddParamListItem("CC FailLag", "P8", "Behavior Cue Comb", this.textBoxCC_failurelag);
            AddParamListItem("CC MoveLength", "P9", "Behavior Cue Comb", this.textBoxCC_MovementLength);
            AddParamListItem("CC CTsize", "P10", "Behavior Cue Comb", this.textBoxCC_CTrad);
            AddParamListItem("CC OT_size", "P11", "Behavior Cue Comb", this.textBoxCC_OTwidth);
            AddParamListItem("CC OT_depth", "P12", "Behavior Cue Comb", this.textBoxCC_OTdepth);
            AddParamListItem("CC X_offset", "P13", "Behavior Cue Comb", this.textBoxCC_Xoffset);
            AddParamListItem("CC Y_offset", "P14", "Behavior Cue Comb", this.textBoxCC_Yoffset);
            AddParamListItem("CC prior_mean", "P15", "Behavior Cue Comb", this.textBoxCC_PriorMean);
            AddParamListItem("CC prior_kap", "P16", "Behavior Cue Comb", this.textBoxCC_PriorKap);

            AddParamListItem("CC cloud_kap_one", "P17", "Behavior Cue Comb", this.textBoxCC_cloud1Kap);
            AddParamListItem("CC cloud_kap_two", "P18", "Behavior Cue Comb", this.textBoxCC_cloud2Kap);
            AddParamListItem("CC cloud_kap_three", "P19", "Behavior Cue Comb", this.textBoxCC_cloud3Kap);
            AddParamListItem("CC cloud_kap_four", "P20", "Behavior Cue Comb", this.textBoxCC_cloud4Kap);
            AddParamListItem("CC cloud_freq_one", "P21", "Behavior Cue Comb", this.textBoxCC_cloud1Freq);
            AddParamListItem("CC cloud_freq_two", "P22", "Behavior Cue Comb", this.textBoxCC_cloud2Freq);
            AddParamListItem("CC cloud_freq_three", "P23", "Behavior Cue Comb", this.textBoxCC_cloud3Freq);
            AddParamListItem("CC cloud_freq_four", "P24", "Behavior Cue Comb", this.textBoxCC_cloud4Freq);

            AddParamListItem("CC blank_one_mode", "P25", "Behavior Cue Comb", this.checkBoxCC_cloud1Blank);
            AddParamListItem("CC slice_size", "P26", "Behavior Cue Comb", this.textBoxCC_slicesize);
            AddParamListItem("CC slice_num", "P27", "Behavior Cue Comb", this.numericUpDownCC_numslices);

            AddParamListItem("CC catch_freq", "P28", "Behavior Cue Comb", this.textBoxCC_catchFreq);
            AddParamListItem("CC catch_L", "P29", "Behavior Cue Comb", this.textBoxCC_catchLow);
            AddParamListItem("CC catch_H", "P30", "Behavior Cue Comb", this.textBoxCC_catchHigh);

            AddParamListItem("CC use_cohack", "P31", "Behavior Cue Comb", this.checkBoxCC_COhack);
            AddParamListItem("CC cohack num", "P32", "Behavior Cue Comb", this.numericUpDownCC_numCOtargs);

            AddParamListItem("CC Use Random", "P33", "Behavior Cue Comb", this.checkBoxCC_useRandomBump);
            AddParamListItem("CC Rand_Low", "P34", "Behavior Cue Comb", this.textBoxCC_randbumpLow);
            AddParamListItem("CC Rand_High", "P35", "Behavior Cue Comb", this.textBoxCC_randbumpHigh);

            AddParamListItem("CC bump_1_mag", "P36", "Behavior Cue Comb", this.textBoxCC_bump1Mag);
            AddParamListItem("CC bump_2_mag", "P37", "Behavior Cue Comb", this.textBoxCC_bump2Mag);
            AddParamListItem("CC bump_3_mag", "P38", "Behavior Cue Comb", this.textBoxCC_bump3Mag);
            AddParamListItem("CC bump_1_freq", "P39", "Behavior Cue Comb", this.textBoxCC_bump1Freq);
            AddParamListItem("CC bump_2_freq", "P40", "Behavior Cue Comb", this.textBoxCC_bump2Freq);
            AddParamListItem("CC bump_3_freq", "P41", "Behavior Cue Comb", this.textBoxCC_bump3Freq);

            AddParamListItem("CC bump_duration", "P42", "Behavior Cue Comb", this.textBoxCC_bumpduration);
            AddParamListItem("CC Gain_pos", "P43", "Behavior Cue Comb", this.textBoxCC_posGain);
            AddParamListItem("CC Gain_vel", "P44", "Behavior Cue Comb", this.textBoxCC_velGain);

            AddParamListItem("CC stim_prob", "P45", "Behavior Cue Comb", this.textBoxCC_stimProb);
            AddParamListItem("CC pos filt", "P46", "Behavior Cue Comb", this.textBoxCC_posfilt);
            AddParamListItem("CC vel filt", "P47", "Behavior Cue Comb", this.textBoxCC_velfilt);
            AddParamListItem("CC bump duration back", "P48", "Behavior Cue Comb", this.textBoxCC_bump_durationBack);
            AddParamListItem("CC No Return", "P49", "Behavior Cue Comb", this.checkBoxCC_NoReturn);

            AddParamListItem("CC feedback window", "P50", "Behavior Cue Comb", this.textBoxCC_feedback_win);
            AddParamListItem("CC training", "P51", "Behavior Cue Comb", this.checkBoxCC_training);

            AddParamListItem("CC use_force_bump", "P52", "Behavior Cue Comb", this.checkBoxCC_forceBumpMode);
            AddParamListItem("CC force rise time", "P53", "Behavior Cue Comb", this.textBoxCC_forceBumpRiseTime);
            AddParamListItem("CC force peak time", "P54", "Behavior Cue Comb", this.textBoxCC_forceBumpPeakTime);

            AddParamListItem("CC bump sampling method", "P55", "Behavior Cue Comb", this.textBoxCC_BSM);
            AddParamListItem("CC small target radius", "P56", "Behavior Cue Comb", this.textBoxCC_STrad);
            #endregion

            #region Sabes

            AddParamListItem("SAB CHL", "P2", "Behavior COsabes", this.textBoxSAB_CHlow);
            AddParamListItem("SAB CHH", "P3", "Behavior COsabes", this.textBoxSAB_CHhigh);
            AddParamListItem("SAB CDL", "P4", "Behavior COsabes", this.textBoxSAB_CDlow);
            AddParamListItem("SAB CDH", "P5", "Behavior COsabes", this.textBoxSAB_CDhigh);
            AddParamListItem("SAB OHL", "P6", "Behavior COsabes", this.textBoxSAB_OHlow);
            AddParamListItem("SAB OHH", "P7", "Behavior COsabes", this.textBoxSAB_OHhigh);
            AddParamListItem("SAB INT", "P8", "Behavior COsabes", this.textBoxSAB_intertrial);
            AddParamListItem("SAB MT", "P9", "Behavior COsabes", this.textBoxSAB_MT);
            AddParamListItem("SAB FL", "P10", "Behavior COsabes", this.textBoxSAB_FLtime);

            AddParamListItem("SAB ML", "P11", "Behavior COsabes", this.textBoxSAB_movementlength);
            AddParamListItem("SAB CTR", "P12", "Behavior COsabes", this.textBoxSAB_CTradius);
            AddParamListItem("SAB OTR", "P13", "Behavior COsabes", this.textBoxSAB_OTradius);
            
            AddParamListItem("SAB COX", "P14", "Behavior COsabes", this.textBoxSAB_coffsetX);
            AddParamListItem("SAB COY", "P15", "Behavior COsabes", this.textBoxSAB_coffsetY);

            AddParamListItem("SAB SMAG", "P16", "Behavior COsabes", this.textBoxSAB_shiftmag);
            AddParamListItem("SAB SAXIS", "P17", "Behavior COsabes", this.textBoxSAB_shiftaxis);
            AddParamListItem("SAB SFREQ", "P18", "Behavior COsabes", this.textBoxSAB_shiftfreq);
            AddParamListItem("SAB WSFREQ", "P19", "Behavior COsabes", this.textBoxSAB_wsshiftfreq);

            AddParamListItem("SAB DCF", "P20", "Behavior COsabes", this.textBoxSAB_DCfreq);
            AddParamListItem("SAB DCL", "P21", "Behavior COsabes", this.textBoxSAB_DClow);
            AddParamListItem("SAB DCH", "P22", "Behavior COsabes", this.textBoxSAB_DChigh);

            AddParamListItem("SAB NUM", "P23", "Behavior COsabes", this.numericUpDownSAB_numtargets);
            AddParamListItem("SAB COR", "P24", "Behavior COsabes", this.textBoxSAB_COrotation);
            AddParamListItem("SAB CTC", "P25", "Behavior COsabes", this.numericUpDownSAB_CTcolor);
            AddParamListItem("SAB OTC", "P26", "Behavior COsabes", this.numericUpDownSAB_OTcolor);

            AddParamListItem("SAB VG", "P27", "Behavior COsabes", this.textBoxSAB_maxforce);
            AddParamListItem("SAB PG", "P28", "Behavior COsabes", this.textBoxSAB_forcegain);
            AddParamListItem("SAB VF", "P29", "Behavior COsabes", this.textBoxSAB_velfilt);
            AddParamListItem("SAB PF", "P30", "Behavior COsabes", this.textBoxSAB_posfilt);
            AddParamListItem("SAB ret", "P31", "Behavior COsabes", this.checkBoxSAB_showreturn);

            AddParamListItem("SAB visc", "Gain", "viscous target/VGain", this.textBoxSAB_vgain);


            #endregion

            #region CenterOut3D
                AddParamListItem("a1", "P1", "Behavior CO 3D", this.numTargets3DTask);
                AddParamListItem("a2", "P2", "Behavior CO 3D", this.centerHoldLow3DTask);
                AddParamListItem("a3", "P3", "Behavior CO 3D", this.centerHoldHigh3DTask);
                AddParamListItem("a4", "P4", "Behavior CO 3D", this.centerDelayLow3DTask);
                AddParamListItem("a5", "P5", "Behavior CO 3D", this.centerDelayHigh3DTask);
                AddParamListItem("a6", "P6", "Behavior CO 3D", this.movementTime3DTask);
                AddParamListItem("a7", "P7", "Behavior CO 3D", this.outerHoldHigh3DTask);
                AddParamListItem("a8", "P8", "Behavior CO 3D", this.outerHoldLow3DTask);
                AddParamListItem("a9", "P9", "Behavior CO 3D", this.centerHoldHigh3DTask);
                AddParamListItem("a10", "P10", "Behavior CO 3D", this.mode3DTask);
                AddParamListItem("a11", "P11", "Behavior CO 3D", this.idiotMode3DTask);
                AddParamListItem("a12", "P12", "Behavior CO 3D", this.reset3DTask);
                AddParamListItem("a13", "P13", "Behavior CO 3D", this.intertrial3DTask);
            #endregion

            #region OutOut
                AddParamListItem("OO CTlow", "P2", "Behavior OutOut", this.textBoxOO_T1low);
                AddParamListItem("OO CThigh", "P3", "Behavior OutOut", this.textBoxOO_T1high);
                AddParamListItem("OO OTlow", "P4", "Behavior OutOut", this.textBoxOO_targ2low);
                AddParamListItem("OO OThigh", "P5", "Behavior OutOut", this.textBoxOO_targ2high);
                AddParamListItem("OO intertrial", "P6", "Behavior OutOut", this.textBoxOO_intertrial);
                AddParamListItem("OO movetime", "P7", "Behavior OutOut", this.textBoxOO_movetime);
                AddParamListItem("OO failtime", "P8", "Behavior OutOut", this.textBoxOO_failtime);

                AddParamListItem("OO reach length", "P9", "Behavior OutOut", this.textBoxOO_movelength);
                AddParamListItem("OO target size", "P10", "Behavior OutOut", this.textBoxOO_targetsize);
                AddParamListItem("OO colorR", "P11", "Behavior OutOut", this.textBoxOO_colorR);
                AddParamListItem("OO colorG", "P12", "Behavior OutOut", this.textBoxOO_targetcolorG);
                AddParamListItem("OO colorB", "P13", "Behavior OutOut", this.textBoxOO_targetcolorB);
                AddParamListItem("OO numtargs", "P14", "Behavior OutOut", this.numericUpDownOO_numtarget);
                AddParamListItem("OO force mag", "P15", "Behavior OutOut", this.textBoxOO_forcemag);
                
            #endregion

            #region ReceptorStim
                AddParamListItem("RSNumTargets", "P1", "Behavior Receptor Stim", this.numericUpDownRSNumTarg);
                AddParamListItem("RSTargSize", "P2", "Behavior Receptor Stim", this.textBoxRSTS);
                AddParamListItem("RSTargTol", "P3", "Behavior Receptor Stim", this.textBoxRSTT);
                AddParamListItem("RS Left Targ Bound", "P4", "Behavior Receptor Stim", this.textBoxRSLeTB);
                AddParamListItem("RS Right Targ Bound","P5", "Behavior Receptor Stim", this.textBoxRSRTB);
                AddParamListItem("RS Upper Targ Bound", "P6", "Behavior Receptor Stim", this.textBoxRSUTB);
                AddParamListItem("RS Lower Targ Bound", "P7", "Behavior Receptor Stim", this.textBoxRSLoTB);
                AddParamListItem("RS Target Hold Low", "P8", "Behavior Receptor Stim", this.textBoxRSTHL);
                AddParamListItem("RS Target Hold High", "P9", "Behavior Receptor Stim", this.textBoxRSTHH);
                AddParamListItem("RS Target Delay Low", "P10", "Behavior Receptor Stim", this.textBoxRSTDL);
                AddParamListItem("RS Target Delay High", "P11", "Behavior Receptor Stim", this.textBoxRSTDH);
                AddParamListItem("RS Movement Time", "P12", "Behavior Receptor Stim", this.textBoxRSMT);
                AddParamListItem("RS Initial Movement", "P13", "Behavior Receptor Stim", this.textBoxRSIMT);
                AddParamListItem("RS Intertrial", "P14", "Behavior Receptor Stim", this.textBoxRSIT);
                AddParamListItem("RS Min Dist", "P15", "Behavior Receptor Stim", this.textBoxRSMiD);
                AddParamListItem("RS Max Dist", "P16", "Behavior Receptor Stim", this.textBoxRSMaD);
                AddParamListItem("RS Disable Abort", "P17", "Behavior Receptor Stim", this.checkBoxRSDA);
                AddParamListItem("RS Green", "P19", "Behavior Receptor Stim", this.checkBoxRSGT);
                AddParamListItem("RS Cum Hold", "P20", "Behavior Receptor Stim", this.checkBoxRSCH);
                AddParamListItem("RS GTO Stim", "P21", "Behavior Receptor Stim", this.checkBoxRSGTO);
                AddParamListItem("RS Vib Stim", "P22", "Behavior Receptor Stim", this.checkBoxRSVib);
            #endregion

            #region TwoSpaceRT
                AddParamListItem("TRT ctholdlow", "P2", "Behavior TwoSpaceRT", this.textBoxTRT_ctHoldLow);
                AddParamListItem("TRT ctholdhigh", "P3", "Behavior TwoSpaceRT", this.textBoxTRT_ctHoldHigh);
                AddParamListItem("TRT holdlow", "P4", "Behavior TwoSpaceRT", this.textBoxTRT_holdLow);
                AddParamListItem("TRT holdhigh", "P5", "Behavior TwoSpaceRT", this.textBoxTRT_holdHigh);
                
                AddParamListItem("TRT intertrial", "P6", "Behavior TwoSpaceRT", this.textBoxTRT_intertrial);
                AddParamListItem("TRT inittime", "P7", "Behavior TwoSpaceRT", this.textBoxTRT_initialMoveTime);
                AddParamListItem("TRT movetime", "P8", "Behavior TwoSpaceRT", this.textBoxTRT_maxMoveTime);
                AddParamListItem("TRT failtime", "P9", "Behavior TwoSpaceRT", this.textBoxTRT_failPenaltyLag);

                AddParamListItem("TRT targetsize", "P10", "Behavior TwoSpaceRT", this.textBoxTRT_targetSize);
                AddParamListItem("TRT numtargs", "P11", "Behavior TwoSpaceRT", this.numericUpDownTRT_numTargets);

                AddParamListItem("TRT colorR", "P12", "Behavior TwoSpaceRT", this.textBoxTRT_colorR);
                AddParamListItem("TRT colorG", "P13", "Behavior TwoSpaceRT", this.textBoxTRT_colorG);
                AddParamListItem("TRT colorB", "P14", "Behavior TwoSpaceRT", this.textBoxTRT_colorB);

                AddParamListItem("TRT ws1xmin", "P15", "Behavior TwoSpaceRT", this.textBoxTRT_ws1xmin);
                AddParamListItem("TRT ws1xmax", "P16", "Behavior TwoSpaceRT", this.textBoxTRT_ws1xmax);
                AddParamListItem("TRT ws1ymin", "P17", "Behavior TwoSpaceRT", this.textBoxTRT_ws1ymin);
                AddParamListItem("TRT ws1ymax", "P18", "Behavior TwoSpaceRT", this.textBoxTRT_ws1ymax);

                AddParamListItem("TRT ws2xmin", "P19", "Behavior TwoSpaceRT", this.textBoxTRT_ws2xmin);
                AddParamListItem("TRT ws2xmax", "P20", "Behavior TwoSpaceRT", this.textBoxTRT_ws2xmax);
                AddParamListItem("TRT ws2ymin", "P21", "Behavior TwoSpaceRT", this.textBoxTRT_ws2ymin);
                AddParamListItem("TRT ws2ymax", "P22", "Behavior TwoSpaceRT", this.textBoxTRT_ws2ymax);

                AddParamListItem("TRT bumprate", "P23", "Behavior TwoSpaceRT", this.textBoxTRT_bumpRate);
                AddParamListItem("TRT bumpholdtime", "P24", "Behavior TwoSpaceRT", this.textBoxTRT_bumpHoldTime);
                AddParamListItem("TRT bumpramp", "P25", "Behavior TwoSpaceRT", this.textBoxTRT_bumpRamp);
                AddParamListItem("TRT bumpmagnitude", "P26", "Behavior TwoSpaceRT", this.textBoxTRT_bumpMagnitude);
                AddParamListItem("TRT bumppeakhold", "P27", "Behavior TwoSpaceRT", this.textBoxTRT_bumpPeakHold);
                AddParamListItem("TRT bumpdirfloor", "P28", "Behavior TwoSpaceRT", this.textBoxTRT_bumpDirFloor);
                AddParamListItem("TRT bumpdirceil", "P29", "Behavior TwoSpaceRT", this.textBoxTRT_bumpDirCeil);
                AddParamListItem("TRT bumpnumdir", "P30", "Behavior TwoSpaceRT", this.numericUpDownTRT_bumpNumDir);

            #endregion

            #region RandomTarget3D
                AddParamListItem("RT3D ftholdlow", "P2", "Behavior RandomTarget3D", this.textBox3DRT_ftHoldLo);
                AddParamListItem("RT3D ftholdhigh", "P3", "Behavior RandomTarget3D", this.textBox3DRT_ftHoldHi);
                AddParamListItem("RT3D targHoldlow", "P4", "Behavior RandomTarget3D", this.textBox3DRT_targHoldLo);
                AddParamListItem("RT3D targHoldhigh", "P5", "Behavior RandomTarget3D", this.textBox3DRT_targHoldHi);

                AddParamListItem("RT3D initMoveTime", "P6", "Behavior RandomTarget3D", this.textBox3DRT_initMoveTime);
                AddParamListItem("RT3D maxMoveTime", "P7", "Behavior RandomTarget3D", this.textBox3DRT_maxMoveTime);

                AddParamListItem("RT3D numTargets", "P8", "Behavior RandomTarget3D", this.numericUpDown3DRT_numTargets);
                AddParamListItem("RT3D ftRow", "P9", "Behavior RandomTarget3D", this.textBox3DRT_ftRow);
                AddParamListItem("RT3D ftCol", "P10", "Behavior RandomTarget3D", this.textBox3DRT_ftCol);
            #endregion

            #region Ring Reporting
                AddParamListItem("RRB centerHoldLow", "P3", "Behavior Ring Reporting", this.textBoxRRB_centerHoldLow);
                AddParamListItem("RRB centerHoldHigh", "P4", "Behavior Ring Reporting", this.textBoxRRB_centerHoldHigh);
                AddParamListItem("RRB delayPeriodLow", "P5", "Behavior Ring Reporting", this.textBoxRRB_delayPeriodLow);
                AddParamListItem("RRB delayPeriodHigh", "P6", "Behavior Ring Reporting", this.textBoxRRB_delayPeriodHigh);
                AddParamListItem("RRB moveTime", "P7", "Behavior Ring Reporting", this.textBoxRRB_moveTime);
                AddParamListItem("RRB_targetHoldLow", "P8", "Behavior Ring Reporting", this.textBoxRRB_targetHoldLow);
                AddParamListItem("RRB_targetHoldHigh", "P9", "Behavior Ring Reporting", this.textBoxRRB_targetHoldHigh);
                AddParamListItem("RRB_bumpDelay", "P10", "Behavior Ring Reporting", this.textBoxRRB_bumpDelay);
                
                AddParamListItem("RRB_bumpHoldTime", "P11", "Behavior Ring Reporting", this.textBoxRRB_bumpHold);
                AddParamListItem("RRB_intertrial", "P12", "Behavior Ring Reporting", this.textBoxRRB_intertrial);
                AddParamListItem("RRB_penalty", "P13", "Behavior Ring Reporting", this.textBoxRRB_penaltyTime);
                
                AddParamListItem("RRB_targetSize", "P14", "Behavior Ring Reporting", this.textBoxRRB_targetSize);
                AddParamListItem("RRB_bigTargetSize", "P15", "Behavior Ring Reporting", this.textBoxRRB_bigTargetSize);

                AddParamListItem("RRB_OTSize", "P16", "Behavior Ring Reporting", this.textBoxRRB_outerTargetWidth);
                AddParamListItem("RRB_OTDepth", "P17", "Behavior Ring Reporting", this.textBoxRRB_outerTargetDepth);
                AddParamListItem("RRB_centerXOffset", "P18", "Behavior Ring Reporting", this.textBoxRRB_centerXOffset);
                AddParamListItem("RRB_centerYOffset", "P19", "Behavior Ring Reporting", this.textBoxRRB_centerYOffset);

                AddParamListItem("RRB_numTargets", "P20", "Behavior Ring Reporting", this.textBoxRRB_numTargets);
                AddParamListItem("RRB_useRandomTargets", "P21", "Behavior Ring Reporting", this.checkBoxRRB_useRandomTargets);
                AddParamListItem("RRB_targetKappa", "P22", "Behavior Ring Reporting", this.textBoxRRB_targetKappa);

                AddParamListItem("RRB_hideCursorDuringBump", "P23", "Behavior Ring Reporting", this.checkBoxRRB_hideCursorDuringBump);
                AddParamListItem("RRB_hideCursorDuringMovement", "P24", "Behavior Ring Reporting", this.checkBoxRRB_hideCursorDuringMovement);
                AddParamListItem("RRB_recenterCursor", "P25", "Behavior Ring Reporting", this.checkBoxRRB_recenterCursorAfterBump);
                AddParamListItem("RRB_abortDuringBump", "P26", "Behavior Ring Reporting", this.checkBoxRRB_abortDuringBump);

                AddParamListItem("RRB_bumpMagOne", "P27", "Behavior Ring Reporting", this.textBoxRRB_bumpMagOne);
                AddParamListItem("RRB_bumpMagTwo", "P28", "Behavior Ring Reporting", this.textBoxRRB_bumpMagTwo);
                AddParamListItem("RRB_bumpMagThree", "P29", "Behavior Ring Reporting", this.textBoxRRB_bumpMagThree);

                AddParamListItem("RRB_bumpFreqOne", "P30", "Behavior Ring Reporting", this.textBoxRRB_bumpFreqOne);
                AddParamListItem("RRB_bumpFreqTwo", "P31", "Behavior Ring Reporting", this.textBoxRRB_bumpFreqTwo);
                AddParamListItem("RRB_bumpFreqThree", "P32", "Behavior Ring Reporting", this.textBoxRRB_bumpFreqThree);

                AddParamListItem("RRB_forceRiseTime", "P33", "Behavior Ring Reporting", this.textBoxRRB_riseTime);
                AddParamListItem("RRB_forcePeakTime", "P34", "Behavior Ring Reporting", this.textBoxRRB_peakDuration);

                AddParamListItem("RRB_stimProb", "P35", "Behavior Ring Reporting", this.textBoxRRB_stimProb);
                AddParamListItem("RRB_stimLevels", "P36", "Behavior Ring Reporting", this.textBoxRRB_stimLevels);
                AddParamListItem("RRB_stimDuringBump", "P37", "Behavior Ring Reporting", this.checkBoxRRB_stimDuringBump);
                AddParamListItem("RRB_stimInsteadOfBump", "P38", "Behavior Ring Reporting", this.checkBoxRRB_stimInsteadOfBump);

                AddParamListItem("RRB_catchRate", "P39", "Behavior Ring Reporting", this.textBoxRRB_catchRate);
                AddParamListItem("RRB_showOuterRing", "P40", "Behavior Ring Reporting", this.checkBoxRRB_showOuterRing);
                AddParamListItem("RRB_showTargetRate", "P41", "Behavior Ring Reporting", this.textBoxRRB_showOuterTargetProb);
                AddParamListItem("RRB_useSquareTargets", "P42", "Behavior Ring Reporting", this.checkBoxRRB_useSquareTargets);

                AddParamListItem("RRB_movementLength", "P43", "Behavior Ring Reporting", this.textBoxRRB_movementLength);

                AddParamListItem("RRB_targetAngleOffset", "P44", "Behavior Ring Reporting", this.textBoxRRB_targetAngleOffset);
                AddParamListItem("RRB_outerTargetSize", "P45", "Behavior Ring Reporting", this.textBoxRRB_outerTargetSize);
                AddParamListItem("RRB_stimDelay", "P46", "Behavior Ring Reporting", this.textBoxRRB_stimDelay);
                AddParamListItem("RRB_repeatFails", "P47", "Behavior Ring Reporting", this.checkBoxRRB_repeatFailures);
                AddParamListItem("RRB_endAtOuterRing", "P48", "Behavior Ring Reporting", this.checkBoxRRB_endAtOuterRing);

                AddParamListItem("RRB_fallTime", "P49", "Behavior Ring Reporting", this.textBoxRRB_fallTime);
                AddParamListItem("RRB_useBumpMapping", "P50", "Behavior Ring Reporting", this.checkBoxRRB_useBumpMapping);
                AddParamListItem("RRB_p1", "P51", "Behavior Ring Reporting", this.textBoxRRB_p1);
                AddParamListItem("RRB_p2", "P52", "Behavior Ring Reporting", this.textBoxRRB_p2);
                AddParamListItem("RRB_p3", "P53", "Behavior Ring Reporting", this.textBoxRRB_p3);
                AddParamListItem("RRB_p4", "P54", "Behavior Ring Reporting", this.textBoxRRB_p4);
                AddParamListItem("RRB_p5", "P55", "Behavior Ring Reporting", this.textBoxRRB_p5);
                AddParamListItem("RRB_p6", "P56", "Behavior Ring Reporting", this.textBoxRRB_p6);
            
                AddParamListItem("RRB_usePinkRing","P57","Behavior Ring Reporting", this.checkBoxRRB_usePinkRing);

            #endregion

            #region CenterOutCenter3D
                AddParamListItem("COC3D sttHoldLo", "P2", "Behavior CenterOutCenter3D", this.textBoxCOC3D_stHoldLo);
                AddParamListItem("COC3D stHoldHi", "P3", "Behavior CenterOutCenter3D", this.textBoxCOC3D_stHoldHi);
                AddParamListItem("COC3D otHoldLo", "P4", "Behavior CenterOutCenter3D", this.textBoxCOC3D_otHoldLo);
                AddParamListItem("COC3D otHoldHi", "P5", "Behavior CenterOutCenter3D", this.textBoxCOC3D_otHoldHi);
                AddParamListItem("COC3D ftHoldLo", "P6", "Behavior CenterOutCenter3D", this.textBoxCOC3D_ftHoldLo);
                AddParamListItem("COC3D ftHoldHi", "P7", "Behavior CenterOutCenter3D", this.textBoxCOC3D_ftHoldHi);

                AddParamListItem("COC3D initMoveTime", "P8", "Behavior CenterOutCenter3D", this.textBoxCOC3D_initMoveTime);
                AddParamListItem("COC3D maxMoveTime", "P9", "Behavior CenterOutCenter3D", this.textBoxCOC3D_maxMoveTime);

                AddParamListItem("COC3D imuResetInterval", "P10", "Behavior RandomTarget3D", this.textBoxCOC3D_imuResetInterval);
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

        private void checkBoxATS_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBoxATS.Checked)
            {
                labelATMDEMaxS.Text = "Starting separation";
                labelATBEMaxS.Text = "Starting separation";
                angleEntryBoxATBEMinS.Enabled = false;
                angleEntryBoxATBHMinS.Enabled = false;
                angleEntryBoxATBHMaxS.Enabled = false;
                angleEntryBoxATMDEMinS.Enabled = false;
                angleEntryBoxATMDHMinS.Enabled = false;
                angleEntryBoxATMDHMaxS.Enabled = false;
            }
            else
            {
                labelATMDEMaxS.Text = "Easy max separation";
                labelATBEMaxS.Text = "Easy max separation";
                angleEntryBoxATBEMinS.Enabled = true;
                angleEntryBoxATBHMinS.Enabled = true;
                angleEntryBoxATBHMaxS.Enabled = true;
                angleEntryBoxATMDEMinS.Enabled = true;
                angleEntryBoxATMDHMinS.Enabled = true;
                angleEntryBoxATMDHMaxS.Enabled = true;
            }
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
            paramID = target.GetParamIdx("TargetTable", "Table");
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
            paramID = target.GetParamIdx("CursorPos/GadgetGain", "Table");
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
            paramID = target.GetParamIdx("WFTargetTable", "Table");
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
            paramID = target.GetParamIdx("BCStimTable", "Table");
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
            paramID = target.GetParamIdx("BFStimTable", "Table");
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
                } else if (paramControls[key].GetType() == typeof(RadioButton)) {
                    RadioButton rb = (RadioButton)paramControls[key];
                    paramValue = (rb.Checked ? 1.0 : 0.0);
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
                    } else if (paramControls[key].GetType() == typeof(RadioButton)) {
                        RadioButton rb = (RadioButton)paramControls[key];
                        rb.Checked = (bp.Parameters[key] > 0);
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