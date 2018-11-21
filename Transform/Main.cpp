/*
ID: teerth.1
PROG: transform
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream fin("transform.in");
	ofstream fout("transform.out");
	char parent[10][10];
	char trans[10][10];

	int N = 0;
	fin >> N;
	int n = N - 1;
	string line;
	for (int i = 0; i < N; i++) { //take first 
		fin >> line;
		for (int j = 0; j < N; j++) {
			parent[i][j] = line[j];
		}
	}
	for (int i = 0; i < N; i++) { //take second
		fin >> line;
		for (int j = 0; j < N; j++) {
			trans[i][j] = line[j];
		}
	}
	fin.close();

	unsigned char possTran[8] = { 1, 2, 3, 4, 5, 5, 5, 6 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (parent[i][j] != trans[i][j])			//6: no change
				possTran[7] = 0;
			if (parent[i][j] != trans[j][i])			//5: combo 270
				possTran[6] = 0;
			if (parent[i][j] != trans[n - i][j])		//5: combo 180
				possTran[5] = 0;
			if (parent[i][j] != trans[n - j][n - i])	//5: combo 90
				possTran[4] = 0;
			if (parent[i][j] != trans[i][n - j]) 		//4: reflection
				possTran[3] = 0;
			if (parent[i][j] != trans[n - j][i])		//3: rotate 270
				possTran[2] = 0;
			if (parent[i][j] != trans[n - i][n - j])	//2: rotate 180
				possTran[1] = 0;
			if (parent[i][j] != trans[j][n - i])		//1: rotate 90
				possTran[0] = 0;
		}
	}

	int retCode = 7;
	for (int ret = 0; ret < 8; ret++) {
		if (possTran[ret] != 0) {
			retCode = possTran[ret];
			break;
		}
	}
	fout << retCode << endl;
	fout.close();

}
