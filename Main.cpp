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

	int max = 0;
	int s1, s2; //ends of side1 and side2
	char clr; //char we are searching for {r,b,w}
	beads = beads + beads; //duplication creates pseudo-circular string

	for (int i = 1; i < N * 2;) {  //skip thru split pt's P(x)
		s2 = 0;
		s1 = 0;
		clr = beads[i];
		for (int j = i; j < N * 2;) { //find longest segment going clockwise from split pt
			if (clr == 'w' && beads[j] != 'w') clr = beads[j]; //if clr was 'w' but other color found, change to new colors
			if (beads[j] == clr || beads[j] == 'w') {
				s1++;
				j++;
			}
			else break;
		}
		clr = beads[i - 1];
		for (int j = i - 1; j >= 0;) { //find longest segment going clockwise from split pt
			if (clr == 'w' && beads[j] != 'w') clr = beads[j]; //if clr was 'w' but other color found, change to new colors
			if (beads[j] == clr || beads[j] == 'w') {
				s2++;
				j--;
			}
			else break;
		}

		max = s1 + s2 > max ? s1 + s2 : max; //get new max
		i += s1; //go to end of segment
	}
	if (max > N) max = N;
	ofstream output("beads.out");
	output << max << endl;
	output.close();
}