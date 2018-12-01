/*
ID: teerth.1
PROG: crypt1
LANG: C++
*/
#include <fstream>
#include <cmath>
#include <algorithm>

#define EXTRACTandCHECK_DIGIT(n) curDigit = n % 10; n /= 10; if (!isProperDigit[curDigit]) goto FAIL;

using namespace std;

int main()
{
	int N, digits[9];
	bool isProperDigit[10] = { false };

	ifstream fin("crypt1.in");
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> digits[i];
		isProperDigit[digits[i]] = true;
	}
	fin.close();
	/*
	 abc
	x de
	____
	 *** pp1
	***  pp2
	**** sum
	 */
	int solutions = 0;
	const int permutations = pow(N, 5);
	for (int i = 0, test = 0; i < permutations; test = ++i) {
		int a, b, c, d, e;	//N-ary notation for test permutation
		a = digits[test % N]; test /= N;
		b = digits[test % N]; test /= N;
		c = digits[test % N]; test /= N;
		d = digits[test % N]; test /= N;
		e = digits[test % N];

		int abc, pp1, pp2, sum;
		abc = 100 * a + 10 * b + c;
		pp1 = abc * e; if (pp1 > 999) goto FAIL; //Calculation and Digit Length Check
		pp2 = abc * d; if (pp2 > 999) goto FAIL;
		sum = 10 * pp2 + pp1; if (sum > 9999) goto FAIL;
		//brackets circumvent GOTO declaration skipping
		{
			int curDigit; //for operation of EXTRACTandCHECK_DIGIT
			int ct;
			for (ct = 0; ct < 3; ct++) { EXTRACTandCHECK_DIGIT(pp1) }
			for (ct = 0; ct < 3; ct++) { EXTRACTandCHECK_DIGIT(pp2) }
			for (ct = 0; ct < 4; ct++) { EXTRACTandCHECK_DIGIT(sum) }
		}
		solutions++; //if no FAIL
	FAIL:;
	}
	ofstream fout("crypt1.out");
	fout << solutions << endl;
	fout.close();
}
