/*
ID: teerth.1
PROG: kimbits
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

int numSet(int n) {
	int i = 0;
	while (n != 0) {
		i += n & 1;
		n >>= 1;
	}
	return i;
}

int N, L, I;
string toBinaryString(int n) {
	string ret;
	while (n != 0) {
		ret = to_string(n & 1) + ret;
		n >>= 1;
	}
	while (ret.length() < N)
		ret = "0" + ret;
	return ret;
}

int main()
{
	ifstream input("kimbits.in");
	ofstream output("kimbits.out");
	input >> N >> L >> I;
	input.close();

	int num = 0;
	for (int i = 0;;) {
		if (numSet(num) <= L) {
			i++;
		}
		if (i == I)
			break;
		num++;
	}

	output << toBinaryString(num) << endl;
	output.close();
}