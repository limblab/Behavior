using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.Xml.Serialization;

namespace BehaviorGraphics
{
    /// <summary>
    /// Holds a description of the force target for the Multi-gadget task.
    /// </summary>
    public class AnIsoForces
    {
        public double number, dir, force;

        /// <summary>
        /// MultiGadgetTarget constructor.  Sets all values to a default of zero.
        /// </summary>
        public AnIsoForces()
        {
            number = 1;
            dir = 0;
            force = 1;
        }

        public AnIsoForces(double num, double dir1, double force1)
        {
            number =num;
            dir = dir1;
            force = force1;
        }

        /// <summary>
        /// X Position of the mid-point of the target
        /// </summary>
        public double getSetNum
        {
            get { return number; }
            set { number = value; }
        }

        /// <summary>
        /// Y Position of the mid-point of the target
        /// </summary>
        public double getSetDir
        {
            get { return dir; }
            set { dir = value; }
        }

        /// <summary>
        /// Height of the target (total allowable force error)
        /// </summary>
        public double getSetForce
        {
            get { return force; }
            set { force = value; }
        }
    }
}

