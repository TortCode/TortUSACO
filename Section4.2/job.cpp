/*
ID: teerth.1
PROG: job
LANG: C++
*/
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
using pii = pair<int, int>;

int njobs;
int MA, MB;
//(what time an additional op will finish, of op start)
vector<int> atype;
vector<int> btype;
// optimal times
vector<int> atimes, btimes;

void process(vector<int>& out, vector<int>& runt)
{
	vector<int> ready(runt.size(), 0);
	for (int job = 0; job < njobs; job++)
	{
		int mach = 0;
		int start;
		int minend = -1;
		for (int i = 0; i < runt.size(); i++)
		{
			int e = ready[i] + runt[i];
			if (minend == -1 || e < minend)
			{
				mach = i;
				minend = e;
			}
		}
		ready[mach] = minend;
		out.push_back(minend);
	}
}

int main()
{
	ifstream input("job.in");
	input >> njobs >> MA >> MB;
	int t;
	for (int i = 0; i < MA; i++)
	{
		input >> t;
		atype.push_back(t);
	}
	for (int i = 0; i < MB; i++)
	{
		input >> t;
		btype.push_back(t);
	}
	input.close();

	process(atimes, atype);
	process(btimes, btype);
	reverse(btimes.begin(), btimes.end());
	int mina = atimes[njobs-1];
	int minb = 0;

	for (int i = 0; i < njobs; i++)
	{
		if (atimes[i] + btimes[i] > minb)
			minb = atimes[i] + btimes[i];
	}

	ofstream output("job.out");
	output << mina << ' ' << minb << endl;
	output.close();
}