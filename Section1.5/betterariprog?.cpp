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
	
  int sol = 0;
	const int maxB = maxBisquare / (N - 1);
  for (unsignt int b = 1; b <= maxB; b++) {
	  for (unsigned int a = 0; a <= maxBisquare; a++) {
		  if (bisquares[a] && (a+(N-1)*b) <= maxBisquare))
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
