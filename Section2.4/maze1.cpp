/*
ID: teerth.1
PROG: maze1
LANG: C++
*/
#include <fstream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int W, H;
char maze[201][77];
bool visited[201][77];
int dist[201][77];
struct node { int i, j; };
priority_queue<node> q;
bool operator<(node a, node b)
{
	return dist[a.i][a.j] > dist[b.i][b.j];
}
inline bool isValid(int i, int j)
{
	return i >= 0 && i <= H && j >= 0 && j <= W;
}
void bfs(int r, int c)
{
	q.push({ r, c });
	while (!q.empty()) {
		node n = q.top();
		q.pop();
		if (!visited[n.i][n.j]) {
			visited[n.i][n.j] = true;
			if (isValid(n.i + 1, n.j) && maze[n.i + 1][n.j] == ' ') {
				if (dist[n.i + 1][n.j] == -1 || dist[n.i + 1][n.j] > (dist[n.i][n.j] + 1))
					dist[n.i + 1][n.j] = dist[n.i][n.j] + 1;
				q.push({ n.i + 1, n.j });
			}
			if (isValid(n.i - 1, n.j) && maze[n.i - 1][n.j] == ' ') {
				if (dist[n.i - 1][n.j] == -1 || dist[n.i - 1][n.j] > (dist[n.i][n.j] + 1))
					dist[n.i - 1][n.j] = dist[n.i][n.j] + 1;
				q.push({ n.i - 1, n.j });
			}
			if (isValid(n.i, n.j + 1) && maze[n.i][n.j + 1] == ' ') {
				if (dist[n.i][n.j + 1] == -1 || dist[n.i][n.j + 1] > (dist[n.i][n.j] + 1))
					dist[n.i][n.j + 1] = dist[n.i][n.j] + 1;
				q.push({ n.i, n.j + 1 });
			}
			if (isValid(n.i, n.j - 1) && maze[n.i][n.j - 1] == ' ') {
				if (dist[n.i][n.j - 1] == -1 || dist[n.i][n.j - 1] > (dist[n.i][n.j] + 1))
					dist[n.i][n.j - 1] = dist[n.i][n.j] + 1;
				q.push({ n.i, n.j - 1 });
			}

		}
	}
}

int main()
{
	ifstream input("maze1.in");
	ofstream output("maze1.out");
	input >> W >> H;
	W *= 2; H *= 2;
	string line;
	getline(input, line);

	int exitFound = 0;
	node exit, exit2;
	for (int i = 0; i <= H; i++) {
		getline(input, line);
		for (int j = 0; j <= W; j++) {
			maze[i][j] = line[j];
			dist[i][j] = -1;
			if (maze[i][j] == ' ' && (i == 0 || i == H || j == 0 || j == W)) {
				dist[i][j] = 1;
				if (exitFound == 0) {
					exitFound++;
					exit.i = i; exit.j = j;
				}
				else {
					exit2.i = i; exit2.j = j;
				}
			}
		}
	}

	bfs(exit.i, exit.j);
	for (int i = 0; i <= H; i++) {
		for (int j = 0; j <= W; j++) {
			visited[i][j] = false;
		}
	}
	bfs(exit2.i, exit2.j);

	int max = 1;
	for (int i = 0; i <= H; i++) {
		for (int j = 0; j <= W; j++) {
			if (dist[i][j] > max) max = dist[i][j];
		}
	}
	output << max/2 << endl;
}
