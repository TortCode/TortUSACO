/*
ID: teerth.1
PROG: fracdec
LANG: C++
*/
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int pos[1000000];

int main()
{
	int N, D;
	ifstream input("fracdec.in");
	ofstream output("fracdec.out");
	input >> N >> D;
	input.close();

	string decimal = "";
	decimal += to_string(N / D) + ".";
	if (N % D == 0)decimal += "0";
	vector<int> quotient;

	for (int i = 0; i < 1000000; i++) pos[i] = -1;

	//intermediate dividend and remainder
	int div = 10 * (N % D);
	for (int i = 0;; i++, div *= 10) {
		if (pos[div] == -1)
			pos[div] = i;
		else break;
		quotient.push_back(div / D);
		div = div % D;
	}
	//construct full number
	int prevPos = pos[div];
	for (int i = 0; i < prevPos; i++) decimal += to_string(quotient[i]);
	if (div != 0) {
		decimal += "(";
		for (int i = prevPos; i < quotient.size(); i++) decimal += to_string(quotient[i]);
		decimal += ")";
	}
	//print
	int w = 0;
	for (char c : decimal) {
		if (w == 76) {
			w = 0;
			output << '\n';
		}
		output << c;
		w++;
	}
	output << endl;

}