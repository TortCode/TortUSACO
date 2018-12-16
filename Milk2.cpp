/*
ID: teerth.1
PROG: milk2
LANG: C++
*/
#include <fstream>
#include <string>
#include <bitset>

using namespace std;

int main() {
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");

	int N;
	fin >> N;
	bitset<1'000'000> milkOn;

	int earliest = 1000000, latest = 0;
	int start, end;

	for (int f = 0; f < N; f++) {
		fin >> start >> end;
		earliest = start < earliest ? start : earliest;
		latest = end > latest ? end : latest;
		for (int t = start; t < end; t++) {
			milkOn[t] = 1;
		}
	}
	fin.close();
	int milkCont = 0, noMilk = 0, streak = 0;
	bool streakb = 1;
	int i;
	for (i = earliest; i < latest; i++) {
		if (milkOn[i] != streakb) {
			if (streakb == 1) {
				milkCont = streak > milkCont ? streak : milkCont;
				streakb = 0;
			}
			else {
				noMilk = streak > noMilk ? streak : noMilk;
				streakb = 1;
			}
			streak = 0;
		}

		streak++;

	}
	if (i == latest && streak > milkCont) milkCont = streak;

	fout << milkCont << " " << noMilk << endl;
	fout.close();


}
