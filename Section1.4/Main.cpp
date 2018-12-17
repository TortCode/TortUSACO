/*
ID: teerth.1
PROG: barn1
LANG: C++
*/
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	int M, S, C; // MAXBOARD, MAXSTALL, COWINSTALL
	fin >> M >> S >> C;
	if (M >= C) {
		fout << C << endl;
		goto finish;
	}

	int stalls[200];
	for (int i = 0; i < C; i++) {
		fin >> stalls[i];
	}
	fin.close();

	sort(stalls, stalls + C);
	int spaces[200];
	for (int i = 0; i < C - 1; i++) { //find space between consecutive stalls
		spaces[i] = stalls[i + 1] - stalls[i] - 1;
	}
	sort(spaces, spaces + C - 1);
	{
		int joinsNeeded = C - M;
		int blockedStalls = C;
		for (int i = 0; i < joinsNeeded; i++) { //merge with smallest gaps between stalls
			blockedStalls += spaces[i];
		}
		fout << blockedStalls << endl;
	}
finish:
	fout.close();
}