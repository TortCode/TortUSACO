/*
ID: teerthp
PROG: mixmilk
LANG: C++
*/
#include <fstream>
#include <algorithm>

struct Bucket {
	int capac, amount;

	int overflow()
	{
		return std::max(amount - capac, 0);
	}
} pails[3];

void transfer(Bucket& from, Bucket& to)
{
	to.amount += from.amount;
	from.amount = to.overflow();
	to.amount -= to.overflow();
}

int main()
{
	std::ifstream input("mixmilk.in");
	for (int i = 0; i < 3; i++) {
		input >> pails[i].capac >> pails[i].amount;
	}
	input.close();

	int from;
	for (int mix = 0; mix < 100; mix++) {
		from = mix % 3;
		transfer(pails[from], pails[(from + 1) % 3]);
	}

	std::ofstream output("mixmilk.out");
	for (int i = 0; i < 3; i++) {
		output << pails[i].amount << std::endl;
	}
	output.close();
}