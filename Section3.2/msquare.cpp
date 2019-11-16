/*
ID: teerth.1
PROG: msquare
LANG: C++
*/
#include<fstream>
#include<string>
#include<algorithm>
#include<bitset>
#include<queue>
using namespace std;

struct Permutation {
	string seq;
	char nums[8]{ 1,2,3,4,8,7,6,5 };
	void transA()
	{
		swap_ranges(nums, nums + 4, nums + 4);
		seq += 'A';
	}
	void transB()
	{
		rotate(nums, nums + 3, nums + 4);
		rotate(nums + 4, nums + 7, nums + 8);
		seq += 'B';
	}
	void transC()
	{
		char tmp = nums[5];
		nums[5] = nums[6];
		nums[6] = nums[2];
		nums[2] = nums[1];
		nums[1] = tmp;
		seq += 'C';
	}
	bool operator==(Permutation& rhs)
	{
		return equal(nums, nums + 8, rhs.nums);
	}
	int hash()
	{
		int h = 0;
		for (int i = 0; i < 8; i++) {
			h <<= 3;
			h += nums[i] - 1;
		}
		return h;
	}
};

Permutation goal;
queue<Permutation> q;
string lextrans;
bitset<1 << 24> visited;
void findSequence(Permutation start)
{
	q.push(start);
	while (!q.empty()) {
		Permutation p = q.front();
		q.pop();
		int h = p.hash();
		if (visited[h])
			continue;
		visited[h] = true;
		if (p == goal) {
			lextrans = p.seq;
			return;
		}
		Permutation a = p, b = p, c = p;
		a.transA();
		b.transB();
		c.transC();
		q.push(a);
		q.push(b);
		q.push(c);
	}
}

int main()
{
	ifstream input("msquare.in");
	ofstream output("msquare.out");
	int nums[2][4];
	input >> nums[0][0] >> nums[0][1] >> nums[0][2] >> nums[0][3]
		>> nums[1][3] >> nums[1][2] >> nums[1][1] >> nums[1][0];

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
			goal.nums[4 * i + j] = nums[i][j];
	Permutation start;
	start.seq = "";
	findSequence(start);

	output << lextrans.size() << endl;
	int w = 0;
	for (char c : lextrans) {
		if (w == 76) {
			w = 0;
			output << '\n';
		}
		output << c;
		w++;
	}
	output << endl;
}