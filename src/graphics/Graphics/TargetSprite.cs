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
        Device device;

        public TargetSprite(Device device)
        {
            ul = new Vector3(0, 0, 0);
            lr = new Vector3(0, 0, 0);
            type = 0;
            this.device = device;
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

            switch (this.type)
            {
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

                default:
                    // do nothing
                    /* example sprite code.  This is not needed because target type 1 is drawn with polygons
                        Sprite s = new Sprite(device);
                        s.Begin(SpriteFlags.None);
                        s.Draw();
                        s.End();
                        s.Dispose();
                     */

                    break;
            }
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
        GreenTarget = 3
    }
}
