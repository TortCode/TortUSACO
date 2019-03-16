/*
ID: teerth.1
PROG: runround
LANG: C++
*/
#include <fstream>
#include <string>
#define CTN(c) (c-'0')
using namespace std;

int main()
{
	int M;
	ifstream input("runround.in");
	ofstream output("runround.out");
	input >> M;
	input.close();

	while (true) {
		NEXT:
		bool contains_digit[10]{ false };
		bool visited[10]{ false };
		string num = to_string(++M);
		int len = num.length();
		//check unique
		for (char c : num) {
			if (contains_digit[CTN(c)])
				goto NEXT;
			contains_digit[CTN(c)] = true;
		}
		//check no zero
		if (contains_digit[0]) goto NEXT;
		int i;
		for (i = 0; !visited[i]; i = (i + CTN(num[i])) % len) visited[i] = true;
		//should not repeat until start
		if (i != 0) goto NEXT;
		//should visit all characters
		for (i = 0; i < len; i++)
			if (!visited[i]) goto NEXT;
		//we're good
		break;
	}

	output << M << '\n';
	output.close();
}