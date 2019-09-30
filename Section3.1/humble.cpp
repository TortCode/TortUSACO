/*
ID: teerth.1
PROG: humble
LANG: C++
*/
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;
#define MAXPRIME 100

int primes[MAXPRIME];
int N, K;
set<long long int> humbles;

long int getHumble(int n)
{
	int i, j;
	long long int min, max;
	for (i = 1;; i++) {
		min = *humbles.begin();
		humbles.erase(humbles.begin());
		if (i == n) return min;
		if (min*primes[0] > *humbles.end()) {
			i++;
			break;
		}
		for (j = 0; j < K; j++) {
			humbles.insert(min*primes[j]);
		}
	}
	for (;; i++) {
		min = *humbles.begin();
		humbles.erase(humbles.begin());
		if (i == n) return min;
	}
}

int main()
{
	ifstream input("humble.in");
	ofstream output("humble.out");
	input >> K >> N;
	for (int i = 0; i < K; i++) {
		input >> primes[i];
		humbles.insert(primes[i]);
	}
	input.close();
	sort(primes, primes + K);

	output << getHumble(N) << endl;
}