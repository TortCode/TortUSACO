/*
ID: teerth.1
PROG: lamps
LANG: C++
*/
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct State {
	vector<bool> lamps;
	int ct = 0;
	State(int sz)
	{
		lamps.resize(sz, true);
	}
	State button1()
	{
		State st = *this;
		st.lamps.flip();
		st.ct++;
		return st;
	}
	State button2()
	{
		State st = *this;
		int len = st.lamps.size();
		for (int i = 1; i < len; i += 2) st.lamps[i-1] = !st.lamps[i-1];
		st.ct++;
		return st;
	}
	State button3()
	{
		State st = *this;
		int len = st.lamps.size();
		for (int i = 2; i < len; i += 2) st.lamps[i-1] = !st.lamps[i-1];
		st.ct++;
		return st;
	}
	State button4()
	{
		State st = *this;
		int len = st.lamps.size();
		for (int i = 1; i < len; i += 3) st.lamps[i-1] = !st.lamps[i-1];
		st.ct++;
		return st;
	}
};


int main()
{
	int N, C;
	vector<State> poss;
	vector<int> on, off;
	ifstream input("lamps.in");
	ofstream output("lamps.out");
	input >> N >> C;
	poss.push_back(State(N));
	int loc;
	input >> loc;
	while (loc != -1) {
		on.push_back(loc);
		input >> loc;
	}
	input >> loc;
	while (loc != -1) {
		off.push_back(loc);
		input >> loc;
	}

	for (int i = poss.size() - 1; i >= 0; i--)
		poss.push_back(poss[i].button1());
	for (int i = poss.size() - 1; i >= 0; i--)
		poss.push_back(poss[i].button2());
	for (int i = poss.size() - 1; i >= 0; i--)
		poss.push_back(poss[i].button3());
	for (int i = poss.size() - 1; i >= 0; i--)
		poss.push_back(poss[i].button4());

	for (int i = poss.size() - 1; i >= 0; i--) {
		bool remove = false;
		if (poss[i].ct % 2 != C % 2)
			remove = true;
		if (poss[i].ct > C)
			remove = true;
		for (int pos : on)
			if (!(poss[i].lamps[pos-1])) remove = true;
		for (int pos : off)
			if (poss[i].lamps[pos-1]) remove = true;
		if (remove)
			poss.erase(poss.begin() + i);
	}
	for (int i = poss.size() - 1; i >= 0; i--)
		for (int j = i - 1; j >= 0; j--)
			if (poss[i].lamps == poss[j].lamps)
				poss.erase(poss.begin() + j);

	sort(poss.begin(), poss.end(), [](State lhs, State rhs) {return lhs.lamps < rhs.lamps;});
	for (State st : poss) {
		for (bool b : st.lamps)
			output << b;
		output << '\n';
	}
	if (poss.size() == 0)
		output << "IMPOSSIBLE" << '\n';
	output.close();
}