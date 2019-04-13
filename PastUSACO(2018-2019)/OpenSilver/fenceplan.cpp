#include <fstream>
#include <utility>
#include <vector>
#define MAXN 100000
using namespace std;
struct Point { int x, y; };
struct Network {
	int u, d, l, r;
	Network(int x, int y) : u(y), d(y), l(x), r(x) {}
};
vector<Network> networks;
vector<Point> cows;
vector<int> moonet[MAXN];
bool visited[MAXN];
int regcount = 0;

void search(int cowid, int regid)
{
	visited[cowid] = true;
	if (cows[cowid].x > networks[regid].r) networks[regid].r = cows[cowid].x;
	if (cows[cowid].x < networks[regid].l) networks[regid].l = cows[cowid].x;
	if (cows[cowid].y > networks[regid].u) networks[regid].u = cows[cowid].y;
	if (cows[cowid].y < networks[regid].d) networks[regid].d = cows[cowid].y;
	for (int i : moonet[cowid])
		if (!visited[i])
			search(i, regid);
}

int main()
{
	int N, M;
	ifstream input("fenceplan.in");
	ofstream output("fenceplan.out");
	input >> N >> M;
	for (int i = 0, x, y; i < N; i++) {
		input >> x >> y;
		cows.push_back({ x,y });
	}
	for (int i = 0, a, b; i < M; i++) {
		input >> a >> b;
		moonet[a - 1].push_back(b - 1);
		moonet[b - 1].push_back(a - 1);
	}
	input.close();
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			networks.push_back(Network(cows[i].x, cows[i].y));
			search(i, regcount++);
		}
	}

	int minPerim = 2 * (networks[0].u - networks[0].d + networks[0].r - networks[0].l);
	int perim;
	for (int i = 1; i < networks.size(); i++) {
		perim = 2 * (networks[i].u - networks[i].d + networks[i].r - networks[i].l);
		minPerim = (perim < minPerim) ? perim : minPerim;
	}
	output << minPerim << '\n';
	output.close();
}