/*
ID: teerth.1
PROG: kimbits
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

int combo[32][32];
int numstrings[32][32];
int pos[32]; // position of 1s

int generate(){
{
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

int find(int index, )
{
	int i = 1;
	int k = 0;
	int len = L;
	while (index != 1) {
		while (index > numstrings[k][)
	}
}
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



	output << toBinaryString(ret) << endl;
	output.close();
}