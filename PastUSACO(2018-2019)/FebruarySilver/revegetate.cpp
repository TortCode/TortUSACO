#include <fstream>
#include <vector>
#include <bitset>
using namespace std;

bitset<100001> visited;
vector<int> edges[100001];

void searchComponent(int pasture)
{
	if (visited[pasture]) return;
	visited[pasture] = true;
	for (int other : edges[pasture])
		searchComponent(other);
}

int main() //BUG: does not check for the impossible case
{
	int n, m;
	ifstream input("revegetate.in");
	input >> n >> m;
	char sd;
	int field1, field2;
	for (int i = 0; i < m; i++) {
		input >> sd >> field1 >> field2;
		edges[field1].push_back(field2);
		edges[field2].push_back(field1);
	}
	input.close();

	int ncomponent = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			searchComponent(i);
			ncomponent++;
		}
	}

	//output 2^ncompoment in binary
	ofstream output("revegetate.out");
	output << "1";
	while (ncomponent > 0) {
		output << "0";
		ncomponent--;
	}
	output.close();
}
