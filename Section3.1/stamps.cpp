/*
ID: teerth.1
PROG: stamps
LANG: C++
*/
#include <fstream>
#include <algorithm>
#define MAXVALUE 10'000
#define MAXUSABLE 200
#define MAXSTAMPS 50
#define MAXPOSTAGE MAXVALUE*MAXUSABLE+1
using namespace std;

int values[MAXSTAMPS];
int minStamps[MAXPOSTAGE];
int usable, nstamps;
// EZ dp
int solve()
{
	int value;
	int i, j;
	for (i = 0; i < MAXPOSTAGE && minStamps[i] <= usable; i++) {
		for (j = 0; j < nstamps; j++) {
			value = values[j];
			if (minStamps[i] + 1 < minStamps[i + value])
				minStamps[i + value] = minStamps[i] + 1;
		}
	}
	return i - 1;
}

int main()
{
	ifstream input("stamps.in");
	ofstream output("stamps.out");
	input >> usable >> nstamps;
	for (int i = 0; i < nstamps; i++)
		input >> values[i];
	fill(minStamps, minStamps + MAXPOSTAGE, MAXUSABLE + 1);
	minStamps[0] = 0;
	output << solve() << endl;
}