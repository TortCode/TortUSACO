/*
ID: teerth.1
PROG: milk
LANG: C++
*/
#include <fstream>
#include <algorithm>
using namespace std;

struct Farmer {
	int price;
	long amount; //of milk that can be supplied
};

int main()
{
	ifstream fin("milk.in");
	ofstream fout("milk.out");

	int N, M; //N is milk needed; M is farmers you can buy from
	fin >> N >> M;

	Farmer supply[5000] = { 0,0 };
	for (int f = 0; f < M; f++) {
		fin >> supply[f].price >> supply[f].amount;
	}
	fin.close();
	sort(supply, supply + M, [](Farmer x, Farmer y) { return x.price < y.price; });

	int unitsNeeded = N;
	int cost = 0;
	for (int i = 0; unitsNeeded != 0; i++) {
		Farmer f = supply[i];
		if (unitsNeeded < f.amount) { //if buying all too much, buy whatever needed
			cost += unitsNeeded * f.price;
			unitsNeeded = 0;
		}
		else { //buy all of farmer's milk
			cost += f.amount * f.price;
			unitsNeeded -= f.amount;
		}
	}

	fout << cost << endl;
	fout.close();
}
