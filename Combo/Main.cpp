/*
ID: teerth.1
PROG: combo
LANG: C++
*/
#include <fstream>
#include <cmath>

using namespace std;

double halfN;
//calculate the Modular Distance mod N between x and y
inline int calcModularDist(int x, int y)
{
	return (halfN - abs(halfN - abs(x - y)));
}

int main()
{
	ifstream fin("combo.in");
	ofstream fout("combo.out");
	int farmer[3], master[3], N;

	fin >> N;
	halfN = N / 2;
	fin >> farmer[0] >> farmer[1] >> farmer[2];
	fin >> master[0] >> master[1] >> master[2];
	fin.close();

	int duplicate[3]{ 0 };
	for (int i = 0; i < 3; i++) {
		int farmNum = farmer[i], masterNum = master[i], closeFarmerNumber;
		for (int diff = -2; diff <= 2; diff++) {
			closeFarmerNumber = (farmNum + diff + N) % N; //(add N) mod N gets rid of negs
			if (calcModularDist(closeFarmerNumber, masterNum) <= 2)
				duplicate[i]++;
		}
	}

	int settings = 250; //125 for farmer, 125 for master
	settings -= duplicate[0] * duplicate[1] * duplicate[2]; //take away duplicate cases
	if (settings > pow(N, 3)) settings = pow(N, 3); //if N < 5, case for farmer and master < 125

	fout << settings << endl;
	fout.close();
}