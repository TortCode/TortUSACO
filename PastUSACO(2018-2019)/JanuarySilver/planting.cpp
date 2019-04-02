#include <fstream>
#include <vector>
#include <set>
using namespace std;

int N;
int grasses[100001];
vector<vector<int>> paths(100001);

void span(set<int>& notPos, int src, int current)
{
	int colour = 1;
	for (int i : notPos) {
		if (i == colour) colour++;
		else break;
	}
	grasses[current] = colour;
	set<int> newNotPos{ grasses[current], grasses[src] };
	for (int adj : paths[current])
		if (grasses[adj] == 0) {
			span(newNotPos, current, adj);
			newNotPos.emplace(grasses[adj]);
		}
}

int main()
{
	ifstream input("planting.in");
	input >> N;
	for (int i = 1; i < N; i++) {
		int src, dest;
		input >> src >> dest;
		paths[src].push_back(dest);
		paths[dest].push_back(src);
	}
	input.close();
	set<int> start{ 0 };
	span(start, 1, 1);

	int max = 1;
	for (int colour : grasses) {
		if (colour > max) max = colour;
	}

	ofstream output("planting.out");
	output << max << endl;
	output.close();
}
