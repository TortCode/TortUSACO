/*
ID: teerth.1
PROB: hamming
LANG: C++
*/
#include <fstream>
using namespace std;

int n, b, d;
int codeword[64]{ 0 };

bool isFar(int a, int b)
{
	int xors = a ^ b;
	int dist = 0;
	while (xors > 0) {
		dist++;
		xors = xors & (xors - 1);
	}
	return dist >= d;
}

bool closeToAny(int word, int pos) {
	for (int i = 0; i < pos; i++)
		if (!isFar(word, codeword[i]))
			return true;
	return false;
}

int main()
{
	ifstream input("hamming.in");
	input >> n >> b >> d;
	input.close();

	for (int i = 1; i < n; i++) {
		int word = codeword[i - 1] + 1;
		while (closeToAny(word, i)) word++;
		codeword[i] = word;
	}

	ofstream output("hamming.out");
	for (int i = 1; i <= n; i++) {
		output << codeword[i-1];
		if (i % 10 == 0 || i == n)
			output << "\n";
		else
			output << " ";
	}
	output.close();
}