using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.Xml.Serialization;

namespace BehaviorGraphics
{
    /// <summary>
    /// Holds a description of the stim table for the bump stim task.
    /// </summary>
    public class BumpChoiceStim
    {
        private int stimCode;
        private double PD;
        
        /// <summary>
        /// BumpChoiceStim constructor.  Sets all values to a default of -1.
        /// </summary>
        public BumpChoiceStim()
        {
            stimCode = -1;
            PD = -1;
        }

        public BumpChoiceStim(int sCode, double prefDir)
        {
            stimCode = sCode;
            PD = prefDir;
        }

        
        /// <summary>
        /// Stimulation code
        /// </summary>
        [XmlElement("StimCode")]
        public int StimCodeVar
        {
            get { return stimCode; }
            set { stimCode = value; }
        }

        /// <summary>
        /// Preferred direction
        /// </summary>
        [XmlElement("PD")]
        public double PDVar
        {
            get { return PD; }
            set { PD = value; }
        }

    }
}
