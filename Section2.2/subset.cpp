/*
ID: teerth.1
PROG: subset
LANG: C++
*/
#include <fstream>
using namespace std;

int main()
{
	int n;
	unsigned int poss[39+1][390+1]{{1}};
	ifstream input("subset.in");
	ofstream output("subset.out");
	input >> n;
	input.close();
	if (n*(n + 1) % 4 != 0) { //half sum is not int
		output << 0 << '\n';
		output.close();
		return 0;
	}
	for (int last = 1; last <= n; last++) //last integer in set considered
		int bigSum = last*(last+1)/4;
		for (int sum = 0; sum < bigSum; sum++)
			poss[last][sum] = poss[last-1][sum]		//last excluded
			+ (last <= sum) ? poss[last-1][sum-last] : 0;	//last included
	
	output << poss[sum][n*(n+1)/4] / 2 << '\n';
	output.close();
}
