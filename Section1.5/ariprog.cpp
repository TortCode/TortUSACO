/*
ID: teerth.1
PROG: ariprog
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <vector>

int N, M;

inline bool searchValue(const std::vector<int>& vec, int start, int target)
{
	int i;
	for (i = start; i < vec.size(); i++) {
		if (vec[i] == target)
			return true;
		if (vec[i] > target)
			return false;
	}
	return false;
}

int main()
{
	std::ifstream input("ariprog.in");
	input >> N >> M;
	input.close();

	std::vector<int> bisquares(1);

	int sqSum;
	for (int p = 0; p <= M; p++) {
		for (int q = 0; q <= p; q++) {
			sqSum = p * p + q * q;
			if (!searchValue(bisquares, 0, sqSum))
				bisquares.push_back(sqSum);
		}
	}



}
