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
struct Sequence {int freq, length, value;};
string toBinaryString(Sequence s) {
	int x = s.value;
	string ret;
	for (int i = 0; i < s.length; i++)
		ret = to_string(x & 1) + ret; x >> 1;
	return ret;
}
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

	vector<Sequence> possible;
	for (i = A - 1; i <= B - 1; i++)
		for (j = 0; j < (1 << 12); j++)
			if (patterns[i][j] > 0)
				possible.push_back({patterns[i][j], i + 1, j });
	sort(possible.begin(), possible.end(), [&](Sequence a, Sequence b) {
		if(a.freq == b.freq) {
			if (a.length == b.length)
				return a.value < b.value;
			return a.length < b.length;
		}
		return a.freq > b.freq;
	});
	if (possible.size() > N)
		possible.resize(N);

	int freq = -1;
	int ct = 0;
	// FINISH OUTPUT RIGHT HERE
	for (Sequence s : possible) {
		// new frequency class
		if (freq != s.freq) {
			if (ct > 0) output << "\n";
			freq = s.freq;
			output << len << "\n";
			ct = 0;
		}
		if (ct == 6) { //line used up
			output << "\n";
			ct = 0;
		} else if (ct > 0) { 
			output << " ";
		}
		output << toBinaryString(s);
		ct++;
	}
	output << "\n";
	return 0;
}
