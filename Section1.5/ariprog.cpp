/*
ID: teerth.1
PROG: ariprog
LANG: C++
*/
#include <fstream>
#include <algorithm>
#include <vector>

int N, M; //len of seq; parameter for set of sum of squares

std::vector<int> bisquares(1);

inline bool searchValue(int start, int target)
{
	for (int i = start; i < bisquares.size(); i++) {
		if (bisquares[i] == target)
			return true;
	}
	return false;
}
inline bool seqExists(int start, int a, int b)
{
	for (int n = 0; n < N; n++) {
		if (!searchValue(start, a + n * b))
			return false;
	}
	return true;
}

int main()
{
	std::ifstream input("ariprog.in");
	std::ofstream output("ariprog.out");
	input >> N >> M;
	input.close();

	int sqSum;
	for (int p = 0; p <= M; p++) { //generate squareSums
		for (int q = 0; q <= p; q++) {
			sqSum = p * p + q * q;
			if (!searchValue(0, sqSum))
				bisquares.push_back(sqSum);
		}
	}

	int size = bisquares.size();
	sort(bisquares.begin(), bisquares.end());

	int a, b, sol = 0;
	int maxB = (bisquares[size - 1] - bisquares[0]) / (N - 1);
	for (int b = 1; b <= maxB; b++) {
		for (int i = 0; i < size - N; i++) {
			a = bisquares[i];
			if (seqExists(i, a, b)) {
				output << a << " " << b << std::endl;
				sol++;
			}
		}
	}

	if (sol == 0)
		output << "NONE" << std::endl;
	
	output.close();

}
