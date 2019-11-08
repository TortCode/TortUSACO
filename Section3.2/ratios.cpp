/*
ID: teerth.1
PROG: ratios
LANG: C++
*/
#include <fstream>
using namespace std;

struct Ratio3 {
	int a, b, c;
	Ratio3() : Ratio3(0, 0, 0) {}
	Ratio3(int _b, int _o, int _w) : a(_b), b(_o), c(_w) {}
	Ratio3 operator+(Ratio3 rhs)
	{
		return Ratio3(a + rhs.a, b + rhs.b, c + rhs.c);
	}
	Ratio3 operator*(int mult)
	{
		return Ratio3(a*mult, b*mult, c*mult);
	}
	bool isMultiple(Ratio3 rat)
	{
		int k = a / rat.a;
		return a == k * rat.a && b == k * rat.b && c == k * rat.c;
	}
} goal, r1, r2, r3;

Ratio3 mixes[100][100][100];

int main()
{
	ifstream input("ratios.in");
	ofstream output("ratios.out");
	input >> goal.a >> goal.b >> goal.c;
	input >> r1.a >> r1.b >> r1.c;
	input >> r2.a >> r2.b >> r2.c;
	input >> r3.a >> r3.b >> r3.c;

	int i, j, k;
	int min = 0;
	Ratio3 optimal;
	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++)
			for (k = 0; k < 100; k++) {
				mixes[i][j][k] = r1 * i + r2 * j + r3 * k;
				if ((min == 0 || i + j + k < min) && mixes[i][j][k].isMultiple(goal)) {
					min = i + j + k;
					optimal = Ratio3(i, j, k);
				}
			}

	if (min == 0)
		output << "NONE\n";
	else
		output << optimal.a << " " << optimal.b << " " << optimal.c << " " 
		<< (r1.a * optimal.a + r2.a * optimal.b + r3.a * optimal.c) / goal.a << "\n";
}