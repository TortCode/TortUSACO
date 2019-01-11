/*
ID: teerth.1
PROG: ariprog
LANG: C++
*/
#include <fstream>
#include <algorithm>
#include <vector>

int N, M; //len of seq; parameter for set of sum of squares
std::vector<int> sumsquares(1);

int loc;
inline bool searchValue(int start, int target)
{
	for (loc = start; loc < sumsquares.size(); loc++) {
		if (sumsquares[loc] == target)
			return true;
		if (sumsquares[loc] > target)
			return false;
	}
	return false;
}
/*inline bool seqExists(int start, int a, int b)
{
	loc = start;
	for (int n = 0; n < N; n++) {
		if (!searchValue(loc, a + n * b))
			return false;
	}
	return true;
}*/

int main()
{
	std::ifstream input("ariprog.in");
	std::ofstream output("ariprog.out");
	input >> N >> M;
	input.close();

	for (int p = 0; p <= M; p++) { //generate squareSums
		for (int q = 0; q <= p; q++) {
			sumsquares.push_back(p * p + q * q);
		}
	}

	sort(sumsquares.begin(), sumsquares.end());
	for (int i = sumsquares.size() - 1; i > 0; i--) {
		if (sumsquares[i] == sumsquares[i - 1])
			sumsquares.erase(sumsquares.begin() + i);
	}
	int size = sumsquares.size();
	
	int a, b, sol = 0;
	int maxB = (sumsquares[size - 1] - sumsquares[0]) / (N - 1);
	bool isSol;
	for (int b = 1; b <= maxB; b++) {
		for (int i = 0; i < size - N; i++) {
			a = sumsquares[i];
			isSol = true;
			loc = i;
			for (int n = 0; n < N; n++) {
				if (!searchValue(loc, a + n * b))
					isSol = false;
			}
			if (isSol) {
				output << a << " " << b << std::endl;
				sol++;
			}
		}
	}

	if (sol == 0)
		output << "NONE" << std::endl;

	output.close();

}
