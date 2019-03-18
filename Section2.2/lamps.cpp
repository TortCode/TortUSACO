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
		lamps.resize(sz + 1);
		for (bool b : lamps) b = 1;
	}
};

State& button1(State st)
{
	st.lamps.flip();
	st.ct++;
	return st;
}
State& button2(State st)
{
	int len = st.lamps.size();
	for (int i = 1; i < len; i += 2) st.lamps[i] = !st.lamps[i];
	st.ct++;
	return st;
}
State& button3(State st)
{
	int len = st.lamps.size();
	for (int i = 2; i < len; i += 2) st.lamps[i] = !st.lamps[i];
	st.ct++;
	return st;
}
State& button4(State st)
{
	int len = st.lamps.size();
	for (int i = 1; i < len; i += 3) st.lamps[i] = !st.lamps[i];
	st.ct++;
	return st;
}

int main()
{
	int N, C;
	vector<State> poss;
	vector<int> on, off;
	ifstream input("lamps.in");
	ofstream output("lamps.out");
	input >> N >> C;
	poss.push_back(State(N));
	for (int i; i != -1; input >> i) on.push_back(i);
	for (int i; i != -1; input >> i) off.push_back(i);

	for (State st : poss) poss.push_back(button1(st));
	for (State st : poss) poss.push_back(button2(st));
	for (State st : poss) poss.push_back(button3(st));
	for (State st : poss) poss.push_back(button4(st));
	
	for (int i = poss.size() - 1; i >= 0; i--) {
		bool remove = false;
		if (poss[i].ct % 2 != C % 2)
			remove = true;
		if (poss[i].ct > C)
			remove = true;
		for (int pos : on)
			if (!poss[i].lamps[pos]) remove = true;
		for (int pos : off)
			if (poss[i].lamps[pos]) remove = true;
		if (remove)
			poss.erase(poss.begin() + i);
	}

	sort(poss.begin(), poss.end(), [&](State lhs, State rhs) {

	});
}