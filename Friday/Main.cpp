/*
ID: teerth.1
PROG: friday
LANG: C++
*/
#include <fstream>
#include <string>

using namespace std;

enum Month {
	jan = 1,
	feb,
	mar,
	apr,
	may,
	june,
	jul,
	aug,
	sep,
	oct,
	nov,
	decem
};

int main() {
	ifstream input("friday.in");
	ofstream output("friday.out");
	int N;
	input >> N;
	input.close();
	int weekday[7] = { 0 }; //Saturday 0, Sunday 1, Monday 2, Tuesday 3, Wednesday 4, Thursday 5, Friday 6
	int dow = 0; //Jan 13 of 1900 is saturday
	int DiM; //Days in Month

	for (int y = 1900; y < 1900 + N; y++) {
		for (int m = jan; m <= decem; m++) {
			weekday[dow]++; //increment weekday of 13th of this month

			switch (m) {
			case apr: case june: case sep: case nov:
				DiM = 30;
				break;

			case feb:
				DiM = 28;
				if (y % 4 == 0) { //leap year exceptions
					DiM = 29;
					if ((y % 100 == 0) && (y % 400 != 0)) DiM = 28;
				}
				break;
			default:
				DiM = 31;
			}

			dow += DiM; //add DiM and mod 7 to get dayofweek for 13th of next month
			dow %= 7;
		}
	}

	output << weekday[0] << " "
		<< weekday[1] << " "
		<< weekday[2] << " "
		<< weekday[3] << " "
		<< weekday[4] << " "
		<< weekday[5] << " "
		<< weekday[6] << endl;
	output.close();
}
