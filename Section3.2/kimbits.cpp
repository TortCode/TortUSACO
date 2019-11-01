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
	combo[0][0] = 1;
	int n, k;
	for (n = 0; n <= 31; n++) {
		combo[n][0] = 1;
		combo[n][n] = 1;
		numstrings[n][0] = 1;
		for (k = 1; k < n; k++) {
			combo[n][k] = combo[n - 1][k - 1] + combo[n - 1][k];
			numstrings[n][k] = numstrings[n][k - 1] + combo[n][k];
		}
		numstrings[n][n] = numstrings[n][n - 1] + 1;
	}
}
	
int N, L, I;
string toBinaryString(int n)
{
	string ret;
	while (n != 0) {
		ret = to_string(n & 1) + ret;
		n >>= 1;
	}
	while (ret.length() < N)
		ret = "0" + ret;
	return ret;
}

int main()
{
	ifstream input("kimbits.in");
	ofstream output("kimbits.out");
	input >> N >> L >> I;
	input.close();

	generate();
	
	int index = I;
	for(int i = 0, k = 0, len = L; index != 1; len--, i++) {
		k = 0;
		while (index > numstrings[k][len]) k++;
		pos[i] = k;
		index -= numstrings[k-1][len];
	}


	output << toBinaryString(ret) << endl;
	output.close();
}
