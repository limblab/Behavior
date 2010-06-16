using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;
using Microsoft.DirectX;
using Microsoft.DirectX.Direct3D;

namespace BehaviorGraphics
{
    public class TargetSprite
    {
        private Vector3 ul, lr;
        private TargetSpriteType type;
        private List<Texture> glyphTextures;
        private Texture errorTexture;
        Material material;
        Device device;

        public TargetSprite(Device device)
        {
            this.device = device;
            Setup();

            glyphTextures = new List<Texture>();
            glyphTextures.Add(errorTexture);            
        }

        public TargetSprite(Device device, List<Texture> glyphTextures) {
            this.device = device;
            Setup();

            this.glyphTextures = glyphTextures;
        }

        private void Setup()
        {
            ul = new Vector3(0, 0, 0);
            lr = new Vector3(0, 0, 0);
            type = 0;
            glyphTextures = new List<Texture>();

            material = new Material();
            material.Diffuse = Color.White;
            material.Specular = Color.LightGray;
            material.SpecularSharpness = 15.0f;

            System.Reflection.Assembly a = System.Reflection.Assembly.GetExecutingAssembly();
            System.IO.Stream s = a.GetManifestResourceStream("BehaviorGraphics.glyphs.error.tga");
            errorTexture = TextureLoader.FromStream(device, s);
        }
        
        public Vector3 UL
        {
            get { return new Vector3(ul.X, ul.Y, 0); }
            set { ul = value; }
        }
        public Vector3 LR
        {
            get { return new Vector3(lr.X, lr.Y, 0); }
            set { lr = value; }
        }

        public TargetSpriteType Type { get { return type; } set { type = value; } }

        public void Draw()
        {
            CustomVertex.TransformedColored[] vertices;
            Texture texture;
            Vector4 p = new Vector4();
            Vector4 d = new Vector4();
            Vector3 d3 = new Vector3();

            switch (this.type) {
                case TargetSpriteType.RedTarget:
                    /* Red square target */
                    vertices = new CustomVertex.TransformedColored[4];
                    vertices[0].Position = new Vector4(ul.X, ul.Y, 0f, 1f);
                    vertices[0].Color = Color.Red.ToArgb();
                    vertices[1].Position = new Vector4(ul.X, lr.Y, 0f, 1f);
                    vertices[1].Color = Color.Red.ToArgb();
                    vertices[2].Position = new Vector4(lr.X, lr.Y, 0f, 1f);
                    vertices[2].Color = Color.Red.ToArgb();
                    vertices[3].Position = new Vector4(lr.X, ul.Y, 0f, 1f);
                    vertices[3].Color = Color.Red.ToArgb();

                    device.VertexFormat = CustomVertex.TransformedColored.Format;
                    device.DrawUserPrimitives(PrimitiveType.TriangleFan, 2, vertices);
                    break;

                case TargetSpriteType.FCTarget:
                    /* White square target */
                    vertices = new CustomVertex.TransformedColored[4];
                    vertices[0].Position = new Vector4(ul.X, ul.Y, 0f, 1f);
                    vertices[0].Color = Color.White.ToArgb();
                    vertices[1].Position = new Vector4(ul.X, lr.Y, 0f, 1f);
                    vertices[1].Color = Color.White.ToArgb();
                    vertices[2].Position = new Vector4(lr.X, lr.Y, 0f, 1f);
                    vertices[2].Color = Color.White.ToArgb();
                    vertices[3].Position = new Vector4(lr.X, ul.Y, 0f, 1f);
                    vertices[3].Color = Color.White.ToArgb();

                    device.VertexFormat = CustomVertex.TransformedColored.Format;
                    device.DrawUserPrimitives(PrimitiveType.TriangleFan, 2, vertices);

                    break;

                case TargetSpriteType.GreenTarget:
                    /* White square target */
                    vertices = new CustomVertex.TransformedColored[4];
                    vertices[0].Position = new Vector4(ul.X, ul.Y, 0f, 1f);
                    vertices[0].Color = Color.Green.ToArgb();
                    vertices[1].Position = new Vector4(ul.X, lr.Y, 0f, 1f);
                    vertices[1].Color = Color.Green.ToArgb();
                    vertices[2].Position = new Vector4(lr.X, lr.Y, 0f, 1f);
                    vertices[2].Color = Color.Green.ToArgb();
                    vertices[3].Position = new Vector4(lr.X, ul.Y, 0f, 1f);
                    vertices[3].Color = Color.Green.ToArgb();

                    device.VertexFormat = CustomVertex.TransformedColored.Format;
                    device.DrawUserPrimitives(PrimitiveType.TriangleFan, 2, vertices);

                    break;

                case TargetSpriteType.WallColisionTarget:
                    p.X = (lr - ul).Y / 3.0f;
                    p.Y = (ul - lr).X / 3.0f;
                    d3 = (15 * (lr - ul));
                    d = new Vector4(d3.X, d3.Y, d3.Z, 1f);

                    /* Wall */
                    vertices = new CustomVertex.TransformedColored[4];
                    vertices[0].Position = new Vector4(ul.X + p.X - d.X, ul.Y + p.Y - d.Y, 0f, 1f);
                    vertices[0].Color = Color.Blue.ToArgb();
                    vertices[1].Position = new Vector4(lr.X + p.X + d.X, lr.Y + p.Y + d.Y, 0f, 1f);
                    vertices[1].Color = Color.Blue.ToArgb();
                    vertices[2].Position = new Vector4(lr.X + d.X, lr.Y + d.Y, 0f, 1f);
                    vertices[2].Color = Color.Blue.ToArgb();
                    vertices[3].Position = new Vector4(ul.X - d.X, ul.Y - d.Y, 0f, 1f);
                    vertices[3].Color = Color.Blue.ToArgb();

                    device.VertexFormat = CustomVertex.TransformedColored.Format;
                    device.DrawUserPrimitives(PrimitiveType.TriangleFan, 2, vertices);

                    /* Goal */
                    vertices = new CustomVertex.TransformedColored[4];
                    vertices[0].Position = new Vector4(ul.X + p.X, ul.Y + p.Y, 0f, 1f);
                    vertices[0].Color = Color.Red.ToArgb();
                    vertices[1].Position = new Vector4(lr.X + p.X, lr.Y + p.Y, 0f, 1f);
                    vertices[1].Color = Color.Red.ToArgb();
                    vertices[2].Position = new Vector4(lr.X, lr.Y, 0f, 1f);
                    vertices[2].Color = Color.Red.ToArgb();
                    vertices[3].Position = new Vector4(ul.X, ul.Y, 0f, 1f);
                    vertices[3].Color = Color.Red.ToArgb();

                    device.VertexFormat = CustomVertex.TransformedColored.Format;
                    device.DrawUserPrimitives(PrimitiveType.TriangleFan, 2, vertices);

                    break;

                case TargetSpriteType.RedArc:
                    /* Red square target */
                    vertices = getArcVertices(ul, lr, Color.Red);
                   
                    device.VertexFormat = CustomVertex.TransformedColored.Format;
                    device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 100, vertices);

                    break;

                case TargetSpriteType.WhiteArc:
                    /* Red square target */
                    vertices = getArcVertices(ul, lr, Color.White);

                    device.VertexFormat = CustomVertex.TransformedColored.Format;
                    device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 100, vertices);

