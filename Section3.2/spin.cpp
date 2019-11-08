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
	int rotation = 0;
	bitset<360> wedges;
	void rotate() {
		rotation = (rotation + speed) % 360;
	}
	bool getBit(int angle) {
		return wedges[(angle - rotation + 360) % 360];
	}
	void setBits(int start, int end)
	{
		for (int i = start; i <= end; i++)
			wedges[i % 360] = true;
	}
} wheels[5];

int findAlignment() {
	int t = 0;
	int angle;
	do {
		for (angle = 0; angle < 360; angle++) {
			if (wheels[0].getBit(angle)
				&& wheels[1].getBit(angle)
				&& wheels[2].getBit(angle)
				&& wheels[3].getBit(angle)
				&& wheels[4].getBit(angle))
				return t;
		}
		wheels[0].rotate();
		wheels[1].rotate();
		wheels[2].rotate();
		wheels[3].rotate();
		wheels[4].rotate();
		t++;
	} while (!(wheels[0].rotation == 0
		&& wheels[1].rotation == 0
		&& wheels[2].rotation == 0
		&& wheels[3].rotation == 0
		&& wheels[4].rotation == 0));
	return -1;
}

int main() {
	ifstream input("spin.in");
	ofstream output("spin.out");
	for (int i = 0; i < 5; i++) {
		int numwedge;
		int start, extent;
		input >> wheels[i].speed >> numwedge;
		for (int j = 0; j < numwedge; j++) {
			input >> start >> extent;
			wheels[i].setBits(start, start + extent);
		}
	}
	int result = findAlignment();
	if (result == -1)
		output << "none" << endl;
	else
		output << result << endl;
}