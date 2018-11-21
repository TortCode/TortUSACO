/*
ID: teerth.1
PROG: milk2
LANG: C++
*/
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

struct Schedule {
	int begin, end;
};

int main() {
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	int N;
	fin >> N;
	Schedule milking[5000];
	for (int f = 0; f < N; f++) {
		fin >> milking[f].begin >> milking[f].end;
	}
	fin.close();

	sort(milking, milking + N, [](Schedule a, Schedule b) {
		return a.begin < b.begin;
	});
	int milk(0), noMilk(0);
	int t;
	Schedule streak = milking[0];
	for (int i = 1; i < N; i++) {
		if (milking[i].begin > streak.end) { //if interval in milking
			t = milking[i].begin - streak.end; //get noMilk interval
			if (t > noMilk) noMilk = t;

			t = streak.end - streak.begin; //get milk streak interval
			if (t > milk) milk = t;
			streak = milking[i];
		}
		else {
			if (milking[i].end > streak.end) //extend streak
				streak.end = milking[i].end;
		}
	}
	t = streak.end - streak.begin;
	if (t > milk) milk = t;

	fout << milk << " " << noMilk << endl;
	fout.close();
}