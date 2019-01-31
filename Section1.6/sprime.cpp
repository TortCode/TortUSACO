/*
ID: teerth.1
PROG: sprime
LANG: C++
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int start[]{ 2,3,5,7 }; //digits to start superprimes
int follow[]{ 1,3,7,9 }; //digits to end superprimes
vector<int> answers;

bool isPrime(int n) {
	if (n % 2 == 0) return false;
	for (int factor = 3; factor * factor <= n; factor++)
		if (n % factor == 0) return false;
	return true;
}

void superprimes(int seed, int left) {
	if (left == N) {
		for (int digit : start)
			superprimes(digit, left - 1);
	}
	else if (left == 0) {
		if (isPrime(seed)) answers.push_back(seed);
	}
	else {
		int number;
		for (int digit : follow) {
			number = 10 * seed + digit;
			if (isPrime(number)) superprimes(number, left - 1);
		}
	}
}

int main()
{
	ifstream input("sprime.in");
	input >> N;
	input.close();

	superprimes(0, N);

	ofstream output("sprime.out");
	for (int n : answers)
		output << n << endl;
	output.close();
}