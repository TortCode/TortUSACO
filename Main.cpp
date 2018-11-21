/*
ID: teerth.1
PROG: gift1
LANG: C++
*/

#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream input("gift1.in");
	ofstream output("gift1.out");
	int NP;
	input >> NP; // line 1
	string persons[10];
	int money[10] = { 0 };

	for (int i = 0; i < NP; i++) { //lines 2-NP+1
		input >> persons[i];
	}

	string giver;
	int giverIdx;
	string recip;
	int recipIdx;
	int gift; //amount to be given by giver
	int split; //people given to by giver

	for (int i = 0; i < NP;) { // last parts
		input >> giver >> gift >> split; //load stoof about giving
		if (split != 0) {
			for (int j = 0; j < NP; j++) {
				if (persons[j] == giver) { //search for giverIdx
					giverIdx = j;
					break;
				}
			}

			int eachG = gift / split;
			money[giverIdx] -= eachG * split; //take away give account

			for (int j = 0; j < split; j++) { //take in recip
				input >> recip;

				for (int k = 0; k < NP; k++) {
					if (persons[k] == recip) { //search for recipIdx
						recipIdx = k;
						break;
					}
				}
				money[recipIdx] += eachG; //add to recip account
			}
		}
		i++; //next giver
	}

	for (int i = 0; i < NP; i++) { //output
		output << persons[i] << " " << money[i] << endl;
	}
}