/*
ID: teerth.1
PROG: kimbits
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

int numstrings[32][32]; // [l,c] -> numstrings of length l and at most c set bits
int pos[32]; // position of 1s

int generate(){
{
	int combo[32][32];
	int n, k;
	for (n = 0; n <= 31; n++) {
		combo[n][0] = 1;
		combo[n][n] = 1;
		for (k = 1; k < n; k++)
			combo[n][k] = combo[n - 1][k - 1] + combo[n - 1][k];
	}
	for (n = 0; n <= 31; n++) {
		numstrings[n][0] = 1;
		for (k = 1; k <= n; k++)
			numstrings[n][k] = numstrings[n][k-1] + combo[n][k];
	}
}

int main()
{
	int N, L, I;
	ifstream input("kimbits.in");
	ofstream output("kimbits.out");
	input >> N >> L >> I;
	input.close();

	generate();
	
	for(int index = I, i = 0, bits = L; index != 1; bits--, i++) {
		int k = 0;
		while (index > numstrings[k][bits]) k++;
		pos[i] = k;
		index -= numstrings[k-1][bits];
	}
	
	string ret;
	int strindex = 1;
	for (int i = 0; i < 32 && pos[i] != 0; i++) {
		while(strindex < pos[i]) {
			ret = "0" + ret;
			strindex++;
		}
		ret = "1" + ret;
		strindex++;
	}
	while(strindex <= N) {
		ret = "0" + ret;
		strindex++;
	}

	output << ret << endl;
	output.close();
}
