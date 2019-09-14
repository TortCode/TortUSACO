/*
ID: teerth.1
PROG: comehome
LANG: C++
*/
#include <fstream>
#include <set>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#define INF 10000000
#define VERTICES 52
using namespace std;

int charIndex(char c) {
	if (c < 'a') return c - 'A';
	else return c - 'a' + 26;
}
// ordered by ABC...abc
int weight[VERTICES][VERTICES];
int dist[VERTICES];
bool visited[VERTICES];
typedef pair<int, int> pii;
set<pii> minHeap;

int main()
{
	ifstream input("comehome.in");
	ofstream output("comehome.out");

	int P;
	input >> P;
	char c1, c2;
	int idx1, idx2, distance;
	for (int i = 0; i < P; i++) {
		input >> c1 >> c2;
		idx1 = charIndex(c1);
		idx2 = charIndex(c2);
		input >> distance;
		if (weight[idx1][idx2] == 0) weight[idx1][idx2] = distance;
		weight[idx1][idx2] = min(weight[idx1][idx2],distance);
		weight[idx2][idx1] = weight[idx1][idx2];
	}
	// init distances
	for (int i = 0; i < VERTICES; i++) {
		dist[i] = INF;
		for (int j = 0; j < VERTICES; j++)
			if (weight[i][j] == 0) weight[i][j] = INF;
	}
	int Z = charIndex('Z');
	dist[Z] = 0;
	minHeap.insert({ 0, Z });
	// dijkstra
	while (!minHeap.empty()) {
		int node = minHeap.begin()->second; minHeap.erase(minHeap.begin());
		visited[node] = true;
		for (int adj = 0; adj < VERTICES; adj++)
			if (dist[adj] > dist[node] + weight[node][adj]) {
				if (dist[adj] != INF)
					minHeap.erase(minHeap.find({ dist[adj], adj }));
				dist[adj] = dist[node] + weight[node][adj];
				minHeap.insert({ dist[adj], adj });
			}
	}
	// get fastest cow
	int fast = 0;
	for (int i = 0; i < Z; i++)
		if (dist[i] < dist[fast]) {
			fast = i;
		}

	output << (char)(fast + 'A') << " " << dist[fast] << endl;
}
