/*
ID: teerth.1
PROG: ariprog
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <vector>

int N, M;

bool searchValue(const std::vector<int>& vec, int start, int target)
{
	return true;
}

int main()
{
	std::ifstream input("ariprog.in");
	input >> N >> M;
	input.close();

	std::vector<int> bisquares;

	for (int p = 0; p <= M; p++) {
		for (int q = 0; q <= p; q++) {
			bisquares.push_back(p*p + q * q);
		}
	}



}
