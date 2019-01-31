/*
ID: teerth.1
PROG: pprime
LANG: C++
*/
#include <fstream>
#include <cmath>
#include <set>
using namespace std;

bool composite[10000 + 1];
set<int> primefactor;
set<int> palindromes;

void primeSieve(int n) //sieve of Eratosthenes
{
	for (int i = 2; i <= n; i++) {
		if (!composite[i]) {
			primefactor.insert(i);
			for (int j = i * i; j <= n; j += i) composite[j] = true;
		}
	}
}

bool isPrime(int n)
{
	for (int factor : primefactor) {
		if (n % factor == 0)
			return false;
		if (factor*factor > n)
			return true;
	}
	return true;
}

int genPalindrome(int seed, bool odd)
{
	int cpy = seed, palin = seed;
	if (odd) cpy /= 10;
	while (cpy > 0) {
		palin = palin * 10 + cpy % 10;
		cpy /= 10;
	}
	return palin;
}

int main()
{
	int a, b;
	ifstream input("pprime.in");
	input >> a >> b; //b is larger than a
	input.close();

	primeSieve(sqrt(b));

	for (int parity = 0; parity <= 1; parity++) {
		int possible, i = 1;
		while ((possible = genPalindrome(i, parity)) <= b) {
			if (isPrime(possible) && possible >= a) palindromes.insert(possible);
			i++;
		}
	}

	ofstream output("pprime.out");
	for (int n : palindromes)
		output << n << endl;
	output.close();
}
