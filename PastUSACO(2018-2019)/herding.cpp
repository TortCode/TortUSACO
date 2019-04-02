#include <fstream>
#include <algorithm>
using namespace std;

int main() //FAILURE DOES NOT WORK
{
	int n;
	int locs[100000];
	ifstream input("herding.in");
	input >> n;
	for (int i = 0; i < n; i++)
		input >> locs[i];
	sort(locs, locs + n);

	int spaces[100000]{ 0 };
	for (int i = 1; i < n; i++)
		spaces[i] = locs[i] - locs[i - 1] - 1 + spaces[i-1];
	int minimum = spaces[n - 1];
	int i = 0;
	for (int start = 0, end = locs[0] + n - 1; end <= locs[n-1]; end = locs[++start] + n - 1) {
		while (locs[i] < end) i++;
		minimum = min(minimum,
			(spaces[i] - locs[i] + end) -
			spaces[start]
		);
	}
	int maximum = max(
		spaces[n-1] - spaces[1],
		spaces[n-2]);

	ofstream output("herding.out");
	output << minimum << "\n";
	output << maximum << "\n";
	output.close();
}