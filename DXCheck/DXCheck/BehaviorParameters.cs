using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.Serialization;
using System.Reflection;
using System.Xml;
using System.Xml.Serialization;

namespace DXCheck
{
    [XmlRoot]
    public class BehaviorParameters 
    {
        private Version version;
        private Dictionary<string, double> parameters;
        private double screenWidth;
        private LoadType lt;

        // center-out specific elements
        private CenterOutMode com;
        private int numTargetsCO;
        private bool idiotMode;

        // random-walk specific elements
        private int numTargetsRW;

        // forced-choice specific elements
        private bool trainingMode;
        private int numGradations;

        public BehaviorParameters()
        {
            version = Assembly.GetExecutingAssembly().GetName().Version;
            parameters = new Dictionary<string, double>();
        }
        
        #region publicAttributes
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
        public int NumTargetsCO
        {
            set { numTargetsCO = value; }
            get { return numTargetsCO; }
        }

        [XmlElement]
        public int NumTargetsRW
        {
            set { numTargetsRW = value; }
            get { return numTargetsRW; }
        }

        [XmlElement]
        public bool IdiotMode
        {
            set { idiotMode = value; }
            get { return idiotMode; }
        }

        [XmlElement]
        public bool TrainingMode
        {
            set { trainingMode = value; }
            get { return trainingMode; }
        }

        [XmlElement]
        public int NumGradations
        {
            set { numGradations = value; }
            get { return numGradations; }
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
            set { parameters = (Dictionary<string,double>)value.Dictionary; }
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
}
