/*
ID: teerth.1
PROG: butter
LANG: C++
*/
#include <fstream>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> edge; //first for node, second for weight
vector<edge> graph[800];
// position of cow i
int cowloc[500];
int dist[800][800];

struct Compare {
	bool operator() (int a, int b)
	{
		return 
	}
};
void dijkstra(int n)
{
	priority_queue<int> heap;
	heap.insert(n);
}
int main()
{
	int N, P, C;
	ifstream input("butter.in");
	ofstream output("butter.out");
	input >> N >> P >> C;

	for (int i = 0; i < N; i++)
		input >> cowloc[i];
	int u, v, w;
	for (int i = 0; i < C; i++) {
		input >> u >> v >> w;
		graph[u].push_back(edge(v, w));
		graph[v].push_back(edge(u, w));
	}
}