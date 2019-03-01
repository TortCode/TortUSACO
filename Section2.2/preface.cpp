/*
ID: teerth.1
PROG: preface
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

string getRoman(int n)
{
	int ones = n % 10; n /= 10;
	int tens = n % 10; n /= 10;
	int hund = n % 10; n /= 10;
	int thou = n % 10;

	string result;
	switch (thou) {
	case 1: result += "M"; break;
	case 2: result += "MM"; break;
	case 3: result += "MMM"; break;
	}
	switch (hund) {
	case 1: result += "C"; break;
	case 2: result += "CC"; break;
	case 3: result += "CCC"; break;
	case 4: result += "CD"; break;
	case 5: result += "D"; break;
	case 6: result += "DC"; break;
	case 7: result += "DCC"; break;
	case 8: result += "DCCC"; break;
	case 9: result += "CM"; break;
	}
	switch (tens) {
	case 1: result += "X"; break;
	case 2: result += "XX"; break;
	case 3: result += "XXX"; break;
	case 4: result += "XL"; break;
	case 5: result += "L"; break;
	case 6: result += "LX"; break;
	case 7: result += "LXX"; break;
	case 8: result += "LXXX"; break;
	case 9: result += "XC"; break;
	}
	switch (ones) {
	case 1: result += "I"; break;
	case 2: result += "II"; break;
	case 3: result += "III"; break;
	case 4: result += "IV"; break;
	case 5: result += "V"; break;
	case 6: result += "VI"; break;
	case 7: result += "VII"; break;
	case 8: result += "VIII"; break;
	case 9: result += "IX"; break;
	}
	return result;
}

int main()
{
	int n;
	string preface;
	ifstream input("preface.in");
	input >> n;
	input.close();

	int I = 0, V = 0, X = 0, L = 0, C = 0, D = 0, M = 0;
	for (int i = 1; i <= n; i++)
		for (char c : getRoman(i))
			switch (c) {
			case 'I': I++; break;
			case 'V': V++; break;
			case 'X': X++; break;
			case 'L': L++; break;
			case 'C': C++; break;
			case 'D': D++; break;
			case 'M': M++; break;
			}

	ofstream output("preface.out");
	if (I > 0) output << "I " << I << "\n";
	if (V > 0) output << "V " << V << "\n";
	if (X > 0) output << "X " << X << "\n";
	if (L > 0) output << "L " << L << "\n";
	if (C > 0) output << "C " << C << "\n";
	if (D > 0) output << "D " << D << "\n";
	if (M > 0) output << "M " << M << "\n";
	output.close();
}
