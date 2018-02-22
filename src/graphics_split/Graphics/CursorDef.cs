using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.DirectX;
using Microsoft.DirectX.Direct3D;
using System.Xml;
using System.Xml.Serialization;
using System.IO;

namespace BehaviorGraphics
{
    public class CursorDef
    {
        float x, y;
        string name, filename;

        public CursorDef()
        {
            x = 0;
            y = 0;
            name = "";
            filename = "";
        }

        public override string ToString()
        {
            return name;
        }

        public Texture GetTexture(Device device)
        {
            System.Reflection.Assembly a = System.Reflection.Assembly.GetExecutingAssembly();
            System.IO.Stream s = a.GetManifestResourceStream("BehaviorGraphics.textures." + this.File);
            return TextureLoader.FromStream(device, s);
        }

        public Vector3 Center
        {
            get { return new Vector3(x, y, 0); }
        }

        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        public string File
        {
            get { return filename; }
            set { filename = value; }
        }

        public float X
        {
            get { return x; }
            set { x = value; }
        }

        public float Y
        {
            get { return y; }
            set { y = value; }
        }
    }

    public class CursorDefs : List<CursorDef>, IXmlSerializable
    {
        public static CursorDefs FromXML()
        {
            CursorDefs cds = new CursorDefs();

            System.Reflection.Assembly a = System.Reflection.Assembly.GetExecutingAssembly();
            Stream reader = a.GetManifestResourceStream("BehaviorGraphics.config.CursorDefs.xml");
            XmlSerializer s = new XmlSerializer(typeof(CursorDefs));
            cds = (CursorDefs)s.Deserialize(reader);
            reader.Close();

            return cds;
        }

        #region IXmlSerializable Members

        public System.Xml.Schema.XmlSchema GetSchema()
        {
            return null;
        }

        public void ReadXml(XmlReader reader)
        {
            XmlSerializer s = new XmlSerializer(typeof(CursorDefs));

            reader.ReadStartElement("CursorDefs");
            while (reader.NodeType != XmlNodeType.EndElement) {
                reader.ReadStartElement("CursorDef");
                
                CursorDef cd = new CursorDef();
                cd.Name = reader.ReadElementContentAsString("Name", "");
                cd.File = reader.ReadElementContentAsString("File", "");
                cd.X = reader.ReadElementContentAsFloat("X", "");
                cd.Y = reader.ReadElementContentAsFloat("Y", "");
                this.Add(cd);

                reader.ReadEndElement();
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
