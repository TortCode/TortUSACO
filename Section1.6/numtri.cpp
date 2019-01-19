/*
ID: teerth.1
PROG: numtri
LANG: C++
*/
#include <fstream>
#include <algorithm>
using namespace std;

int maxSums1[1000], maxSums2[1000]; //represents max possible sum getting to a point

int main()
{
	int R;
	int current;
	int* prevSums = maxSums1; //pointers for swapping
	int* curSums = maxSums2;

	ifstream input("numtri.in");
	input >> R >> curSums[0];
	for (int r = 1; r < R; r++) {
		swap(prevSums, curSums);

		input >> current;
		curSums[0] = prevSums[0] + current;
		for (int c = 1; c <= r; c++) {
			input >> current;
			curSums[c] = max(prevSums[c - 1], prevSums[c]) + current;
		}
	}
	input.close();

	int max = 0;
	for (int c = 0; c <= R; c++)
		if (curSums[c] > max)
			max = curSums[c];

	ofstream output("numtri.out");
	output << max << endl;
	output.close();
}
