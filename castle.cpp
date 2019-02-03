/*
ID: teerth.1
PROG: castle
LANG: C++
*/
#include <fstream>
#include <vector>
using namespace std;

short modules[51][51]; //stored walls in bit form SENW
short components[51][51];
vector<short> compSizes(1);

void visit(int i, int j, int compID)
{
	if (components[i][j] != 0) return;
	components[i][j] = compID;
	compSizes[compID]++;

	if (!(modules[i][j] & 0b1000)) visit(i + 1, j, compID); //S
	if (!(modules[i][j] & 0b0100)) visit(i, j + 1, compID); //E
	if (!(modules[i][j] & 0b0010)) visit(i - 1, j, compID); //N
	if (!(modules[i][j] & 0b0001)) visit(i, j - 1, compID); //W
}

int main()
{
	int M, N; //width and height
	ifstream input("castle.in");
	ofstream output("castle.out");
	input >> M >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			input >> modules[i][j];
	input.close();

	int curComponent = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (components[i][j] == 0) {
				compSizes.push_back(0);
				visit(i, j, ++curComponent);
			}
		}
	}
	output << curComponent << '\n'; //number of rooms

	short maxRoom = 0;
	for (short n : compSizes) maxRoom = (n > maxRoom) ? n : maxRoom;
	output << maxRoom << '\n'; //size of largest room

	short maxCreated = 0;
	pair<pair<int, int>, char>  maxLoc; //<i,j>, direc

	short createdSize;
	for (int j = 1; j <= M; j++) {
		for (int i = N; i >= 1; i--) {
			if (i > 1 && (components[i][j] != components[i - 1][j])) { //N
				createdSize = compSizes[components[i][j]] + compSizes[components[i - 1][j]];
				if (createdSize > maxCreated) {
					maxCreated = createdSize;
					maxLoc = make_pair(make_pair(i, j), 'N');
				}
			}
			if ( j < M && (components[i][j] != components[i][j + 1]) ) { //E
				createdSize = compSizes[components[i][j]] + compSizes[components[i][j + 1]];
				if (createdSize > maxCreated) {
					maxCreated = createdSize;
					maxLoc = make_pair(make_pair(i, j), 'E');
				}
			}
		}
	}
	output << maxCreated << '\n'; //largest room by removing one wall
	output << maxLoc.first.first << ' ' << maxLoc.first.second << ' ' << maxLoc.second << endl; //location of solution to wall, most west, then most south, then 'n' priority over 'e'
	output.close();
}