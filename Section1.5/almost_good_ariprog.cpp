/*
ID: teerth.1
PROG: ariprog
LANG: C++
*/
#include <fstream>
#include <bitset>

int N, M; //len of seq; parameter for set of bisquares
std::bitset<125001> bisquares; //if bisquares[i] then i is bisquare

inline bool seqExists(int term, const int& b)
{
	for (int n = 1; n < N; n++) {
		term += b;
		if (!bisquares[term]) return false;
	}
	return true;
}

int main()
{
	std::ifstream input("ariprog.in");
	std::ofstream output("ariprog.out");
	input >> N >> M;
	input.close();

	//generate bisquares
	for (int p = 0; p <= M; p++) {
		for (int q = 0; q <= p; q++) {
			bisquares[p * p + q * q] = true;
		}
	}

	const int maxBisquare = 2 * M * M;
	const int maxB = maxBisquare / (N - 1);

	int sol = 0, maxA;
	for (unsigned int b = 1; b <= maxB; b++) {
		maxA = maxBisquare - (N - 1) * b;
		for (unsigned int a = 0; a <= maxA; a++) {
			if (bisquares[a])
				if (seqExists(a, b)) {
					output << a << " " << b << std::endl;
					sol++;
				}
		}
	}
	if (sol == 0) {
		output << "NONE" << std::endl;
	}
	output.close();
}
