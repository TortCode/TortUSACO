/*
ID: teerth.1
PROG: namenum
LANG: C++
*/
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <map>
using namespace std;

int main()
{
	ifstream fin("namenum.in");
	ifstream dict("dict.txt");
	ofstream fout("namenum.out");
	map<char, array<char, 3>> Keypad = {
		{'2',{'A','B','C'}},
		{'3',{'D','E','F'}},
		{'4',{'G','H','I'}},
		{'5',{'J','K','L'}},
		{'6',{'M','N','O'}},
		{'7',{'P','R','S'}},
		{'8',{'T','U','V'}},
		{'9',{'W','X','Y'}}
	};

	string serial;
	fin >> serial;
	const int serlen = serial.length();
	fin.close();

	string s;
	vector<string> dictionary;
	while (!dict.eof()) {
		dict >> s;
		if (s.length() == serlen) { //same len as serial no.
			dictionary.push_back(s);
		}
	}
	dict.close();

	int totalMatch = 0;
	for (string name : dictionary) {
		bool match = true;
		char serC, nameC;
		for (int i = 0; i < serlen; i++) {
			serC = serial[i];
			nameC = name[i];
			if ((nameC != Keypad[serC][0]) && (nameC != Keypad[serC][1]) && (nameC != Keypad[serC][2])) {
				match = false;
				break;
			}
		}

		if (match) {
			totalMatch++;
			fout << name << endl;
		}
	}
	if (totalMatch == 0) {
		fout << "NONE" << endl;
	}
	fout.close();
}
