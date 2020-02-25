/*
ID: teerth.1
PROG: rockers
LANG: C++
*/
#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

constexpr auto MAXSONG = 20;
constexpr auto MAXDISK = 20;
constexpr auto MAXCAP = 20;

int nsong, ndisk, cap;
bitset<1 << 20> visited;
vector<int> songs;

int doesFit(int deleted)
{
	int disks = 1;
	int used = 0;
	int size = 0;
	for (int i = 0; i < songs.size(); ++i)
	{
		if (deleted & (1 << i)) continue;
		if (used + songs[i] <= cap)
			used += songs[i];
		else {
			used = songs[i];
			++disks;
		}
		++size;
	}
	return (disks <= ndisk)? size : 0;
}

int main()
{

	ifstream input("rockers.in");
	ofstream output("rockers.out");
	input >> nsong >> cap >> ndisk;
	for (int i = 0, len; i < nsong; ++i)
	{
		input >> len;
		if (len > cap) continue;
		songs.push_back(len);
	}

	int best = 0;
	const int end = (1 << nsong);
	for (int i = 0; i < end; ++i)
		best = max(best, doesFit(i));

	output << best << endl;

}