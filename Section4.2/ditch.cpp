/*
ID: teerth.1
PROG: ditch
LANG: C++
*/
#include <fstream>
#include <queue>
#include <algorithm>

#define MAXM 200
#define INF 2'000'000'001

using pii = std::pair<int, int>;
int N, M;

int flow[MAXM];
int prevn[MAXM];
bool visited[MAXM];
int adj[MAXM][MAXM]; //arg0 is start arg1 is the end, value is remaining capacity

int addflow()
{
	std::fill(flow, flow + M, 0);
	std::fill(prevn, prevn + M, -1);
	std::fill(visited, visited + M, false);
	flow[0] = INF;

	std::priority_queue<pii> pq;
	pq.push({ flow[0], 0 });

	while (!pq.empty())
	{
		int maxloc = pq.top().second; pq.pop();
		visited[maxloc] = true;
		for (int i = 1; i < M; i++)
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

	int pathcap = flow[M - 1];
	if (pathcap == 0)
		return 0;
	int curr = M - 1;
	while (prevn[curr] != -1)
	{
		adj[prevn[curr]][curr] -= pathcap;
		adj[curr][prevn[curr]] += pathcap;
		curr = prevn[curr];
	}
	return pathcap;
}

int main()
{
	std::ifstream input("ditch.in");
	input >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int s, e, c;
		input >> s >> e >> c;
		adj[s - 1][e - 1] += c;
	}
	input.close();

	int total = 0;
	int curr;
	do
	{
		curr = addflow();
		total += curr;
	} while (curr);

	std::ofstream output("ditch.out");
	output << total << std::endl;
	output.close();
}
