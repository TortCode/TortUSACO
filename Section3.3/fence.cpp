/*
ID: teerth.1
PROG: fence
LANG: C++
*/
#include <fstream>
#include <set>

std::multiset<int> edges[501]; //one-based
int path[1024];
int pos = 0;

int findStart()
{
	int first = 0;
	int sz;
	for (int i = 1; i <= 500; ++i) {
		sz = edges[i].size();
		if (first == 0 && sz > 0)
			first = i;
		// odd node indicates eulerian path which starts at same node
		if (sz % 2 == 1)
			return i;
	}
	// every node has even degree, so start at lexically first
	return first;
}

void findPath(int n)
{
	int adj;
	while (!edges[n].empty()) {
		adj = *edges[n].begin();
		// delete edge
		edges[n].erase(edges[n].begin());	
		edges[adj].erase(edges[adj].find(n));
		findPath(adj);
	}
	path[pos] = n;
	++pos;
}

int main()
{
	std::ifstream input("fence.in");
	std::ofstream output("fence.out");

	int nfence;
	input >> nfence;
	int u, v;
	for (int i = 0; i < nfence; ++i) {
		input >> u >> v;
		edges[u].insert(v);
		edges[v].insert(u);
	}
	findPath(findStart());
	for (int i = pos-1; i >= 0; --i)
		output << path[i] << std::endl;
}
