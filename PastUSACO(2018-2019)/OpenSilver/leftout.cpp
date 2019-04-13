#include <fstream>
#include <bitset>
#include <string>
using namespace std;

bitset<1000> grid[1000];
int n;
void vert_flip(int col)
{
	for (int i = 0; i < n; i++)
		grid[i][col] = !grid[i][col];
}

int main()
{
	ifstream input("leftout.in");
	ofstream output("leftout.out");
	input >> n;
	string s;
	for (int i = 0; i < n; i++) {
		input >> s;
		for (int j = 0; j < n; j++)
			if (s[j] == 'R') grid[i][j] = true;
	}
	input.close();

	if (!grid[0][0]) grid[0].flip();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i != 0 && !grid[i - 1][j]) vert_flip(j);
			if (j != 0 && !grid[i][j - 1]) grid[i].flip();
		}

	int x=-1, y=-1;
	int count = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!grid[i][j]) {
				count++;
				if (x == -1) {
					x = i;
					y = j;
				}
			}
OUT:
	if (count > 1 || count == 0)
		output << -1 << '\n';
	else
		output << x + 1 << ' ' << y + 1 << '\n';
	output.close();
}