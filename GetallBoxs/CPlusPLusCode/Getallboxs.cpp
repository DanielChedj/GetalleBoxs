// ConsoleApplication1.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Box
{
public:
	char Typ;
	long Groesse;
};

class ISO
{
public:
	vector<char> allBoxsTyp;

private:
	vector<char> Buffer;

	//Hier werde ich alle Bytes von dem MP4 extrahieren
public:
	bool ReadAllBytes(char const* filename)
	{
		bool pruefer;

		ifstream ifs;
		ifs.open(filename, ios::binary | ios::ate);

		// Pruefe ob die Datei geöffnet ist
		if (ifs.is_open())
		{
			try
			{
				ifstream::pos_type pos = ifs.tellg();

				Buffer.resize(pos);

				ifs.seekg(0, ios::beg);

				ifs.read(&Buffer[0], pos);

				pruefer = true;
			}
			catch (char ex)
			{
				cout << "Fehler " << ex;
			}
		}

		else
		{
			cout << "Feler beim Oeffnen der Datei " << endl;
			pruefer = false;

		}

		return pruefer;
	}

	// Hier wrid ein Hexadecimal in einem Ascii und in Integer konvertiert.  
private:
	char hexToAscii(char *Hex)
	{
		char hex[4];
		char *result;

		hex[0] = '0';
		hex[0] = 'x';
		hex[0] = Hex[1];
		hex[0] = Hex[2];


		return strtol(hex, &result, 16);
	}

	//Hier analysiere ich die Bytes der MP4 Datei und extrahiere ich alle Box (Typ und Groeße)
public:
	vector<Box> GetBoxs()
	{
		vector<Box> ListeVonBoxen;

		for (size_t i = 0; i < Buffer.size() - 4; i++)
		{
			char s1 = hexToAscii(&Buffer[i]);
			char s2 = hexToAscii(&Buffer[i + 1]);
			char s3 = hexToAscii(&Buffer[i + 2]);
			char s4 = hexToAscii(&Buffer[i + 3]);

			if (s1 == '\0' | s1 == ' ' | s1 == NULL | s2 == '\0' | s2 == ' ' | s2 == NULL | s3 == '\0' | s3 == ' ' | s3 == NULL | s4 == '\0' | s4 == ' ' | s4 == NULL)
			{
				continue;
			}

			char s = s1 + s2 + s3 + s4;

			for each(auto boxtyp in allBoxsTyp)
			{
				if (s == boxtyp)
				{
					Box AktuellBox;

					AktuellBox.Groesse = hexToAscii(&Buffer[i - 4]) + hexToAscii(&Buffer[i - 3]) +
						hexToAscii(&Buffer[i - 2]) + hexToAscii(&Buffer[i - 1]);

					AktuellBox.Typ = boxtyp;

					ListeVonBoxen.push_back(AktuellBox);

					break;
				}
			}
		}
		return ListeVonBoxen;
	}
};

int main()
{
	vector<char> allboxtyp;
	allboxtyp.push_back('ftyp');
	allboxtyp.push_back('moov');
	allboxtyp.push_back('chtb');	allboxtyp.push_back('ctts');	allboxtyp.push_back('data');	allboxtyp.push_back('mvhd');	allboxtyp.push_back('priv');
	allboxtyp.push_back('esds');	allboxtyp.push_back('free');	allboxtyp.push_back('frma');	allboxtyp.push_back('tfhd');	allboxtyp.push_back('vmhd');
	allboxtyp.push_back('hmhd');	allboxtyp.push_back('iviv');	allboxtyp.push_back('stts');	allboxtyp.push_back('wide');	allboxtyp.push_back('mdhd');
	allboxtyp.push_back('mdat');	allboxtyp.push_back('mp4s');	allboxtyp.push_back('mpv4');	allboxtyp.push_back('name');	allboxtyp.push_back('sign');
	allboxtyp.push_back('stco');	allboxtyp.push_back('tref');	allboxtyp.push_back('trun');	allboxtyp.push_back('tkhd');	allboxtyp.push_back('user');
	allboxtyp.push_back('aaid');	allboxtyp.push_back('akid');	allboxtyp.push_back('atid');	allboxtyp.push_back('clip');	allboxtyp.push_back('apid');
	allboxtyp.push_back('aaid');	allboxtyp.push_back('edts');	allboxtyp.push_back('covr');	allboxtyp.push_back('dinf');	allboxtyp.push_back('disk');
	allboxtyp.push_back('geid');	allboxtyp.push_back('cpil');	allboxtyp.push_back('cprt');	allboxtyp.push_back('gnre');	allboxtyp.push_back('ilst');
	allboxtyp.push_back('minf');	allboxtyp.push_back('hnti');	allboxtyp.push_back('matt');	allboxtyp.push_back('mdia');	allboxtyp.push_back('moof');
	allboxtyp.push_back('hinf');	allboxtyp.push_back('pinf');	allboxtyp.push_back('plid');	allboxtyp.push_back('rtng');	allboxtyp.push_back('schi');
	allboxtyp.push_back('stbl');	allboxtyp.push_back('sinf');	allboxtyp.push_back('stik');	allboxtyp.push_back('tmpo');	allboxtyp.push_back('traf');
	allboxtyp.push_back('trak');	allboxtyp.push_back('trkn');	allboxtyp.push_back('udta');

	ISO iso;

	iso.allBoxsTyp = allboxtyp;
	bool TestIfOpen;

	TestIfOpen = iso.ReadAllBytes("C:\\Users\HP\Documents\diagramm.txt");

	if (TestIfOpen)
	{
		vector<Box> Result = iso.GetBoxs();

		for each (auto item in Result)
		{
			cout << "Typ : " << item.Typ << "Groesse : " << item.Groesse;
		}
	}

	system("PAUSE");

	return 0;
}

