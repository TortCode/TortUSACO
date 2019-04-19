/*
ID: teerth.1
PROG: concom
LANG: C++
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

struct edge { int tail, weight; };
vector<edge> outedges[101];
int percent[101]; //sum of ownerships of surrounding
bool visited[101];
vector<pair<int, int>> ownerships; //solutions

void search(int owner, int c)
{
	visited[c] = true;
	for (edge e : outedges[c]) {
		percent[e.tail] += e.weight;
		if (!visited[e.tail] && percent[e.tail] > 50) {
			ownerships.push_back({ owner, e.tail });
			search(owner, e.tail);
		}
	}
}

int main()
{
	ifstream input("concom.in");
	ofstream output("concom.out");
	//input
	int n; input >> n;
	int h, t, p;
	for (int i = 0; i < n; i++) {
		input >> h >> t >> p;
		outedges[h].push_back({ t,p });
	}
	input.close();
	//find ownerships
	for (int i = 1; i <= 100; i++) {
		if (outedges[i].size() > 0) {
			search(i, i);
			fill(visited, visited + 101, 0);
			fill(percent, percent + 101, 0);
		}
	}
	//output
	sort(ownerships.begin(), ownerships.end());
	for (auto own : ownerships)
		output << own.first << ' ' << own.second << '\n';
	output.close();
}