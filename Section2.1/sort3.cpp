/*
ID: teerth.1
PROG: sort3
LANG: C++
*/
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
	short N, values[1000];
	short keyCount[4]{ 0 };
	ifstream input("sort3.in");
	input >> N;
	for (short i = 0; i < N; i++) {
		input >> values[i];
		keyCount[values[i]]++;
	}
	short end1 = keyCount[1];
	short end2 = end1 + keyCount[2];

	short valPositions[4][4]{ 0 }; //[value][region]
	for (short i = 0; i < end1; i++) //allocated to 1s
		valPositions[values[i]][1]++;
	for (short i = end1; i < end2; i++) //allocated to 2s
		valPositions[values[i]][2]++;
	for (short i = end2; i < N; i++) //allocated to 3s
		valPositions[values[i]][3]++;

	short minOps = valPositions[1][3] + valPositions[1][2] + valPositions[2][3] + fmax(valPositions[1][3] - valPositions[3][1], 0); //you figure it out
	ofstream output("sort3.out");
	output << minOps << '\n';
	output.close();
}