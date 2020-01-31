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

int dist[MAXROW][MAXCOL];
bool visited[MAXROW][MAXCOL];

inline bool isValid(int r, int c)
{
	return r >= 0 && r < rows && c >= 0 && c < cols;
}
inline int index(Position p)
{
	return p.f * MAXCOL + p.s;
}

void dijkstra()
{
	int moves[][2] =
	{
		{-1,-2}, {-2,-1},
		{-1,2}, {2,-1},
		{1,2}, {2,1},
		{1,-2}, {-2,1}
	};
	for (int i = 0; i < MAXROW; ++i)
		for (int j = 0; j < MAXCOL; ++j)
			dist[i][j] = 1000;
	dist[0][0] = 0;
	pq.push({ 0, Position(0,0) });
	while (!pq.empty()) {
		Position p = pq.top().s; pq.pop();
		if (visited[p.f][p.s]) continue;
		visited[p.f][p.s] = true;
		for (int i = 0; i < 8; ++i) {
			int nf = p.f + moves[i][0], ns = p.s + moves[i][1];
			if (isValid(nf, ns) && !visited[nf][ns]) {
				if (dist[p.f][p.s] + 1 < dist[nf][ns])
				{
					dist[nf][ns] = dist[p.f][p.s] + 1;
					pq.push({ -dist[nf][ns], Position(nf,ns) });
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
		for (int i = -3; i <= 3; ++i) {
			for (int j = -3; j <= 3; ++j) {
				kingmove = min(kingmove,
					max(abs(i),abs(j))
					+ dist[abs(k.f - king.f - i)][abs(k.s - king.s - j)]
					+ dist[abs(king.f + i - r)][abs(king.s + j - c)]
					- dist[abs(k.f - r)][abs(k.s - c)]
				);
			}
		}
		ret += dist[abs(k.f - r)][abs(k.s - c)];
	}
	ret += kingmove;
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
	if (knights.empty()) {
		output << 0 << endl;
		return 0;
	}
	dijkstra();

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