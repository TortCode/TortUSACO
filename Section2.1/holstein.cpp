/*
ID: teerth.1
PROG: holstein
LANG: C++
*/
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
int V, G;
queue<vector<int>> qScoops;
struct Vitamins {
	int _arr[1000];
	void initZero()
	{
		for (int i = 0; i < V; i++) _arr[i] = 0;
	}
	int& operator[](int i) { return _arr[i]; }
	Vitamins& operator+=(Vitamins &r)
	{
		for (int i = 0; i < V; i++) _arr[i] += r[i];
		return *this;
	}
	bool operator>=(Vitamins &r)
	{
		for (int i = 0; i < V; i++)
			if (_arr[i] < r[i]) return false;
		return true;
	}
} minreq, feeds[15];
void process(vector<int> &combination) //enqueue next possibilities
{
	int last = combination.size(); //size before new elem
	combination.push_back(0);
	for (int n = combination[last - 1] + 1; n < G; n++) {
		combination[last] = n;
		qScoops.push(combination);
	}
}
vector<int> solve()
{
	for (int n = 0; n < G; n++) qScoops.push({ n }); //initial possibilities
	vector<int> combos;
	Vitamins v;
	while (!qScoops.empty()) {
		v.initZero();
		combos = qScoops.front(); qScoops.pop();
		for (int n : combos) v += feeds[n];
		if (v >= minreq) return combos;
		else process(combos);
	}
	return{ -1 }; //FAIL
}
int main()
{
	ifstream input("holstein.in");
	input >> V;
	for (int i = 0; i < V; i++) input >> minreq[i];
	input >> G;
	for (int i = 0; i < G; i++) for (int j = 0; j < V; j++) input >> feeds[i][j];
	input.close();

	vector<int> ans = solve();
	ofstream output("holstein.out");
	output << ans.size();
	for (int n : ans) output << " " << n + 1;
	output << "\n";
	output.close();
}
