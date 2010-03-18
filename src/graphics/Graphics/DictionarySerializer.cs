using System;
using System.Collections;
using System.Collections.Generic;
using System.Xml;
using System.Xml.Serialization;
using System.Xml.Schema;
using System.IO;

namespace BehaviorGraphics
{
    public class DictionarySerializer : IXmlSerializable
    {
        private IDictionary dictionary;

        public DictionarySerializer()
        {
            this.dictionary = new Dictionary<string, double>();
        }

        public DictionarySerializer(IDictionary dictionary)
        {
            this.dictionary = dictionary;
        }

        public IDictionary Dictionary
        {
            get { return dictionary; }
        }

        public static void Serialize(IDictionary dictionary, Stream stream)
        {
            DictionarySerializer ds = new DictionarySerializer(dictionary);
            XmlSerializer xs = new XmlSerializer(typeof(DictionarySerializer));
            xs.Serialize(stream, ds);
        }

        public static IDictionary Deserialize(Stream stream)
        {
            XmlSerializer xs = new XmlSerializer(typeof(DictionarySerializer));
            DictionarySerializer ds = (DictionarySerializer)xs.Deserialize(stream);

            return ds.dictionary;
        }

        XmlSchema IXmlSerializable.GetSchema()
        {
            return null;
        }

        void IXmlSerializable.ReadXml(XmlReader reader)
        {
            reader.Read();
            reader.ReadStartElement("dictionary");
            while (reader.NodeType != XmlNodeType.EndElement) {
                reader.ReadStartElement("item");
                string key = reader.ReadElementString("key");
                double value = double.Parse(reader.ReadElementString("value"));
                reader.ReadEndElement();
                reader.MoveToContent();
                dictionary.Add(key, value);
            }
            reader.ReadEndElement();
            reader.ReadEndElement();
        }

        void IXmlSerializable.WriteXml(XmlWriter writer)
        {
            writer.WriteStartElement("dictionary");
            foreach (object key in dictionary.Keys) {
                object value = dictionary[key];
                writer.WriteStartElement("item");
                writer.WriteElementString("key", key.ToString());
                writer.WriteElementString("value", value.ToString());
                writer.WriteEndElement();
            }
            writer.WriteEndElement();
        }
    }
}