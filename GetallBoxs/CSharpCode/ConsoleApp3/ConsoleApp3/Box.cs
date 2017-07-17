using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    public class Box
    {
       

        long _Size;
        string _Typ;

        public string Typ
        {
            get
            {
                return _Typ;
            }

            set
            {
                _Typ = value;
            }
        }

        public long Size
        {
            get { return _Size; }
            set { _Size = value; }
        }

        public Box(string typ)
        {
            this.Typ = typ;
        }
    }
}
