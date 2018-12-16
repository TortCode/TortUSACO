/*
ID: teerth.1
PROG: skidesign
LANG: C++
*/
#include <fstream>
#include <algorithm>
#include <cmath>

int N;
Hill skiCourse[1000];

inline void sortHills() {
	std::sort(skiCourse, skiCourse + N, [](Hill a, Hill b) {a.height < b.height; });
}

struct Hill {
	
	int height, change = 0;

	void decreaseHeight(int decrease) {
		height -= decrease;
		change -= decrease;
	}
};
int main()
{
	std::ifstream input("skidesign.in");
	input >> N;
	for (int i = 0; i < N; i++) {
		input >> skiCourse[i].height;
	}
	input.close();
	
	sortHills();
	double median;
	median = (N % 2 == 1) ? skiCourse[N / 2].height : (skiCourse[N / 2 - 1].height + skiCourse[N / 2].height) / 2.0;

	for (int i = 0; i < N; i++) {
		int h = skiCourse[i].height;
		if (abs(h - median) > 17) {
			int diff = (h > median) ? h - median + 8 : median - h - 8;
			skiCourse[i].changeHeight(-diff);
		}
	}
	sortHills();
	while (skiCourse[N - 1].height - skiCourse[0].height > 17) {
	}
}
