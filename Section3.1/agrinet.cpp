/*
ID: teerth.1
PROG: agrinet
LANG: C++
*/
#include <fstream>
#include <algorithm>
#define MAXNODE 100
using namespace std;
int N;
int weights[MAXNODE][MAXNODE];
int dist[MAXNODE];
bool inTree[MAXNODE];

int minNode()
{
	int minpos = -1;
	for (int i = 0; i < N; i++)
		if (!inTree[i] && (minpos == -1 || dist[i] < dist[minpos]))
			minpos = i;
	return minpos;
}

int main()
{
	ifstream input("agrinet.in");
	ofstream output("agrinet.out");
	input >> N;
	
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			input >> weights[i][j];

	// prims algo
	int cost = 0;
	inTree[0] = true;
	for (j = 0; j < N; j++)
		dist[j] = weights[0][j];
	for (int sz = 1; sz < N; sz++) {
		// add minimum node to tree
		int node = minNode();
		inTree[node] = true;
		cost += dist[node];
		// update neighbours
		for (i = 0; i < N; i++)
			if (dist[i] == -1 || weights[node][i] < dist[i])
				dist[i] = weights[node][i];
	}

	output << cost << '\n';
}