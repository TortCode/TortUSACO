/*
ID: teerth.1
PROG: prefix
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream input("prefix.in");
	ofstream output("prefix.out");

	int nprim = 0;
	string primitives[200];
	string p, s = "", temp;
	input >> p;
	while (p != ".") {
		primitives[nprim++] = p;
		input >> p;
	}
	input >> temp;
	while (!input.eof()) {
		s += temp;
		input >> temp;
	}

	int SLEN = s.length();
	bool poss[200'001]{ true };
	int i, j, len;
	for (i = 0; i <= SLEN; i++) {
		if (poss[i])
			for (j = 0; j < nprim; j++) {
				len = primitives[j].length();
				if (primitives[j] == s.substr(i, len)) //one-based for primitives; zero-based for string
					poss[i + len] = true;
			}
	}

	int pos;
	for (pos = SLEN; pos >= 0; pos--) if (poss[pos]) break;
	output << pos << '\n';
	output.close();
}
