/*
ID: teerth.1
PROG: palsquare
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	int B;
	fin >> B;
	fin.close();

	char numeral[20] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J' };
	char remainder;
	for (int N = 1; N <= 300; N++) {
		int sq = N * N;

		string convertSquare = "";
		while (sq != 0) { //convert starting at least significant digit
			remainder = numeral[sq % B];
			sq /= B;
			convertSquare = remainder + convertSquare;
		}
		int len = convertSquare.length();

		bool isPal = true;
		for (int i = 0; i < (len / 2); i++) { // palindrome check
			if (convertSquare[i] != convertSquare[len - 1 - i]) {
				isPal = false;
				break;
			}
		}

		if (isPal) {
			string convertN = "";
			int calcN = N;
			while (calcN != 0) { //convert starting at least significant digit
				remainder = numeral[calcN % B];
				calcN /= B;
				convertN = remainder + convertN;
			}
			fout << convertN << " " << convertSquare << endl;
		}
	}

	fout.close();

}
