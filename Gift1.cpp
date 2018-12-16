/*
ID: teerth.1
PROG: gift1
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

int NP;

inline int findName(string arr[], string name)
{
	for (int i = 0; i < NP; i++)
		if (arr[i] == name)
			return i;
	return -1;
}

int main()
{
	ifstream input("gift1.in");
	ofstream output("gift1.out");
	input >> NP; // line 1
	string persons[10];
	int money[10]{ 0 };

	for (int i = 0; i < NP; i++) //lines 2-NP+1
		input >> persons[i];

	string giver;
	string recip;
	int gift; //amount to be given by giver
	int split; //people given to by giver

	for (int i = 0; i < NP; i++) {
		input >> giver >> gift >> split;
		if (split != 0) {
			int eachG = gift / split;
			money[findName(persons, giver)] -= eachG * split; //take away give account

			for (int j = 0; j < split; j++) { //take in recip
				input >> recip;
				money[findName(persons, recip)] += eachG; //add to recip account
			}
		}
	}
	for (int i = 0; i < NP; i++) {
		output << persons[i] << " " << money[i] << endl;
	}
	input.close(); output.close();
}
