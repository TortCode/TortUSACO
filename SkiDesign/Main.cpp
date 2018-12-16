/*
ID: teerth.1
PROG: skidesign
LANG: C++
*/
#include <fstream>
#include <algorithm>
#include <cmath>

int N;

struct Hill {

	int orig, height, change;
	void reset()
	{
		height = orig;
		change = 0;
	}
	void increaseHeight(int increase)
	{
		change += increase;
		height = orig + change;
	}
} skiCourse[1000];

inline void sortHills() {
	std::sort(skiCourse, skiCourse + N, [](Hill a, Hill b) { return a.height < b.height; });
}

void approximateLevel(const int& average) {
	for (int i = 0; i < N; i++) {
		int h = skiCourse[i].height;
		if (abs(h - average) > 9) {
			int diff = (h > average) ? average - h + 9 : average - h - 9;
			skiCourse[i].increaseHeight(diff);
		}
	}
	sortHills();
}

int main()
{
	std::ifstream input("skidesign.in");
	input >> N;
	double sum = 0;
	for (int i = 0; i < N; i++) {
		input >> skiCourse[i].orig;
		skiCourse[i].reset();
	}
	input.close();

	sortHills();
	int lowest = skiCourse[0].orig;
	int highest = skiCourse[N - 1].orig;
	int minCost = -1, cost;

	for (int test = lowest; test <= highest; test++) {
		for (int i = 0; i < N; i++) {
			skiCourse[i].reset();
		}
		approximateLevel(test); //make all hills within 9 of test

		int priceBias(0); //negative means raising from below is better; positive means cutting from above is better
		for (int i = 0; i < N; i++) {
			if (skiCourse[i].height == (test + 9))
				priceBias += skiCourse[i].change * 2 - 1;
			if (skiCourse[i].height == (test - 9))
				priceBias += skiCourse[i].change * 2 + 1;
		}
		if (priceBias > 0) {
			for (int i = 0; i < N; i++)
				if (skiCourse[i].height == (test + 9))
					skiCourse[i].increaseHeight(-1);
		}
		else {
			for (int i = 0; i < N; i++)
				if (skiCourse[i].height == (test - 9))
					skiCourse[i].increaseHeight(1);
		}

		cost = 0;
		for (int i = 0; i < N; i++) {
			cost += skiCourse[i].change * skiCourse[i].change;
		}
		if (minCost == -1) minCost = cost;
		if (cost < minCost)
			minCost = cost;
	}
	std::ofstream output("skidesign.out");
	output << minCost << std::endl;
	output.close();
}