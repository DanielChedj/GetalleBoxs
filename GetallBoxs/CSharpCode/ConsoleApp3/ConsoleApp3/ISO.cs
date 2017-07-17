using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class ISO
    {
        private string path;

        public byte[] bytes;

        public List<Box> allBoxs = new List<Box>();

        public ISO(string path)
        {
            this.path = path;
            GetByte();
        }

        void GetByte()
        {

            bytes = File.ReadAllBytes(path);

        }

        public List<Box> GetBoxs()
        {
            List<Box> listeVonBoxen = new List<Box>();

            for (int i = 0; i < bytes.Length - 4; i++)
            {
                string s1 = Encoding.ASCII.GetString(new byte[] { bytes[i] });
                string s2 = Encoding.ASCII.GetString(new byte[] { bytes[i + 1] });
                string s3 = Encoding.ASCII.GetString(new byte[] { bytes[i + 2] });
                string s4 = Encoding.ASCII.GetString(new byte[] { bytes[i + 3] });

                if (s1 == "\0" | s1 == " " | s1 == null | s4 == "\0" | s4 == " " | s4 == null | s2 == "\0" | s2 == " " | s2 == null | s3 == "\0" | s3 == " " | s3 == null)
                {
                    continue;
                }

                string s = s1 + s2 + s3 + s4;

                foreach (var aktbox in allBoxs)
                {
                    if (s == aktbox.Typ)
                    {
                        aktbox.Size = int.Parse(bytes[i - 4].ToString()) + int.Parse(bytes[i - 3].ToString()) +
                                                  int.Parse(bytes[i - 2].ToString()) + int.Parse(bytes[i - 1].ToString());


                        listeVonBoxen.Add(aktbox);

                        break;
                    }
                }
            }

            return listeVonBoxen;

        }
    }
}
