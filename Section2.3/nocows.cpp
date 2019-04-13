/*
ID: teerth.1
PROG: nocows
LANG: C++
*/
//LOOK AWAY THIS IS A CATASTROPHE NOT MEANT FOR HUMAN EYES
//RUNTIME IS HORRIBLE, FOUR LAYERS OF NESTING, CLUNKY TRANSITIONS WITH UNNEEDED STATE PARAMETER
#include <iostream>
#include <fstream>
using namespace std;

int C[201][201]; // n choose k
short dp[201][101][201]; //nodes, height, leaves at bottom
void buildCombinations(int n, int k)
{
	for (int i = 0; i <= n; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i && j < k; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 9901;
	}
}
int main() {
	buildCombinations(200, 200);
	ifstream input("nocows.in");
	ofstream output("nocows.out");
	int nodes, height;
	input >> nodes >> height;
	input.close();

	dp[1][1][1] = 1;
	for (int n = 1; n <= nodes; n += 2) {
		for (int h = 1; h < height; ++h) {
			for (int lv = 1; lv <= 200; ++lv) {
				for (int k = 1; k <= lv && (n + 2 * k <= nodes) && 2 * k <= 200; ++k) { //add k groups to bottom
					dp[n + 2 * k][h + 1][2 * k] =
						(C[lv][k] * dp[n][h][lv]
						+ dp[n + 2 * k][h + 1][2 * k]) % 9901;
				}
			}
		}
	}
	int sum = 0;
	for (int lv = 1; lv <= 200; lv++)
		sum += dp[nodes][height][lv];
	output << sum % 9901 << '\n';
	output.close();
}
