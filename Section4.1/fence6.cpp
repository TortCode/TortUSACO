/*
ID: teerth.1
PROG: fence6
LANG: C++
*/
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
constexpr int INF = 255 * 150;
constexpr int MAXSEG = 100;
int N;

//all one-based
int weight[MAXSEG + 1];
vector<int> conn[MAXSEG + 1][2]; //what fences connect to at ends
int endnode[MAXSEG + 1][2]; //what node found at each fence end

//global node counter
int gnode = 0;

void mark_nodes()
{
	int u, j;
	for (u = 1; u <= N; ++u) {
		for (j = 0; j < 2; ++j) {
			if (endnode[u][j] > 0) continue;
			// mark node at connecting edge ends
			endnode[u][j] = ++gnode;
			for (int v : conn[u][j]) {
				if (find(conn[v][0].begin(), conn[v][0].end(), u) != conn[v][0].end())
					endnode[v][0] = gnode;
				else
					endnode[v][1] = gnode;
			}
		}
	}
}

//adj-list with entry (weight, connecting vertex)
vector<vector<pii>> adjl;
void construct_graph()
{
	for (int i = 0; i < gnode; ++i)
		adjl.push_back(vector<pii>());
	int u, v, w;
	for (int e = 1; e <= N; ++e) {
		u = endnode[e][0] - 1;
		v = endnode[e][1] - 1;
		w = weight[e];
		adjl[u].push_back({ w,v });
		adjl[v].push_back({ w,u });
	}
}

int shortpath(int i, int j)
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> dist(gnode, INF);
	bool visited[2*MAXSEG];
	fill(visited, visited + gnode, false);
	pq.push({ 0, i });
	dist[i] = 0;
	while (!pq.empty()) {
		int u, v, w;
		u = pq.top().second; pq.pop();
		if (visited[u]) continue;
		visited[u] = true;
		for (pii p : adjl[u]) {
			w = p.first;
			v = p.second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push({ dist[v], v });
			}
		}
	}
	return dist[j];
}

int main()
{
	ifstream input("fence6.in");
	input >> N;

	// input into edges
	for (int i = 0; i < N; ++i) {
		int s, l, n1, n2;
		input >> s >> l >> n1 >> n2;
		weight[s] = l;
		int j, t;
		for (j = 0; j < n1; ++j) {
			input >> t;
			conn[s][0].push_back(t);
		}
		for (j = 0; j < n2; ++j) {
			input >> t;
			conn[s][1].push_back(t);
		}
	}
	input.close();

	mark_nodes();
	construct_graph();

	int minperimeter = INF;
	for (int u = 0; u < gnode; ++u) {
		for (int j = adjl[u].size() - 1; j >= 0; j--) {
			int w = adjl[u][j].first;
			int v = adjl[u][j].second;
			// delete edge and use dijkstra to find next shortest route
			adjl[u].pop_back();
			adjl[v].erase(find_if(adjl[v].begin(), adjl[v].end(),
				[=](pii p) { return p.first == w && p.second == u; }));
			int currmin = w + shortpath(u, v);
			if (currmin < minperimeter)
				minperimeter = currmin;
		}
	}

	ofstream output("fence6.out");
	output << minperimeter << endl;
	output.close();
}
