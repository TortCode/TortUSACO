/*
ID: teerth.1
PROG: subset
LANG: C++
*/
#include <fstream>
#include <algorithm>
using namespace std;

int n;
unsigned int poss[40][391];

unsigned int getPoss(int start, int sum)
{
	if (start < 0 || sum < 0) return 0;
	if (poss[start][sum] == -1)
		poss[start][sum] = getPoss(start - 1, sum) + getPoss(start - 1, sum - start);
	return poss[start][sum];
}

int main()
{
	fill(poss[0], poss[0] + 40 * 391, -1); 
	poss[0][0] = 1;
	ifstream input("subset.in");
	ofstream output("subset.out");
	input >> n;
	input.close();
	if (n*(n + 1) % 4 != 0) { //half sum is not int
		output << 0 << '\n';
		output.close();
		return 0;
	}
	
	unsigned int possSum = getPoss(n, n*(n + 1) / 4);
	output << possSum / 2 << '\n';
	output.close();
}
