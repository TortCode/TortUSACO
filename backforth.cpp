#include <fstream>
#include <vector>
#include <set>

struct Barn {
	std::vector<int> buckets;
	int tank = 1000;
} barn1, barn2;

std::set<int> possibilities;

void solve(int day)
{
	int size, volume;
	switch (day) {
	case 5:
		possibilities.emplace(barn1.tank);
		break;
	case 3: case 1:
		size = barn1.buckets.size();
		for (int i = 0; i < size; i++) {
			volume = barn1.buckets[i];

			barn1.tank -= volume;
			barn2.tank += volume;
			barn1.buckets.erase(barn1.buckets.begin() + i);
			barn2.buckets.push_back(volume);
			solve(day + 1);

			barn1.tank += volume;
			barn2.tank -= volume;
			barn1.buckets.insert(barn1.buckets.begin() + i, volume);
			barn2.buckets.pop_back();
		}
		break;
	case 4: case 2:
		size = barn2.buckets.size();
		for (int i = 0; i < size; i++) {
			volume = barn2.buckets[i];

			barn2.tank -= volume;
			barn1.tank += volume;
			barn2.buckets.erase(barn2.buckets.begin() + i);
			barn1.buckets.push_back(volume);
			solve(day + 1);

			barn2.tank += volume;
			barn1.tank -= volume;
			barn2.buckets.insert(barn2.buckets.begin() + i, volume);
			barn1.buckets.pop_back();
		}
		break;
	}
}

int main()
{
	std::ifstream input("backforth.in");
	int size;
	for (int i = 0; i < 10; i++) {
		input >> size;
		barn1.buckets.push_back(size);
	}
	for (int i = 0; i < 10; i++) {
		input >> size;
		barn2.buckets.push_back(size);
	}

	solve(1);

	std::ofstream output("backforth.out");
	output << possibilities.size() << std::endl;
	output.close();
}