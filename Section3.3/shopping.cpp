/*
ID: teerth.1
PROG: shopping
LANG: C++
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

int noffers, nbuys, six_to_nbuys;

struct Offer {
	int items[5]{};
	int price;
};
std::vector<Offer> offers;
// product code map-> 1-5
int index[1000];
int count = 0;
int purchase[5];

int minprice[6][6][6][6][6];
inline bool isValid(int a, int b, int c, int d, int e)
{
	return a <= 5
		&& b <= 5
		&& c <= 5
		&& d <= 5
		&& e <= 5;
}

void dp()
{
	int a, b, c, d, e;
	int na, nb, nc, nd, ne;
	for (Offer o : offers) {
		for (int i = 0, j; i < six_to_nbuys; ++i) {
			j = i;
			a = j % 6; j /= 6;
			b = j % 6; j /= 6;
			c = j % 6; j /= 6;
			d = j % 6; j /= 6;
			e = j % 6; j /= 6;
			na = a + o.items[0];
			nb = b + o.items[1];
			nc = c + o.items[2];
			nd = d + o.items[3];
			ne = e + o.items[4];
			if (isValid(na, nb, nc, nd, ne) && minprice[a][b][c][d][e] + o.price < minprice[na][nb][nc][nd][ne])
				minprice[na][nb][nc][nd][ne] = minprice[a][b][c][d][e] + o.price;
		}
	}

}
int main()
{
	std::ifstream input("shopping.in");
	std::ofstream output("shopping.out");

	input >> noffers;
	int n, c, k, p;
	// the count of index is assigned in order of scanning product code
	std::fill(index, index + 1000, -1);
	for (int i = 0; i < noffers; ++i) {
		input >> n;
		Offer o;
		for (int j = 0; j < n; ++j) {
			input >> c >> k;
			if (index[c] == -1) {
				index[c] = count; ++count;
			}
			o.items[index[c]] = k;
		}
		input >> o.price;
		offers.push_back(o);
	}
	input >> nbuys;
	for (int i = 0; i < nbuys; ++i) {
		input >> c >> k >> p;
		if (index[c] == -1) {
			index[c] = count; ++count;
		}
		purchase[index[c]] = k;
		Offer o;
		// price p for given 1 item
		o.items[index[c]] = 1;
		o.price = p;
		offers.push_back(o);
	}

	six_to_nbuys = (int)std::pow(6, nbuys);
	for (int i = 0, j,a,b,c,d,e; i < six_to_nbuys; ++i) {
		j = i;
		a = j % 6; j /= 6;
		b = j % 6; j /= 6;
		c = j % 6; j /= 6;
		d = j % 6; j /= 6;
		e = j % 6; j /= 6;
		minprice[a][b][c][d][e] = 999 * 25;
	}
	minprice[0][0][0][0][0] = 0;

	dp();

	output << minprice[purchase[0]][purchase[1]][purchase[2]][purchase[3]][purchase[4]] << std::endl;
}