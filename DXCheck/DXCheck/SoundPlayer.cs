using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.DirectX;
using Microsoft.DirectX.DirectSound;

namespace DXCheck
{
    class SoundPlayer
    {
        private Device device;

        private SecondaryBuffer abort, go, reward;

        public SoundPlayer(System.Windows.Forms.Control owner)
        {
            device = new Device();
            device.SetCooperativeLevel(owner, CooperativeLevel.Priority);

            BufferDescription d = new BufferDescription();
            d.ControlVolume = true;

            System.Reflection.Assembly a = System.Reflection.Assembly.GetExecutingAssembly();
            System.IO.Stream s;

            s = a.GetManifestResourceStream("DXCheck.tones.abort.wav");
            abort = new SecondaryBuffer(s, d, device);

            s = a.GetManifestResourceStream("DXCheck.tones.go.wav");
            go = new SecondaryBuffer(s, d, device);

            s = a.GetManifestResourceStream("DXCheck.tones.reward.wav");
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

        public enum SoundID
        {
            abort,
            go,
            reward
        }
    }
}
