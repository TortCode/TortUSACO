/*
ID: teerth.1
PROG: butter
LANG: C++
*/
#include <fstream>
#include <queue>
#include <utility>
#define INF 205'000
using namespace std;
typedef pair<int, int> Edge; //first for node, second for weight

vector<Edge> graph[800];
// position of cow i
int cowloc[500];
int dist[800][800];

void dijkstra(int n)
{
	for (int i = 0; i < 800; i++) dist[n][i] = INF;
	dist[n][n] = 0;
	bool visited[800]{ 0 };

	auto cmp = [=](int a, int b) -> bool {
		return dist[n][a] > dist[n][b];
	};
	priority_queue<int, vector<int>, decltype(cmp)> heap(cmp);
	heap.push(n);

	int u, v, w;
	while (!heap.empty()) {
		// get min dist node to graph
		u = heap.top(); heap.pop();
		visited[u] = true;
		for (Edge e : graph[u]) {
			// update neighbours
			v = e.first; w = e.second;
			if (!visited[v]) {
				if (dist[n][u] + w < dist[n][v]) {
					dist[n][v] = dist[n][u] + w;
					heap.push(v);
				}
			}
		}
	}
}

int main()
{
	int N, P, C;
	ifstream input("butter.in");
	ofstream output("butter.out");
	input >> N >> P >> C;

	for (int i = 0; i < N; i++) {
		input >> cowloc[i];
		cowloc[i]--;
	}
	int u, v, w;
	for (int i = 0; i < C; i++) {
		input >> u >> v >> w;
		graph[u-1].push_back(Edge(v-1, w));
		graph[v-1].push_back(Edge(u-1, w));
	}

	for (int i = 0; i < P; i++) dijkstra(i);
	// find sugar placement w least sum of distance
	int minsum = -1;
	for (int i = 0; i < P; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++)
			sum += dist[i][cowloc[j]];
		if (minsum == -1 || sum < minsum)
			minsum = sum;
	}
	
	output << minsum << endl;
}