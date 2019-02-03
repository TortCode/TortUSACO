/*
ID: teerth.1
PROG: frac1
LANG: C++
*/
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Fraction {
	short num, denom;
	Fraction(short n, short d) : num(n), denom(d) {} 
	bool operator==(const Fraction &rhs)
	{
		return (num * rhs.denom) == (denom * rhs.num);
	}
	static bool lessThan(const Fraction &lhs, const Fraction &rhs)
	{
		return (lhs.num * rhs.denom) < (lhs.denom * rhs.num);
	}
};

int main()
{
	int N;
	ifstream input("frac1.in");
	input >> N;
	input.close();

	vector<Fraction> fractions;
	fractions.push_back(Fraction(0, 1)); fractions.push_back(Fraction(1, 1)); //element 1 and 2
	for (short d = 1; d <= N; d++) {
		for (short n = 1; n < d; n++) {
			fractions.push_back(Fraction(n, d));
		}
	}

	for (int i = 2; i < fractions.size(); i++) {
		for (int j = i + 1; j < fractions.size(); j++) {
			if (fractions[i] == fractions[j]) {
				if (fractions[i].denom < fractions[j].denom) //i more reduced than j
					fractions.erase(fractions.begin() + j);
				else
					fractions.erase(fractions.begin() + i);
				j--; //stay here and check new frac
			}
		}
	}

	sort(fractions.begin(), fractions.end(), Fraction::lessThan);

	ofstream output("frac1.out");
	for (Fraction f : fractions)
		output << f.num << '/' << f.denom << '\n';
	output.close();
}
