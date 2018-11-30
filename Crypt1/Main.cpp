/*
ID: teerth.1
PROG: crypt1
LANG: C++
*/
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#define ISPROPERDIG(x) if (find(digits, digits + N, x) == (digits + N)) goto fail; //if no match for x in digits, FAIL

using namespace std;

int main()
{
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	int N;
	int digits[10];
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> digits[i];
	}
	fin.close();
	/*
	 abc
	x de
	____
	 *** pp1
	***  pp2
	----
	**** sum
	 */
	int solutions = 0;
	for (int i = 0; i < pow(N, 5); i++) {
		int test = i;	//N-ary notation for test case
		int a = digits[test % N];
		test /= N;
		int b = digits[test % N];
		test /= N;
		int c = digits[test % N];
		test /= N;
		int d = digits[test % N];
		test /= N;
		int e = digits[test % N];

		int abc = 100 * a + 10 * b + c;
		int pp1 = abc * e; //partial product 1
		int pp2 = abc * d; //partial product 2
		int sum = 10 * pp2 + pp1;

		if (pp1 > 999) goto fail;
		if (pp2 > 999) goto fail;
		if (sum > 9999) goto fail;
		{
			int remainder;
			int ct;
			for (ct = 0; ct < 3; ct++) {
				remainder = pp1 % 10;
				pp1 /= 10;
				ISPROPERDIG(remainder)
			}
			for (ct = 0; ct < 3; ct++) {
				remainder = pp2 % 10;
				pp2 /= 10;
				ISPROPERDIG(remainder)
			}
			for (ct = 0; ct < 4; ct++) {
				remainder = sum % 10;
				sum /= 10;
				ISPROPERDIG(remainder)
			}
		}
		//if no fail
		solutions++;
	fail:;
	}

	fout << solutions << endl;
	fout.close();
}