                    break;

                default:

                    // See if we are one of the glyph types
                    if ((int)this.type >= 16 && (int)this.type <= 31) {
                        int glyphID = ((int)this.type - 16);
                        try {
                            texture = glyphTextures[glyphID];
                        } catch (ArgumentOutOfRangeException) {
                            texture = errorTexture;
                        }

                        CustomVertex.TransformedTextured[] txtVert = 
                            new CustomVertex.TransformedTextured[4];
                        txtVert[0].Position = new Vector4(ul.X, ul.Y, 0f, 1f);
                        txtVert[0].Tu = 0;
                        txtVert[0].Tv = 0;
                        txtVert[1].Position = new Vector4(ul.X, lr.Y, 0f, 1f);
                        txtVert[1].Tu = 0;
                        txtVert[1].Tv = 1;
                        txtVert[2].Position = new Vector4(lr.X, lr.Y, 0f, 1f);
                        txtVert[2].Tu = 1;
                        txtVert[2].Tv = 1;
                        txtVert[3].Position = new Vector4(lr.X, ul.Y, 0f, 1f);
                        txtVert[3].Tu = 1;
                        txtVert[3].Tv = 0;
                        device.VertexFormat = CustomVertex.TransformedTextured.Format;
                        device.SetTexture(0, texture);
                        device.Material = material;
                        device.DrawUserPrimitives(PrimitiveType.TriangleFan, 2, txtVert);
                    }
                    // Otherwise do nothing


                    /* example sprite code.  This is not needed because target type 1 is drawn with polygons
                        Sprite s = new Sprite(device);
                        s.Begin(SpriteFlags.None);
                        s.Draw();
                        s.End();
                        s.Dispose();
                     */

                    break;
            }

            device.SetTexture(0, null);
        }

        private CustomVertex.TransformedColored[] getArcVertices(Vector3 innerStart, Vector3 outerStop, Color c)
        {
            CustomVertex.TransformedColored[] vertices = new CustomVertex.TransformedColored[200];
            float start = (float)Math.Atan2((double)innerStart.Y, (double)innerStart.X);
            float length = (float)Math.Atan2((double)outerStop.Y, (double)outerStop.X) - start;
            float inner = (float)Math.Sqrt( (double)(innerStart.X*innerStart.X + innerStart.Y*innerStart.Y) );
            float outer = (float)Math.Sqrt((double)(outerStop.X * outerStop.X + outerStop.Y * outerStop.Y)); ;

            for (int i = 0; i < 100; i++) {
                double theta = start + i / 100 * length;

                vertices[2 * i].Position = new Vector4(inner*(float)Math.Cos(theta), inner*(float)Math.Sin(theta), 0f, 1f);
                vertices[2 * i].Color = c.ToArgb();
                                
                vertices[2 * i + 1].Position = new Vector4(outer * (float)Math.Cos(theta), outer * (float)Math.Sin(theta), 0f, 1f);
                vertices[2 * i + 1].Color = c.ToArgb();
            }

            return vertices;
        }

        public void SetPosition(float left, float top, float right, float bottom)
        {
            ul.X = left;
            ul.Y = top;
            lr.X = right;
            lr.Y = bottom;
        }

    }

    public enum TargetSpriteType
    {
        None = 0,
        RedTarget = 1,
        FCTarget = 2,
        GreenTarget = 3,
        WallColisionTarget = 4,
        RedArc = 5,
        WhiteArc = 6,
        Glyph0 = 16,
        Glyph1 = 17,
        Glyph2 = 18,
        Glyph3 = 19,
        Glyph4 = 20,
        Glyph5 = 21,
        Glyph6 = 22,
        Glyph7 = 23,
        Glyph8 = 24,
        Glyph9 = 25,
        Glyph10 = 26,
        Glyph11 = 27,
        Glyph12 = 28,
        Glyph13 = 29,
        Glyph14 = 30,
        Glyph15 = 31,
    }
}
