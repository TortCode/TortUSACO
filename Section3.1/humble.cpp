/*
ID: teerth.1
PROG: humble
LANG: C++
*/
#include <fstream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAXPRIME 100
#define MAXHUMBLE 100'000
int N, K;
int primes[MAXPRIME];
int minIndex[MAXPRIME];
long humbles[MAXHUMBLE];

long getHumble(int n)
{
	int i, j;
	long max;
	long minAboveMax;
	int prime;
	for (i = 1; i <= n; i++) {
		max = humbles[i - 1];
		minAboveMax = LONG_MAX;
		for (j = 0; j < K; j++) {
			prime = primes[j];
			while (prime * humbles[minIndex[j]] <= max) minIndex[j]++;
			minAboveMax = min(minAboveMax, prime * humbles[minIndex[j]]);
		}
		humbles[i] = minAboveMax;
	}
	return humbles[n];
}

int main()
{
	ifstream input("humble.in");
	ofstream output("humble.out");
	input >> K >> N;
	for (int i = 0; i < K; i++)
		input >> primes[i];
	input.close();
	sort(primes, primes + K);
	humbles[0] = 1;

	output << getHumble(N) << endl;
}
