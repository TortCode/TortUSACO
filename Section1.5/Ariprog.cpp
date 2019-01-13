/*
ID: teerth.1
PROG: ariprog
LANG: C++
*/
#include <fstream>
#include <algorithm>
#include <vector>
#include <bitset>

int N, M; //len of seq; parameter for set of bisquares
int maxBisquare;
std::vector<std::pair<int, int>> sequences;
std::bitset<125001> bisquares; //if bisquares[i] then i is bisquare

inline bool seqExists(const int& a, const int& b)
{
	int term = a;
	for (int n = 1; n < N; n++) {
		term += b;
		if (term > maxBisquare || !bisquares[term]) return false;
	}
	return true;
}

int main()
{
	std::ifstream input("ariprog.in");
	std::ofstream output("ariprog.out");
	input >> N >> M;
	input.close();

	maxBisquare = 2 * M * M;
	//generate bisquares
	for (int p = 0; p <= M; p++) {
		for (int q = 0; q <= p; q++) {
			bisquares[p * p + q * q] = true;
		}
	}
	
	const int maxB = 2 * M * M / (N - 1);
	for (unsigned int a = 0; a <= maxBisquare; a++) {
		if (bisquares[a])
			for (unsigned int j = a + 1; j <= maxBisquare; j++) {
				if (bisquares[j]) {
					int b = j - a;
					if (b > maxB) break;
					if (seqExists(a, b)) {
						sequences.push_back(std::make_pair(a, b));
					}
				}
			}
	}

	if (sequences.size() == 0) {
		output << "NONE" << std::endl;
	}
	else {
		sort(sequences.begin(), sequences.end(), [](std::pair<int, int> x, std::pair<int, int> y) {
			return (x.second == y.second) ? x.first < y.first : x.second < y.second;
		});
		for (std::pair<int, int> solution : sequences)
			output << solution.first << " " << solution.second << std::endl;
	}
	output.close();
}