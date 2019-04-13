/*
ID: teerth.1
PROG: money
LANG: C++
*/
#include <fstream>
using namespace std;

long long dp[10001][26]{ {1} }; //coin value, coins used

int main()
{
	int coins[25], N, V;
	ifstream input("money.in");
	ofstream output("money.out");
	input >> V >> N;
	for (int i = 0; i < V; i++)
		input >> coins[i];
	input.close();

	for (int i = 0; i < V; i++) {
		int coin = coins[i];
		for (int j = 0; j <= N; j++) {
			dp[j][i+1] += dp[j][i] //none of current coin added
				+ ((j - coin >= 0) ? dp[j - coin][i+1] : 0); //one of current coin added
		}
	}
	long long ans = dp[N][V];
	output << ans << '\n';
	output.close();
}
