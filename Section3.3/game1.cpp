/*
ID: teerth.1
PROG: game1
LANG: C++
*/
#include <fstream>
using namespace std;

constexpr int MAXN = 200;
int N;
int board[MAXN];

// 0 for player 1, 1 for player 2
int optimal[MAXN][MAXN][2];

void optimize(int turn)
{
	int ply = (turn + 1) % 2;
	int op = turn % 2;

	int i = 0;
	int j = N - turn;
	for (; j < N; ++i, ++j)
	{
		int lpick = board[i] + optimal[i+1][j][ply];
		int rpick = board[j] + optimal[i][j-1][ply];
		if (lpick > rpick) {
			optimal[i][j][ply] = lpick;
			optimal[i][j][op] = optimal[i+1][j][op];
		}
		else {
			optimal[i][j][ply] = rpick;
			optimal[i][j][op] = optimal[i][j-1][op];
		}
	}
}

int main()
{
	ifstream input("game1.in");
	ofstream output("game1.out");
	input >> N;
	int ply = (N + 1) % 2;
	int op = N % 2;
	for (int i = 0; i < N; ++i) {
		input >> board[i];
		optimal[i][i][ply] = board[i];
		optimal[i][i][op] = 0;
	}

	for (int i = N - 1; i >= 1; --i)
		optimize(i);

	output << optimal[0][N - 1][0] << ' ' << optimal[0][N - 1][1] << endl;
}