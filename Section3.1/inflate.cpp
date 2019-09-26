/*
ID: teerth.1
PROG: inflate
LANG: C++
*/
#include <fstream>
#define MAXTIME 10'000
#define MAXCATEGORY 10'000
using namespace std;

int dp[MAXTIME + 1];

int main()
{
	int LEN, CLASS;
	ifstream input("inflate.in");
	ofstream output("inflate.out");
	input >> LEN >> CLASS;
	int pts, time;
	for (int i = 0; i < CLASS; i++) {
		input >> pts >> time;
		for (int t = 0; t + time <= LEN; t++) {
			if (dp[t] + pts > dp[t + time])
				dp[t + time] = dp[t] + pts;
		}
	}

	int maxpoint = 0;
	for (int t = 0; t <= MAXTIME; t++)
		if (maxpoint < dp[t])
			maxpoint = dp[t];


	output << maxpoint << endl;
}