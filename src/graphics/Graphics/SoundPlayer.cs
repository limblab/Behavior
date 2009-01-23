using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.DirectX;
using Microsoft.DirectX.DirectSound;

namespace BehaviorGraphics
{
    public class SoundPlayer
    {
        private Device device;
        private SoundPlayer.SoundTheme theme;

        private SecondaryBuffer abort, go, reward;

        public SoundPlayer(System.Windows.Forms.Control owner, SoundPlayer.SoundTheme theme)
        {
            this.theme = theme;
            device = new Device();
            device.SetCooperativeLevel(owner, CooperativeLevel.Priority);

            BufferDescription d = new BufferDescription();
            d.ControlVolume = true;

            System.Reflection.Assembly a = System.Reflection.Assembly.GetExecutingAssembly();
            System.IO.Stream s;

            s = a.GetManifestResourceStream(String.Format("BehaviorGraphics.tones.abort{0}.wav", (int)theme));
            abort = new SecondaryBuffer(s, d, device);

            s = a.GetManifestResourceStream(String.Format("BehaviorGraphics.tones.go{0}.wav", (int)theme));
            go = new SecondaryBuffer(s, d, device);

            s = a.GetManifestResourceStream(String.Format("BehaviorGraphics.tones.reward{0}.wav", (int)theme));
            reward = new SecondaryBuffer(s, d, device);
        }

        public void Play(SoundID id) {
            BufferPlayFlags flags = BufferPlayFlags.Default;

            if (id == SoundID.abort) {
                abort.Play(0, flags);
            } else if (id == SoundID.go) {
                go.Play(0, flags);
            } else if (id == SoundID.reward) {
                reward.Play(0, flags);
            }
        }

        public void Play(int id)
        {
            switch (id) {
                case 1:
                    Play(SoundID.go);
                    break;
                case 2:
                    Play(SoundID.reward);
                    break;
                case 3:
                    Play(SoundID.abort);
                    break;
            }
        }

        public SoundPlayer.SoundTheme Theme
        {
            get { return this.theme; }
        }

        public enum SoundID
        {
            abort,
            go,
            reward
        }

        public enum SoundTheme
        {
            Theme1 = 1,
            Theme2 = 2,
            Theme3 = 3
        }
    }
}
