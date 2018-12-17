/*
ID: teerth.1
PROG: wormhole
LANG: C++
*/
#include <fstream>
#include <vector>
#include <map>
using namespace std;
typedef unsigned char byte;
typedef vector<byte> grouping;

int N, halfN; //amount of portals, number of pairs
vector<byte> usedInPair;
vector<grouping> PartitionList;

void generatePartition(int elem, grouping pairs)
{
	if (elem == N) { //full partition made ADD
		PartitionList.push_back(pairs);
	}
	for (byte i = 0; i < halfN; i++) {
		if (usedInPair[i] == 2) continue; //if pair filled SKIP
		pairs[elem] = i;
		usedInPair[i]++;
		generatePartition(elem + 1, pairs);
		usedInPair[i]--;
		if (usedInPair[i] == 0) break; //if empty pair reached STOP
	}
}

inline int searchCounterpart(grouping g, int origPos)
{
	byte group = g[origPos];
	for (int i = 0; i < N; i++) {
		if (g[i] == group && i != origPos) return i;
	}
}

struct Farm {
	bool isEndPortal[12]{ false };

	Farm(map<int, int> portals) {
		int endIdx = 0;
		for (pair<int, int> p : portals) {
			endIdx += p.second;
			isEndPortal[endIdx - 1] = true;
		}
	}
};

int main()
{
	ifstream input("wormhole.in");
	ofstream output("wormhole.out");
	input >> N;
	halfN = N / 2;

	struct Point {
		int x, y;
	} curr;
	map<int, int> yGroups;
	for (int i = 0; i < N; i++) {
		input >> curr.x >> curr.y;
		yGroups.emplace(curr.y, 0);
		yGroups[curr.y]++;
	}
	input.close();
	const Farm portalMap(yGroups);
	{
		grouping g(N);
		vector<byte> u(halfN, 0);
		usedInPair = u;
		generatePartition(0, g);
	}
	int solutions = 0;
	for (grouping wormholes : PartitionList) {
		byte pairNumber;
		bool checked[12]{ false };
		for (int i = 0; i < N; i++) {
			if (checked[i]) continue;
			int portal = i;
			bool doesInfLoop = false;
			do {
				checked[portal] = true;
				portal = searchCounterpart(wormholes, portal); //teleport
				if (portalMap.isEndPortal[portal]) break;
				portal++; //move +x
				if (portal == i) { //back at start
					solutions++;
					doesInfLoop = true;
				}
			} while (!doesInfLoop);
			if (doesInfLoop) break;
		}
	}
	output << solutions << endl;
	output.close();
}
