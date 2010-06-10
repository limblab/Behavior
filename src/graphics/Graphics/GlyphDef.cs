using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.DirectX;
using Microsoft.DirectX.Direct3D;
using System.Xml;
using System.Xml.Serialization;
using System.IO;

namespace BehaviorGraphics {
    public class GlyphDef {
        private string name, prefix;
        private int numGlyphs;

        public GlyphDef() {
            name = "";
            prefix = "";
            numGlyphs = 0;
        }

        public override string ToString() {
            return this.name;
        }

        public List<Texture> GetTextures(Device device) {
            System.Reflection.Assembly a = System.Reflection.Assembly.GetExecutingAssembly();

            List<Texture> txts = new List<Texture>();

            for (int i = 1; i <= NumGlyphs; i++) {
                System.IO.Stream s = a.GetManifestResourceStream(
                    String.Format("BehaviorGraphics.glyphs.{0}{1}.tga", prefix, i));
                Texture tmp = TextureLoader.FromStream(device, s);
                txts.Add(tmp);
            }
            
            return txts;
        }

        public string Name {
            get { return name; }
            set { name = value; }
        }

        public string Prefix {
            get { return prefix; }
            set { prefix = value; }
        }

        public int NumGlyphs {
            get { return numGlyphs; }
            set { numGlyphs = value; }
        }
    }

    public class GlyphDefs : List<GlyphDef>, IXmlSerializable {

        public static GlyphDefs FromXML() {
            GlyphDefs gds = new GlyphDefs();

            System.Reflection.Assembly a = System.Reflection.Assembly.GetExecutingAssembly();
            Stream reader = a.GetManifestResourceStream("BehaviorGraphics.config.GlyphDefs.xml");
            XmlSerializer s = new XmlSerializer(typeof(GlyphDefs));
            gds = (GlyphDefs)s.Deserialize(reader);
            reader.Close();

            return gds;
        }

        #region IXmlSerializable Members
        public System.Xml.Schema.XmlSchema GetSchema() {
            return null;
        }

        public void ReadXml(XmlReader reader) {
            XmlSerializer s = new XmlSerializer(typeof(GlyphDefs));

            reader.ReadStartElement("GlyphDefs");
            while (reader.NodeType != XmlNodeType.EndElement) {
                reader.ReadStartElement("GlyphDef");

                GlyphDef gd = new GlyphDef();
                gd.Name = reader.ReadElementContentAsString("Name", "");
                gd.NumGlyphs = reader.ReadElementContentAsInt("NumGlyphs", "");
                gd.Prefix = reader.ReadElementContentAsString("FilePrefix", "");
                this.Add(gd);
             
                reader.ReadEndElement();
            }
            reader.ReadEndElement();
        }

        public void WriteXml(XmlWriter writer) {
            throw new NotImplementedException();
        }

        #endregion
    }
}
