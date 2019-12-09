/*
ID: teerth.1
PROG: shopping
LANG: C++
*/
#include <fstream>
#include <vector>
#include <utility>

// 0 to 5 for each item
constexpr int MAXCOMBOCODE = 6 * 6 * 6 * 6 * 6;
int minPrice[MAXCOMBOCODE];
// from code to index in minprice
int index[1000];
int sixpow[]{ 1,6,36,36 * 6,36 * 36 };
int noffers, nbuys;

// code, no of items
using Item = std::pair<int, int>;
struct Offer {
	std::vector<Item> items;
	int price;
	int encode()
	{
		int n;
		for (Item it : items)
			n += sixpow[index[it.first]] * it.second;
		return n;
	}
} offers[99];

struct Purchase {
	int code;
	int nitem;
	int price;
} purchases[5];



void dp()
{
	for (int i = 0; i < noffers; ++i) {
		int code = offers[i].encode();
		int p = offers[i].price;
		for (int j = MAXCOMBOCODE - 1; j >= 0; --j) {

		}
	}
}

int main()
{
	std::ifstream input("shopping.in");
	std::ofstream output("shopping.out");
	input >> noffers;
	int n, c, k, p;
	for (int i = 0; i < noffers; ++i) {
		input >> n;
		for (int j = 0; j < n; ++j) {
			input >> c >> k;
			offers[i].items.push_back(Item(c, k));
		}
		input >> offers[n].price;
	}
	input >> nbuys;
	for (int i = 0; i < nbuys; ++i) {
		input >> c >> k >> p;
		purchases[i] = { c, k, p };
		index[c] = i;
	}

	dp();

	output << minPrice[0] << std::endl;
}