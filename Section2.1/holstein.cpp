/*
ID: teerth.1
PROG: holstein
LANG: C++
*/
#include <fstream>

using namespace std;

int V, vitamin[1000];
int G, feed[15][1000];

int main()
{
	ifstream input("holstein.in");
	ofstream output("holstein.out");
	input >> V;
	for (int i = 0; i < V; i++)
		input >> vitamin[i];
	input >> G;
	for (int i = 0; i < G; i++)
		for (int j = 0; j < V; j++)
			input >> feed[i][j];
	input.close();
}