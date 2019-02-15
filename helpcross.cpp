#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
	struct Cow {
		int start;
		int fin;
	} cows[20000];
	int chickens[20000]{ 0 };
	int C, N; //chickens, cows

	ifstream input("helpcross.in");
	input >> C >> N;
	for (int i = 0; i < C; i++) {
		input >> chickens[i];
	}
	for (int i = 0; i < N; i++) {
		input >> cows[i].start;
		input >> cows[i].fin;
	}
	input.close();

	sort(chickens, chickens + C);
	sort(cows, cows + N, [](Cow l, Cow r) {
		if (l.start < r.start)
			return true;
		if (l.start == r.start)
			return l.fin < r.fin;
		return false;
	});

	int pairs = 0;
	int cik = 0;
	for (int i = 0; i < N; i++) {
		if (cik >= C) break;
		while (chickens[cik] < cows[i].start) cik++;
		if (cik < C && chickens[cik] <= cows[i].fin) {
			cik++;
			pairs++;
		}
	}

	ofstream output("helpcross.out");
	output << pairs << "\n";
	output.close();
}
