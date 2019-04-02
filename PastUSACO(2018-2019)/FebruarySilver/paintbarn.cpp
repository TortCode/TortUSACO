#include <fstream>
#include <cstring>
using namespace std;

int coats[1001][1001];

int main()
{
	int n, k;
	ifstream input("paintbarn.in");
	input >> n >> k;
	int x1, y1, x2, y2, x, y;
	for (int i = 0; i < n; ++i) {
		input >> x1 >> y1 >> x2 >> y2;
		for (x = x1; x < x2; ++x)
			for (y = y1; y < y2; ++y)
				++coats[x][y];
	}
	input.close();

	int area = 0;
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++)
			if (coats[i][j] == k) area++;
	ofstream output("paintbarn.out");
	output << area << "\n";
	output.close();
}