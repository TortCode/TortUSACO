/*
ID: teerth.1
PROG: zerosum
LANG: C++
*/
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
using namespace std;
typedef pair<string, int> psi;
int N;
int loc; //global position within tested sequence.
int oper[10]; //starts at 2, goes to 9
//0is_ 1is+ 2is-

psi run_together(int n)
{
	string s = to_string(n);
	int sum = n;
	for (int i = n + 1; i <= N && oper[i] == 0; i++) {
		sum = sum * 10 + i;
		s += " " + to_string(i);
	}
	loc = i;
	return psi(s, sum);
}

int main()
{
	vector<string> seqs;
	ifstream input("zerosum.in");
	ofstream output("zerosum.out");
	input >> N;
	input.close();

	int POWER = pow(3, N - 1);
	for (int i = 0; i < POWER; i++) {
		int p = i;
		for (int j = N; j >= 2; j--) {
			oper[j] = p % 3;
			p /= 3;
		}
		psi init = run_together(1);
		int sum = init.second;
		string s = init.first;
		while (loc <= N) {
			psi var;
			if (oper[loc] == 2) {
				var = run_together(loc);
				sum += var.second;
				s += "+" + var.first;
			}
			if (oper[loc] == 3) {
				var = run_together(loc);
				sum -= var.second;
				s += "-" + var.first;
			}
		}
		//output
		if (sum == 0)
			output << s << '\n';
	}
	output.close();
}
