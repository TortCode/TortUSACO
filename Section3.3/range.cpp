/*
ID: teerth.1
PROG: range
LANG: C++
*/
#include <fstream>
#include <array>
#include <string>
using namespace std;

ifstream input("range.in");
ofstream output("range.out");

constexpr int MAXSIDE = 250;
using Field = array<array<bool, MAXSIDE>, MAXSIDE>;
Field field1, field2;

int sidelen;

void printNumGrazing(int size, Field& prev, Field& next)
{
	if (size > sidelen) return;

	int count = 0;
	int dim = sidelen - size + 1;

	for (int i = 0; i < dim; ++i)
	{
		for (int j = 0; j < dim; ++j)
		{
			next[i][j] = prev[i][j] && prev[i][j + 1] && prev[i + 1][j] && prev[i + 1][j + 1];
			if (next[i][j]) ++count;
		}
	}
	
	if (count > 0) output << size << ' ' << count << endl;

	printNumGrazing(size + 1, next, prev);
}

int main()
{
	input >> sidelen;
	string line;
	for (int i = 0; i < sidelen; ++i)
	{
		input >> line;
		for (int j = 0; j < sidelen; ++j)
			field1[i][j] = (line[j] == '1');
	}

	printNumGrazing(2, field1, field2);
}