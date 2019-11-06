/*
ID: teerth.1
PROG: spin
LANG: C++
*/
#include <fstream>
#include <bitset>
using namespace std;

struct Wheel {
	int speed;
	bitset<360> wedges;
	void setBits(int start, int end)
	{
		for (int i = start; i <= end; i++)
			wedges[i % 360] = true;
	}
} wheels[5];

int main() {
	ifstream input("spin.in");
	ofstream output("spin.out");

	for (int i = 0; i < 5; i++){
		int numwedge;
		int start, extent;
		input >> wheels[i].speed >> numwedge;
		for (int j = 0; j < numwedge; j++) {
			input >> start >> extent;
			wheels[i].setBits(start, start + extent);
		}
	}

	int rotation[5]{ 0 };



	return 0;
}