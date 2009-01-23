using System;
using System.Collections.Generic;
using System.Text;

namespace DXCheck
{
    public struct Box
    {
        public float Left;
        public float Right;
        public float Top;
        public float Bottom;

        public Box(float x1, float y1, float x2, float y2)
        {
            this.Left = x1;
            this.Right = x2;
            this.Top = y1;
            this.Bottom = y2;
        }

        public override string ToString()
        {
            return String.Format("( ({0}, {1}), ({2}, {3}) )", Left, Top, Right, Bottom);
        }
    }
}
