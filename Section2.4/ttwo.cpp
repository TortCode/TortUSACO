/*
ID: teerth.1
PROG: ttwo
LANG: C++
*/
#include <fstream>
#include <string>
#include <bitset>
using namespace std;

int obstacle[10][10];
bitset<10000> state[16];
struct COW {
	int x, y, d = 0; //0 N 1 E 2 S 3 W
	void move()
	{
		switch (d) {
		case 0:
			if (y - 1 < 0 || obstacle[y - 1][x]) ++d;
			else --y;
			break;
		case 1:
			if (x + 1 >= 10 || obstacle[y][x + 1]) ++d;
			else ++x;
			break;
		case 2:
			if (y + 1 >= 10 || obstacle[y + 1][x]) ++d;
			else ++y;
			break;
		case 3:
			if (x - 1 < 0 || obstacle[y][x - 1]) d = 0;
			else --x;
			break;
		}
	}
} farmer, cow;

int main()
{
	ifstream input("ttwo.in");
	ofstream output("ttwo.out");

	string line;
	for (int i = 0; i < 10; ++i) {
		input >> line;
		for (int j = 0; j < 10; ++j) {
			if (line[j] == '*')
				obstacle[i][j] = true;
			if (line[j] == 'F') {
				farmer.y = i; farmer.x = j;
			}
			if (line[j] == 'C') {
				cow.y = i; cow.x = j;
			}
		}
	}
	int count, dir, pos;
	for (count = 0;;count++) {
		if (cow.x == farmer.x && cow.y == farmer.y)
			break;
		cow.move();
		farmer.move();
		dir = 4 * cow.d + farmer.d;
		pos = farmer.x + (10 * farmer.y) + (100 * cow.x) + (1000 * cow.y);
		if (state[dir][pos]) {
			count = 0; break;
		}
		state[dir][pos] = true;
	}
	output << count << endl;
}