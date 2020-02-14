/*
ID: teerth.1
PROG: heritage
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

void postOrder(ofstream& out, string pre, string in)
{
	if (in.length() == 0) return;
	char root = pre[0];
	int pos = in.find(root);
	// left subtree
	postOrder(out, pre.substr(1, pos), in.substr(0, pos));
	// right substree
	postOrder(out, pre.substr(pos + 1), in.substr(pos + 1));
	out << root;
}

int main()
{
	ifstream input("heritage.in");
	ofstream output("heritage.out");
	string inorder, preorder;
	input >> inorder >> preorder;

	postOrder(output, preorder, inorder);
	output << endl;
}