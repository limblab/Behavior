using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.Xml.Serialization;
using XPCAPICOMLib;
using System.IO;


namespace BehaviorGraphics
{
    public class LabParam
    {
        private String blockName;
        private String paramName;
        private double paramValue;

        public LabParam() { }

        public void SendToTarget(xPCTarget target)
        {
            Array param = Array.CreateInstance(typeof(double), 1);
            int paramID;

            paramID = target.GetParamIdx(blockName, paramName);
            if (paramID >= 0) {
                param.SetValue(paramValue, 0);
                target.SetParam(paramID, ref param);
            }
        }

        #region Public Properties
        [XmlElement("Block")]
        public String Block
        {
            get { return blockName; }
            set { blockName = value; }
        }

        [XmlElement("Name")]
        public String Parameter
        {
            get { return paramName; }
            set { paramName = value; }
        }

        [XmlElement("Value")]
        public double Value
        {
            get { return paramValue; }
            set { paramValue = value; }
        }
        #endregion
    }

    [XmlRoot("LabConfig")]
    public class LabSpecification
    {
        [XmlAttribute("lab")]
        public int Lab;

        private List<LabParam> parameters;

        public void SendToTarget(xPCTarget target)
        {
            foreach (LabParam p in parameters) {
                p.SendToTarget(target);
            }
        }

        [XmlIgnore]
        public List<LabParam> Parameters
        {
            get { return parameters; }
            set { parameters = value; }
        }

        [XmlArray("LabParamList")]
        public LabParam[] ParamArray
        {
            get
            {
                LabParam[] lpa = new LabParam[parameters.Count];
                parameters.CopyTo(lpa);
                return lpa;
            }
            set
            {
                if (value == null) return;
                LabParam[] lpa = (LabParam[])value;
                if (parameters != null) {
                    parameters.Clear();
                } else {
                    parameters = new List<LabParam>();
                }
                foreach (LabParam lp in lpa) {
                    parameters.Add(lp);
                }
            }
        }
    }

    public class LabList : List<LabSpecification>, IXmlSerializable
    {
        public static LabList FromXML()
        {
            LabList labList = new LabList();

            System.Reflection.Assembly a = System.Reflection.Assembly.GetExecutingAssembly();
            Stream reader = a.GetManifestResourceStream("BehaviorGraphics.config.LabConfigs.xml");
            XmlSerializer s = new XmlSerializer(typeof(LabList));
            labList = (LabList)s.Deserialize(reader);
            reader.Close();

            return labList;
        }

        public LabSpecification GetLabSpecification(int lab)
        {
            foreach (LabSpecification ls in this) {
                if (ls.Lab == lab) {
                    return ls;
                }
            }

            throw new Exception("The specified lab could not be found");
        }

        #region IXmlSerializable Members
        public System.Xml.Schema.XmlSchema GetSchema()
        {
            return null;
        }

        public void ReadXml(XmlReader reader)
        {
            XmlSerializer s = new XmlSerializer(typeof(LabList));

            reader.ReadStartElement("LabList");
            while (reader.NodeType != XmlNodeType.EndElement) {
                //reader.ReadStartElement("LabConfig");

                String str = reader.ReadOuterXml();

                XmlSerializer labConfigSerializer = new XmlSerializer(typeof(LabSpecification));
                StringReader sr = new StringReader(str);
                LabSpecification ls = (LabSpecification)labConfigSerializer.Deserialize(sr);

                this.Add(ls);

                /*
                CursorDef cd = new CursorDef();
                cd.Name = reader.ReadElementContentAsString("Name", "");
                cd.File = reader.ReadElementContentAsString("File", "");
                cd.X = reader.ReadElementContentAsFloat("X", "");
                cd.Y = reader.ReadElementContentAsFloat("Y", "");
                this.Add(cd);
                */

                //reader.ReadEndElement();
            }
            reader.ReadEndElement();
        }

        public void WriteXml(XmlWriter writer)
        {
            throw new NotImplementedException();
        }
        #endregion
    }
}
