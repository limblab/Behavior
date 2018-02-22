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
    public class MultiGadgetTarget
    {
        private double xPos, yPos, height, width;
        private int xVar, yVar;

        /// <summary>
        /// MultiGadgetTarget constructor.  Sets all values to a default of zero.
        /// </summary>
        public MultiGadgetTarget()
        {
            xPos = 0;
            yPos = 0;
            height = 0;
            width = 0;
            xVar = 0;
            yVar = 0;
        }

        public MultiGadgetTarget(double y, double h, double x, double w)
        {
            xPos = x;
            yPos = y;
            height = h;
            width = w;
            xVar = 0;
            yVar = 0;
        }

        public MultiGadgetTarget(double y, double h, double x, double w, int x_var, int y_var)
        {
            xPos = x;
            yPos = y;
            height = h;
            width = w;
            xVar = x_var;
            yVar = y_var;
        }

        /// <summary>
        /// X Position of the mid-point of the target
        /// </summary>
        [XmlElement("x")]
        public double TgtXPos
        {
            get { return xPos; }
            set { xPos = value; }
        }

        /// <summary>
        /// Y Position of the mid-point of the target
        /// </summary>
        [XmlElement("y")]
        public double TgtYPos
        {
            get { return yPos; }
            set { yPos = value; }
        }

        /// <summary>
        /// Height of the target (total allowable force error)
        /// </summary>
        [XmlElement("h")]
        public double TgtHeight
        {
            get { return height; }
            set { height = value; }
        }

        /// <summary>
        /// Width of the target (allowable difference between two forces)
        /// </summary>
        [XmlElement("w")]
        public double TgtWidth
        {
            get { return width; }
            set { width = value; }
        }

        /// <summary>
        /// X variation enabling for MVC target
        /// </summary>
        [XmlElement("xVar")]
        public int xVar_enable
        {
            get { return xVar; }
            set { xVar = value; }
        }

        /// <summary>
        /// X variation enabling for MVC target
        /// </summary>
        [XmlElement("yVar")]
        public int yVar_enable
        {
            get { return yVar; }
            set { yVar = value; }
        }
    }
}
