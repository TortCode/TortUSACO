#include <fstream>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;

int N;
int regionCounter = 0;
char iceCream[1000][1000];
bool isFilled[1000][1000]; //stores regionID for each character on iceCream

struct region {
	int area = 0;
	int perimeter = 0;
};

vector<region> blobs;

inline bool outOfBounds(int n) { return n < 0 || n >= N; }

void flood(int i, int j)
{
	if (outOfBounds(i) || outOfBounds(j)) {
		blobs[regionCounter].perimeter++;
		return;
	}
	if (iceCream[i][j] == '.') {
		blobs[regionCounter].perimeter++;
		return;
	}
	if (!isFilled[i][j]) {
		blobs[regionCounter].area++;
		isFilled[i][j] = true;
		flood(i, j + 1);
		flood(i, j - 1);
		flood(i + 1, j);
		flood(i - 1, j);
	}
}

int main()
{
	ifstream input("perimeter.in");
	input >> N;
	for (int i = 0; i < N; i++) {
		string line;
		input >> line;
		for (int j = 0; j < N; j++) {
			iceCream[i][j] = line[j];
		}
	}
	input.close();
	
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (iceCream[x][y] == '#' && !isFilled[x][y]) {
				blobs.emplace_back();
				flood(x, y);
				regionCounter++;
			}
		}
	}

	int minPerim = blobs[0].perimeter, maxArea = blobs[0].area;
	for (region blob : blobs) {
		if (blob.area > maxArea) {
			maxArea = blob.area;
			minPerim = blob.perimeter;
		}
		if (blob.area == maxArea && blob.perimeter < minPerim)
			minPerim = blob.perimeter;
	}

	ofstream output("perimeter.out");
	output << maxArea << " " << minPerim << endl;
	output.close();
}