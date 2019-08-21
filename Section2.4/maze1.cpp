/*
ID: teerth.1
PROG: maze1
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <string>
#include <set>
using namespace std;
int W, H;
char maze[201][77];
int dist[201][77];
struct node { int i, j; };
set<node> q;
bool operator<(node a, node b)
void bfs(int r, int c)
{
	q.insert({ r,c });
}

int main()
{
	ifstream input("maze1.in");
	ofstream output("maze1.out");
	input >> W >> H;
	W *= 2; H *= 2;
	string line;
	getline(input, line);
	for (int i = 0; i <= H; i++) {
		getline(input, line);
		cout << line << endl;
		for (int j = 0; j <= W; j++) {
			maze[i][j] = line[j];
			dist[i][j] = -1;
			if (maze[i][j] == ' ' && (i == 0 || i == H || j == 0 || j == W))
				dist[i][j] = 1;
		}
	}




	return 0;
}