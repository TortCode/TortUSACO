/*
ID: teerth.1
PROG: beads
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

int main() {
	int N;
	string beads;

	ifstream input("beads.in");
	input >> N;
	input >> beads;
	input.close();
	beads = beads + beads; //duplication creates pseudo-circular string
	int len = N * 2;

	int max = 0;
	int s1, s2, sum; //ends of side1 and side2 and sum
	char clr; //clr searched for {r,b,w}

	for (int i = 1; i < len; i += s1) { //skip to end of forward segment each time
		s2 = 0;
		s1 = 0;

		clr = beads[i];
		for (int j = i; j < len; j++) { //forwards
			if (clr == 'w') clr = beads[j];
			//color indeterminate('w') until nonwhite found
			if (beads[j] == clr || beads[j] == 'w') s1++;
			else break;
		}

		clr = beads[i - 1];
		for (int j = i - 1; j >= 0; j--) { //backwards
			if (clr == 'w') clr = beads[j];
			//color indeterminate('w') until nonwhite found
			if (beads[j] == clr || beads[j] == 'w') s2++;
			else break;
		}

		if ((sum = s1 + s2) > max) max = sum; //get new max
	}
	if (max > N) max = N;
	ofstream output("beads.out");
	output << max << endl;
	output.close();
}