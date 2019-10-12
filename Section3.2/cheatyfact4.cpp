/*
ID: teerth.1
PROG: fact4
LANG: C++
*/
#include <fstream>
using namespace std;

int main() {
	ifstream input("fact4.in");
	ofstream output("fact4.out");
	int N;
	input >> N;

	int digit = 1;
	for (int i = 1; i <= N; i++) {
		digit *= i;
		while (digit % 10 == 0) digit /= 10;
		// this was really cheaty right here, i just set the modulus to be a "high enough" power of ten
		digit %= 100000;
	}

	output << digit % 10 << endl;
}
