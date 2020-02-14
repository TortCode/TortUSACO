/*
ID: teerth.1
PROG: fence9
LANG: C++
*/
#include <fstream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	int t;
	if (a < b)
	{
		t = a;
		a = b;
		b = t;
	}
	while (b != 0)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main()
{
	int n, m, p;
	ifstream input("fence9.in");
	ofstream output("fence9.out");
	input >> n >> m >> p;
	int B = p + gcd(n, m) + gcd(abs(p - n), m);
	// Picks Thm: Area = I + B/2 - 1 -> I = 1 + Area - B/2
	output << 1 + (m*p - B) / 2 << endl;
}