/*
ID: teerth.1
PROG: camelot
LANG: C++
*/
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>

#define f first
#define s second

using namespace std;
constexpr int MAXROW = 30;
constexpr int MAXCOL = 26;
using Position = pair<int, int>;

Position king;
vector<Position> knights;
priority_queue<pair<int, Position>> pq;
int rows, cols;

int dist[MAXROW][MAXCOL][MAXROW][MAXCOL];
bool visited[MAXROW][MAXCOL];

inline bool isValid(int r, int c)
{
	return r >= 0 && r < rows && c >= 0 && c < cols;
}

void dijkstra(Position k)
{
	int moves[][2] =
	{
		{-1,-2}, {-2,-1},
		{-1,2}, {2,-1},
		{1,2}, {2,1},
		{1,-2}, {-2,1}
	};
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
		{
			visited[i][j] = false;
			dist[k.f][k.s][i][j] = 1000;
		}
	dist[k.f][k.s][k.f][k.s] = 0;
	pq.push({ 0, k });
	while (!pq.empty()) {
		Position p = pq.top().s; pq.pop();
		if (visited[p.f][p.s]) continue;
		visited[p.f][p.s] = true;
		for (int i = 0; i < 8; ++i) {
			int nf = p.f + moves[i][0], ns = p.s + moves[i][1];
			if (isValid(nf, ns) && !visited[nf][ns]) {
				if (dist[k.f][k.s][p.f][p.s] + 1 < dist[k.f][k.s][nf][ns])
				{
					dist[k.f][k.s][nf][ns] = dist[k.f][k.s][p.f][p.s] + 1;
					pq.push({ -dist[k.f][k.s][nf][ns], Position(nf,ns) });
				}
			}
		}
	}
}

int min_moves(int r, int c)
{
	int ret = 0;
	int kingmove = 1000;
	for (Position k : knights) {
		for (int i = -2; i <= 2; ++i) {
			for (int j = -2; j <= 2; ++j) {
				int ni = king.f + i, nj = king.s + j;
				if (isValid(ni, nj))
					kingmove = min(kingmove,
						max(abs(i), abs(j))
						+ dist[r][c][ni][nj]
						+ dist[ni][nj][k.f][k.s]
						- dist[r][c][k.f][k.s]
				);
			}
		}
		ret += dist[r][c][k.f][k.s];
	}
	ret = min(ret + kingmove, ret + max(abs(king.f - r), abs(king.s - c)));
	return ret;
}

int main()
{
	ifstream input("camelot.in");
	ofstream output("camelot.out");

	char c;
	int r;
	input >> rows >> cols;
	input >> c >> r;
	king.first = r - 1;
	king.second = c - 'A';
	while (input >> c >> r)
		knights.push_back({ r - 1, c - 'A' });
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			dijkstra({ i,j });

	int leastmove = -1;
	int moves;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			moves = min_moves(i, j);
			if (leastmove == -1 || moves < leastmove)
				leastmove = moves;
		}
	}

	output << leastmove << endl;
}