#include <fstream>

int N;
int demand[1000 + 1]; //one-based array

int main()
{
	std::ifstream input("blist.in");
	input >> N;
	int s, t, b;
	int time;
	for (int i = 0; i < N; i++) {
		input >> s >> t >> b;
		for (time = s; time <= t; time++)
			demand[time] += b;
	}
	input.close();

	int max = 0;
	for (int i = 1; i <= 1000; i++) {
		if (demand[i] > max)
			max = demand[i];
	}

	std::ofstream output("blist.out");
	output << max << std::endl;
	output.close();
}