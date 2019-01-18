/*
ID: teerth.1
PROG: milk3
LANG: C++
*/
#include <fstream>

int ABC[3];
bool solutions[21];

struct Buckets {
	int abc[3]; // 0 a, 1 b, 2 c
	
	Buckets(const Buckets& copy)
	{
		this->abc[0] = copy.abc[0];
		this->abc[1] = copy.abc[1];
		this->abc[2] = copy.abc[2];
	}

	void pour(int from, int to)
	{

	}
};

void branchSolution(Buckets amts, int left)
{
	if (amts.abc[0] == 0) {
		if (!solutions[amts.abc[2]]) {
			solutions[amts.abc[2]] = true;
			branchSolution(amts, 4);
		}
	}
	if (left == 0) return;

	for (int i = 0; i < 9; i++) {
		int from = i % 3;
		int to = i / 3;
		if (amts.abc[from] != 0) {
			
		}
	}
};

int main()
{
	std::ifstream input("milk3.in");
	input >> ABC[0] >> ABC[1] >> ABC[2];
	input.close();

	std::ofstream output("milk3.in");
	for (int i = 0; i < 20; i++) {
		if (solutions[i])
			output << i << " ";
	}
	output << std::endl;
	output.close();
}