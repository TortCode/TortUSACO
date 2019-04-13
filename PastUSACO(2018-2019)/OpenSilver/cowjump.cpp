#include <fstream>
#include <utility>
#include <algorithm>
#define MAXN 100000
using namespace std;
struct Point {
	int x, y;
};
typedef pair<Point, Point> Line;

int cross_orient(Point orig, Point a, Point b)
{
	int prod = (b.y - orig.y)*(a.x - orig.x) - (b.x - orig.x)*(a.y - orig.y);
	if (prod == 0) return 0;
	if (prod > 0) return 1;
	return -1;
}
bool onSeg(Point a, Point b, Point mid)
{
	return (mid.x >= min(a.x, b.x)) &&
		(mid.x <= max(a.x, b.x)) &&
		(mid.y <= max(a.y, b.y)) &&
		(mid.y >= min(a.y, b.y));
}
bool isIntersect(Line a, Line b)
{
	int or1 = cross_orient(a.first, a.second, b.first);
	int or2 = cross_orient(a.first, a.second, b.second);
	int or3 = cross_orient(b.first, b.second, a.first);
	int or4 = cross_orient(b.first, b.second, a.second);
	if ((or1 != or2) && (or3 != or4)) return true;
	if (or1 == 0 && onSeg(a.first, a.second, b.first)) return true;
	if (or2 == 0 && onSeg(a.first, a.second, b.second)) return true;
	if (or3 == 0 && onSeg(b.first, b.second, a.first)) return true;
	if (or4 == 0 && onSeg(b.first, b.second, a.second)) return true;
	return false;
}
Line hurdles[MAXN];
int nIntersect[MAXN];
int main()
{
	int n;
	ifstream input("cowjump.in");
	ofstream output("cowjump.out");
	input >> n;
	int x1, y1, x2, y2;
	for (int i = 0; i < n; i++) {
		input >> x1 >> y1 >> x2 >> y2;
		hurdles[i] = Line({ x1,y1 }, { x2,y2 });
	}
	input.close();
	int earliest = -1;
	int i;
	for (i = 0; i < n; i++) {
		if (nIntersect[i] > 1) break;
		for (int j = i + 1; j < n; j++) {
			if (isIntersect(hurdles[i], hurdles[j])) {
				nIntersect[i]++;
				nIntersect[j]++;
			}
		}
		if (nIntersect[i] > 0 && earliest == -1) earliest = i;
		if (nIntersect[i] > 1) break;
	}
	if (i != n)
		output << i + 1 << '\n';
	else
		output << earliest + 1 << '\n';
	output.close();
}