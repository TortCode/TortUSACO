/*
ID: teerth.1
PROG: wormhole
LANG: C++
*/
#include <fstream>
#include <algorithm>
#include <map>
using namespace std;

int N, latitudes;

struct Point {
	int x, y;
};

struct Farm {
	int lines[12];

	Farm(map<int, int> portals) {
		int i = 0;
		for (pair<int, int> p : portals) {
			lines[i] = p.second;
			i++;
		}
		latitudes = i;
	}
};

int main()
{
	ifstream input("wormhole.in");
	ofstream output("wormhole.out");

	map<int, int> yGroups;

	input >> N;
	Point curr;
	for (int i = 0; i < N; i++) {
		input >> curr.x >> curr.y;
		yGroups.emplace(curr.y, 0);
		yGroups[curr.y]++;
	}
	input.close();
	const Farm portalMap(yGroups);






	output.close();
}