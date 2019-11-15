/*
ID: teerth.1
PROG: msquare
LANG: C++
*/
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

struct Permutation {
	string seq;
	char nums[8] { 1,2,3,4,8,7,6,5 };
	void transA()
	{
		swap_ranges(nums, nums + 4, nums + 4);
		seq += 'A';
	}
	void transB()
	{
		rotate(nums, nums + 4, nums + 3);
		rotate(nums + 4, nums + 8, nums + 7);
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
		int h=0;
		for (int i = 0; i < 8; i++) {
			h <<= 3;
			h += nums[i] - 1;
		}
		return h;
	}
};

Permutation goal;
string lextrans;
bool visited[1 << 24];
bool findSequence(Permutation& p)
{
	int h = p.hash();
	if (visited[h])
		return false;
	visited[h] = true;
	if (p == goal) {
		lextrans = p.seq;
		return true;
	}
	Permutation a = p, b = p, c = p;
	a.transA();
	b.transB();
	c.transC();
	return findSequence(a) || findSequence(b) || findSequence(c);
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
			goal.nums[4*i+j] = nums[i][j];
	Permutation start;
	start.seq = "";
	findSequence(start);

	int w = 0;
	for (char c : lextrans) {
		if (w == 76) {
			w = 0;
			output << '\n';
		}
		output << c;
		w++;
	}
	if (w != 0)
		output << endl;

	return 0;
}