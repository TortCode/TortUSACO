/*
ID: teerth.1
PROG: dualpal
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");

	int N, S;
	fin >> N >> S;
	fin.close();

	int doublePalCount = 0; //counts how many nums so far are double palindromes
	for (int test = S + 1; doublePalCount != N; test++) {

		int palCheck = 0; //count how in how base is palindromic
		for (int base = 2; base <= 10; base++) {
			string convert = "";
			string remainder;
			int testCopy = test;
			while (testCopy != 0) { //convert starting at least significant digit
				remainder = testCopy % base;
				testCopy /= base;
				convert = remainder + convert;
			}
			
			bool isPal = true;
			int len = convert.length();
			for (int i = 0; i < (len / 2); i++) { // palindrome check
				if (convert[i] != convert[len - 1 - i]) {
					isPal = false;
					break;
				}
			}
			if (isPal) {
				palCheck++;
				if (palCheck == 2) break;
			}
		}

		if (palCheck == 2) {
			doublePalCount++;
			fout << test << endl;
		}
	}

	fout.close();
}
