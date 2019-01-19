/*
ID: teerth.1
PROG: milk3
LANG: C++
*/
#include <fstream>
#include <vector>
int ABC[3];
bool seen[21][21];
bool solutions[21];

struct Buckets {
	int abc[3]; // 0 a, 1 b, 2 c
	Buckets(int a, int b, int c)
	{
		abc[0] = a;
		abc[1] = b;
		abc[2] = c;
	}
	static Buckets pour(Buckets amts, int from, int to)
	{
		int transfer = amts.abc[from];
		if (amts.abc[to] + amts.abc[from] > ABC[to])
			transfer = ABC[to] - amts.abc[to];
		amts.abc[to] += transfer;
		amts.abc[from] -= transfer;
		return amts;
	}
};

void branchSolution(Buckets amts)
{
	if (seen[amts.abc[1]][amts.abc[2]])
		return;
	else
		seen[amts.abc[1]][amts.abc[2]] = true;

	if (amts.abc[0] == 0) {
		solutions[amts.abc[2]] = true;
	}

	for (int i = 0; i < 9; i++) {
		int from = i % 3;
		int to = i / 3;
		branchSolution(Buckets::pour(amts, from, to));
	}
};

int main()
{
	std::ifstream input("milk3.in");
	input >> ABC[0] >> ABC[1] >> ABC[2];
	input.close();

	Buckets start = Buckets(0, 0, ABC[2]);
	branchSolution(start); //num

	std::ofstream output("milk3.out");
	std::vector<int> sols;
	for (int i = 0; i <= 20; i++) {
		if (solutions[i])
			sols.push_back(i);
	}
	for (int i = 0; i < sols.size(); i++) {
		output << sols[i];
		if (i < sols.size() - 1)
			output << " ";
		else
			output << std::endl;
	}
	output.close();
}