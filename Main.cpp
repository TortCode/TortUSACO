/*
ID: teerth.1
PROG: ride
LANG: C++
*/
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream input("ride.in");
	ofstream output("ride.out");
	int prod1 = 1;
	int prod2 = 1;
	string str1, str2;
	input >> str1 >> str2;

	for (char c : str1) {
		prod1 *= (c - 'A' + 1);
	}
	for (char c : str2) {
		prod2 *= (c - 'A' + 1);
	}
	if (prod1 % 47 == prod2 % 47) output << "GO" << endl;
	else output << "STAY" << endl;

	input.close();
	output.close();

}