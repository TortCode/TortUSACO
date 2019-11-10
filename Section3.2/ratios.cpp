/*
ID: teerth.1
PROG: ratios
LANG: C++
*/
#include <fstream>
using namespace std;

struct Triple {
	int a, b, c;
	Triple() : Triple(0, 0, 0) {}
	Triple(int _b, int _o, int _w) : a(_b), b(_o), c(_w) {}
	Triple operator+(Triple rhs)
	{
		return Triple(a + rhs.a, b + rhs.b, c + rhs.c);
	}
	Triple operator*(int mult)
	{
		return Triple(a*mult, b*mult, c*mult);
	}
	bool isMultiple(Triple rat)
	{
		int k = (a + b + c) / (rat.a + rat.b + rat.c);
		return a == k * rat.a && b == k * rat.b && c == k * rat.c;
	}
} goal, r1, r2, r3;

int main()
{
	ofstream output("ratios.out");
	ifstream input("ratios.in");

	input >> goal.a >> goal.b >> goal.c;
	input >> r1.a >> r1.b >> r1.c;
	input >> r2.a >> r2.b >> r2.c;
	input >> r3.a >> r3.b >> r3.c;

	if (goal.a + goal.b + goal.c == 0) {
		output << "0 0 0 0\n";
		return 0;
	}
	int i, j, k;
	int minSum = 0;
	Triple optimal, mix;
	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++)
			for (k = 0; k < 100; k++) {
				mix = r1 * i + r2 * j + r3 * k;
				if ((minSum == 0 || i + j + k < minSum) && mix.isMultiple(goal)) {
					minSum = i + j + k;
					optimal = Triple(i, j, k);
				}
			}
	Triple total = r1 * optimal.a + r2 * optimal.b + r3 * optimal.c;
	if (minSum == 0)
		output << "NONE\n";
	else
		output << optimal.a << " " << optimal.b << " " << optimal.c << " "
		<< (total.a + total.b + total.c) / (goal.a + goal.b + goal.c) << "\n";
}