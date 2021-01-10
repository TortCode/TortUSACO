/*
ID: teerth.1
PROG: stall4
LANG: C++
*/
#include <fstream>
#include <queue>
#include <algorithm>

using pii = std::pair<int, int>;

constexpr int MAXN = 200;
constexpr int MAXM = 200;
constexpr int NODES = 2 + MAXN + MAXM;
constexpr int INF = 200;
// number of cows
int N;
// number of stalls
int M;

bool visited[NODES];
int prevn[NODES];
int flow[NODES];
int adj[NODES][NODES];

int addflow()
{
	std::fill(visited, visited + NODES, false);
	std::fill(prevn, prevn + NODES, -1);
	std::fill(flow, flow + NODES, 0);

	std::priority_queue<pii> pq;
	visited[0] = true;
	flow[0] = INF;
	pq.push({ flow[0], 0 });

	while (!pq.empty())
	{
		int maxloc = pq.top().second; pq.pop();
		visited[maxloc] = true;
		for (int i = 0; i < NODES; i++)
		{
			if (visited[i])
				continue;
			int alt = std::min(flow[maxloc], adj[maxloc][i]);
			if (flow[i] < alt)
			{
				prevn[i] = maxloc;
				flow[i] = alt;
				pq.push({ alt, i });
			}
		}
	}

	int pathcap = flow[1];
	int curr = 1;
	while (prevn[curr] != -1)
	{
		adj[prevn[curr]][curr] -= pathcap;
		adj[curr][prevn[curr]] += pathcap;
		curr = prevn[curr];
	}

	return pathcap;
}

inline int stall(int i) { return 1 + MAXN + i; }
inline int cow(int i) { return 1 + i; }
// source is 0; sink is 1
int main()
{
	std::ifstream input("stall4.in");
	input >> N >> M;

	// path to src and sink
	for (int i = 1; i <= N; i++)
		adj[0][cow(i)] = 1;
	for (int i = 1; i <= M; i++)
		adj[stall(i)][1] = 1;
	// load stall choices
	for (int i = 1; i <= N; i++)
	{
		int S, t;
		input >> S;
		for (int j = 0; j < S; j++)
		{
			input >> t;
			adj[cow(i)][stall(t)] = 1;
		}
	}
	input.close();

	int curr = 0, total = 0;
	while (curr = addflow())
		total += curr;

	std::ofstream output("stall4.out");
	output << total << std::endl;
	output.close();

}