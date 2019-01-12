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

int loc;
/*inline bool searchValue(int start, int target)
{
	for (loc = start; loc < sumsquares.size(); loc++) {
		if (sumsquares[loc] == target)
			return true;
		if (sumsquares[loc] > target)
			return false;
	}
	return false;
}*/
inline bool seqExists(int start, const int& a, const int& b)
{
	int target = a;
	bool exists;
	for (int n = 0; n < N; n++) {
		for (; start < bisquares.size() - 1; start++) {
			if (bisquares[start] >= target) break;
		}
		if (bisquares[start] != target)
			return false;
		target += b;
	}
	return true;
}

int main()
{
	std::ifstream input("ariprog.in");
	std::ofstream output("ariprog.out");
	input >> N >> M;
	input.close();

	for (int p = 0; p <= M; p++) { //generate squareSums
		for (int q = 0; q <= p; q++) {
			bisquares.push_back(p * p + q * q);
		}
	}

	sort(bisquares.begin(), bisquares.end());
	for (int i = bisquares.size() - 1; i > 0; i--) {
		if (bisquares[i] == bisquares[i - 1])
			bisquares.erase(bisquares.begin() + i);
	}
	int size = bisquares.size();

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
