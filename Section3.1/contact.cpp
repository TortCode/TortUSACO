/*
ID: teerth.1
PROG: contact
LANG: C++
*/
#include <fstream>
#include <bitset>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int A, B, N;
int patterns[12][1 << 12]; // (length - 1), sequence value

int main()
{
	ifstream input("contact.in");
	ofstream output("contact.out");
	input >> A >> B >> N;
	string seq, s;
	while (!input.eof()) {
		input >> s;
		seq += s;
	}
	int size = seq.size;
	bitset<200'000> emission(seq);

	int i, j;

	for (i = 0; i < size; i++) {
		int sum = 0;
		for (j = 0; j < B; j++) {
			sum << 1;
			sum += emission[i+j];
			patterns[j][sum]++;
		}
	}

	struct Sequence {
		int length, value;
	};
	vector<Sequence> possible;
	for (i = A - 1; i <= B - 1; i++)
		for (j = 0; j < (1 << 12); j++)
			if (patterns[i][j] > 0)
				possible.push_back({ i + 1,patterns[i][j] });
	sort(possible.begin(), possible.end(), [](Sequence a, Sequence b) {
		a.value > b.value;
	});


	return 0;
}
