#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

int N;

struct Peak {
	int x, y;
} mountains[100000];

inline bool isDistinct(const Peak& lo, const Peak& hi)
{
	return lo.y > (hi.y - abs(lo.x - hi.x));
}

int main()
{
	ifstream input("mountains.in");
	input >> N;
	for (int i = 0; i < N; i++) {
		input >> mountains[i].x >> mountains[i].y;
	}
	sort(mountains, mountains + N, [](Peak a, Peak b) { return a.y < b.y; });

	int count = 0;
	for (int i = 0; i < N; i++) {
		bool allDistinct = true;
		for (int j = i + 1; j < N; j++) {
			if (!isDistinct(mountains[i], mountains[j])){
				allDistinct = false;
				break;
			}
		}
		if (allDistinct)
			count++;
	}

	ofstream output("mountains.out");
	output << count << endl;
}
