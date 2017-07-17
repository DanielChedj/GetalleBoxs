using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {

            List<Box> allBoxs = new List<Box>() {
                new Box("ftyp"),
                new Box("moov"),
                new Box("chtb"), new Box("ctts"), new Box("data"), new Box("mvhd"), new Box("priv"),
                new Box("esds"), new Box("free"), new Box("frma"), new Box("tfhd"), new Box("vmhd"),
                new Box("hmhd"), new Box("iviv"), new Box("stts"), new Box("wide"), new Box("mdhd"),
                new Box("mdat"), new Box("mp4s"), new Box("mpv4"), new Box("name"), new Box("sign"),
                new Box("stco"), new Box("tref"), new Box("trun"), new Box("tkhd"), new Box("user"),
                new Box("aaid"), new Box("akid"), new Box("atid"), new Box("clip"), new Box("apid"),
                new Box("aaid"), new Box("edts"), new Box("covr"), new Box("dinf"), new Box("disk"),
                new Box("geid"), new Box("cpil"), new Box("cprt"), new Box("gnre"), new Box("ilst"),
                new Box("minf"), new Box("hnti"), new Box("matt"), new Box("mdia"), new Box("moof"),
                new Box("hinf"), new Box("pinf"), new Box("plid"), new Box("rtng"), new Box("schi"),
                new Box("stbl"), new Box("sinf"), new Box("stik"), new Box("tmpo"), new Box("traf"), new Box("stsc"), new Box("stsz"), new Box("meta"),new Box("hdlr"),
                new Box("avcC"),new Box("dref"),new Box("elst"),
                new Box("trak"), new Box("trkn"), new Box("udta")
            };

            ISO iso = new ISO(@"C:\Users\HP\Downloads\test_timescapes.mp4");
            iso.allBoxs = allBoxs;
            List<Box> boxs = iso.GetBoxs();

            foreach (var VARIABLE in boxs)
            {
                Console.WriteLine( "Typ : " + VARIABLE.Typ + "     Groesse : " + VARIABLE.Size);
            }

            Console.ReadLine();
        }
    }
}
