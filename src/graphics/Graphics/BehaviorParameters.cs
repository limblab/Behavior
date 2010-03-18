using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.Serialization;
using System.Reflection;
using System.Xml;
using System.Xml.Serialization;

namespace BehaviorGraphics
{
    [XmlRoot]
    public class BehaviorParameters
    {
        private Version version;
        private Dictionary<string, double> parameters;
        private double screenWidth;
        private int cursor;
        private SoundPlayer.SoundTheme soundTheme;
        private LoadType lt;
        private LoadType lt2;
        private float verticalDisplacement;

        // Multi-Gadget specific elements
        private List<MultiGadgetTarget> mgTargets;
        private double[] mgGains = new double[4];
        private int bdCatchBlock;

        // Flextension specific elements
        private List<MultiGadgetTarget> wfTargets;

        // Bump choice specific elements
        private List<BumpChoiceStim> bcStim;

        // center-out specific elements
        private CenterOutMode com;

        #region publicAttributes
        
        public BehaviorParameters()
        {
            version = Assembly.GetExecutingAssembly().GetName().Version;
            parameters = new Dictionary<string, double>();
            mgTargets = new List<MultiGadgetTarget>();
            for (int i = 0; i < 16; i++)
                mgTargets.Add(new MultiGadgetTarget());
            wfTargets = new List<MultiGadgetTarget>();
            for (int i = 0; i < 16; i++)
                wfTargets.Add(new MultiGadgetTarget());
            bcStim = new List<BumpChoiceStim>();
            for (int i = 0; i < 16; i++)
                bcStim.Add(new BumpChoiceStim());
        }

        [XmlIgnore]
        public Dictionary<string, double> Parameters
        {
            set { parameters = value; }
            get { return parameters; }
        }

        [XmlElement]
        public double ScreenWidth
        {
            set { this.screenWidth = value; }
            get { return this.screenWidth; }
        }

        [XmlArray]
        public double[] MGGains
        {
            set {this.mgGains = value; }
            get { return this.mgGains; }

        }

        [XmlElement]
        public int BD_Catch_Block
        {
            set { this.bdCatchBlock = value; }
            get { return this.bdCatchBlock; }
        }

        [XmlElement]
        public float VerticalDisplacement
        {
            get { return this.verticalDisplacement; }
            set { this.verticalDisplacement = value; }
        }

        [XmlElement]
        public int Cursor
        {
            set { this.cursor = value; }
            get { return this.cursor; }
        }

        [XmlElement]
        public SoundPlayer.SoundTheme SoundTheme
        {
            set { this.soundTheme = value; }
            get { return this.soundTheme; }
        }

        [XmlElement]
        public CenterOutMode CenterOutMode
        {
            set { com = value; }
            get { return com; }
        }

        [XmlElement]
        public LoadType Load
        {
            set { lt = value; }
            get { return lt; }
        }

        [XmlElement]
        public LoadType LoadCatch
        {
            set { lt2 = value; }
            get { return lt2; }
        }

        [XmlAttribute]
        public string Version
        {
            get { return this.version.ToString(); }
            set { this.version = new Version(value); }
        }

        [XmlElement]
        public DictionarySerializer SerializedParameters
        {
            get { return new DictionarySerializer(parameters); }
            set { parameters = (Dictionary<string, double>)value.Dictionary; }
        }

        [XmlArray("MultiGadgetTargetList")]
        public MultiGadgetTarget[] MGTArray
        {
            get
            {
                MultiGadgetTarget[] mgta = new MultiGadgetTarget[mgTargets.Count];
                mgTargets.CopyTo(mgta);
                return mgta;
            }
            set
            {
                if (value == null) return;
                MultiGadgetTarget[] mgta = (MultiGadgetTarget[])value;
                mgTargets.Clear();
                foreach (MultiGadgetTarget mgt in mgta)
                {
                    mgTargets.Add(mgt);
                }
            }
        }

        [XmlIgnore]
        public List<MultiGadgetTarget> MGTargets
        {
            get { return mgTargets; }
            set { mgTargets = value; }
        }

        [XmlArray("FlextensionTargetList")]
        public MultiGadgetTarget[] WFTArray
        {
            get
            {
                MultiGadgetTarget[] wfta = new MultiGadgetTarget[wfTargets.Count];
                wfTargets.CopyTo(wfta);
                return wfta;
            }
            set
            {
                if (value == null) return;
                MultiGadgetTarget[] wfta = (MultiGadgetTarget[])value;
                wfTargets.Clear();
                foreach (MultiGadgetTarget wft in wfta)
                {
                    wfTargets.Add(wft);
                }
            }
        }
        
        [XmlIgnore]
        public List<MultiGadgetTarget> WFTargets
        {
            get { return wfTargets; }
            set { wfTargets = value; }
        }

        [XmlArray("BumpChoiceStimList")]
        public BumpChoiceStim[] BCSList
        {
            get
            {
                BumpChoiceStim[] bcsl = new BumpChoiceStim[bcStim.Count];
                bcStim.CopyTo(bcsl);
                return bcsl;
            }
            set
            {
                if (value == null) return;
                BumpChoiceStim[] bcsl = (BumpChoiceStim[])value;
                bcStim.Clear();
                foreach (BumpChoiceStim bcs in bcsl)
                {
                    bcStim.Add(bcs);
                }
            }
        }

        [XmlIgnore]
        public List<BumpChoiceStim> BCStims
        {
            get { return bcStim; }
            set { bcStim = value; }
        }

        #endregion
        }
    

        public enum CenterOutMode
        {
            Bump = 2,
            Catch = 1,
            None = 0
        }

        public enum LoadType
        {
            None = 0,
            Static = 1,
            Viscous = 2,
            Curl = 3,
            RotatingCurl = 4,
            Chaotic = 5
        }

        public enum LoadParam
        {
            None = 0,
            Static = 1,
            Chaotic = 2,
            Viscous = 3,
        }

        public enum BD_Catch_List
        {
            None  = 0,
            pct5  = 20,
            pct10 = 10,
            pct14 = 7,
            pct20 = 5,
            pct25 = 4,
            pct33 = 3,
        }
        public enum BD_Catch_Index
        {
            None = 0,
            pct5 = 1,
            pct10 = 2,
            pct14 = 3,
            pct20 = 4,
            pct25 = 5,
            pct33 = 6,
        }

}

