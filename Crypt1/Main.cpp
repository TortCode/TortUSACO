/*
ID: teerth.1
PROG: crypt1
LANG: C++
*/
#include <fstream>
#include <string>
#include <vector>
#define useproperchar(remainder) if (!(remainder == a || remainder == b || remainder == c || remainder == d || remainder == e)) { \
isSolution = false; \
goto fail;}

using namespace std;

int main()
{
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	int N;
	vector<int> digits;
	fin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		fin >> num;
		digits.push_back(num);
	}
	fin.close();
	/*
	 abc
	x de
	____
	 ***
	***
	----
	****
	 */
	int solutions = 0;
	for (int a : digits) {
		for (int b : digits) {
			for (int c : digits) {
				for (int d : digits) {
					for (int e : digits) {
						int abc = 100 * a + 10 * b + c;
						int pp1 = abc * e; //partial product 1
						if (pp1 > 999) continue;
						int pp2 = abc * d; //partial product 2
						if (pp2 > 999) continue;
						int sum = 10 * pp2 + pp1;
						if (sum > 9999) continue;
						bool isSolution = true;
						int remainder;
						for (int i = 0; i < 3; i++) {
							remainder = pp1 % 10;
							pp1 /= 10;
							useproperchar(remainder);
						}
						for (int i = 0; i < 3; i++) {
							remainder = pp2 % 10;
							pp2 /= 10;
							useproperchar(remainder);
						}
						for (int i = 0; i < 4; i++) {
							remainder = sum % 10;
							sum /= 10;
							useproperchar(remainder);
						}
					fail:
						if (!isSolution) continue;
						else solutions++;

					}
				}
			}
		}
	}

	fout << solutions;
	fout.close();
}
