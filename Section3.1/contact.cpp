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

struct Sequence { 
	int freq, length, value;
};

string toBinaryString(Sequence s) {
	int x = s.value;
	string ret;
	for (int i = 0; i < s.length; i++) {
		ret = to_string(x % 2) + ret; 
		x /= 2;
	}
	return ret;
}

int main()
{
	ifstream input("contact.in");
	ofstream output("contact.out");
	input >> A >> B >> N;
	string s, temp;
	while (getline(input, temp))
		s += temp;
	reverse(s.begin(), s.end());
	bitset<200'000> emission(s);

	int i, j;
	for (i = 0; i < s.size(); i++) {
		int sum = 0;
		for (j = 0; j < B && (i + j < s.size()); j++) {
			sum *= 2;
			sum += emission[i + j];
			patterns[j][sum]++;
		}
	}
	
	vector<Sequence> possible;
	for (i = A - 1; i <= B - 1; i++)
		for (j = 0; j < (1 << 12); j++)
			if (patterns[i][j] > 0)
				possible.push_back({ patterns[i][j], i + 1, j });
	sort(possible.begin(), possible.end(), [](Sequence a, Sequence b) {
		if (a.freq == b.freq) {
			if (a.length == b.length)
				return a.value < b.value;
			return a.length < b.length;
		}
		return a.freq > b.freq;
	});

	// group by frequency
	int frequency = -1;
	int classindex = -1;
	vector<vector<Sequence>> classes;
	for (Sequence seq : possible) {
		if (frequency != seq.freq) {
			classes.push_back(vector<Sequence>());
			frequency = seq.freq;
			classindex++;
		}
		classes[classindex].push_back(seq);
	}
	if (classes.size() > N)
		classes.resize(N);
	
	// all that grubby output
	for (vector<Sequence> freqClass : classes) {
		output << freqClass[0].freq << "\n";
		int ct = 0;
		for (Sequence seq : freqClass) {
			if (ct == 6) { //line used up
				output << "\n";
				ct = 0;
			}
			else if (ct > 0) { //another seq precedes
				output << " ";
			}
			output << toBinaryString(seq);
			ct++;
		}
		if (ct != 0)
			output << "\n";
	}
}
