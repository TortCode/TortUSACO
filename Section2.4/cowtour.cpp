/*
ID: teerth.1
PROG: cowtour
LANG: C++
*/
// ok it works now
// but its full of ugly vectors
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
int N;
struct Point {
	int x, y;
} vertex[150];
double dist[150][150];

double distance(Point a, Point b)
{
	int dx = a.x - b.x;
	int dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

int main()
{
	ifstream input("cowtour.in");
	ofstream output("cowtour.out");
	int i, j, k, l;
	input >> N;
	for (i = 0; i < N; i++)
		input >> vertex[i].x >> vertex[i].y;
	string str;
	for (i = 0; i < N; i++) {
		dist[i][i] = 0;
		input >> str;
		for (j = 0; j < i; j++) {
			if (str[j] == '1') dist[i][j] = distance(vertex[i], vertex[j]);
			else dist[i][j] = INFINITY;
			dist[j][i] = dist[i][j];
		}
	}
	// Floyd-Warshall
	for (k = 0; k < N; k++) for (i = 0; i < N; i++) for (j = 0; j < i; j++)
		if (dist[i][k] + dist[k][j] < dist[i][j])
			dist[i][j] = dist[j][i] = dist[i][k] + dist[k][j];

	vector<vector<int>> components;
	int cmp = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < components.size(); j++) {
			if (dist[components[j][0]][i] < INFINITY) {
				components[j].push_back(i);
				break;
			}
		}
		if (j == components.size())
			components.push_back({ i });
	}
	int CMPSZ = components.size();
	// Let  maxDist be farthest dist from point to all others in component
	vector<vector<double>> maxDist;
	for (i = 0; i < CMPSZ; i++)
		maxDist.push_back(vector<double>(components[i].size()));
	double max;
	double greatCis = 0;
	int sz1, sz2;
	for (k = 0; k < CMPSZ; k++) {
		vector<int> &v = components[k];
		sz1 = v.size();
		for (i = 0; i < sz1; i++) {
			max = 0;
			for (j = 0; j < sz1; j++)
				max = fmax(max, dist[v[i]][v[j]]);
			maxDist[k][i] = max;
			greatCis = fmax(greatCis, max);
		}

	}
	// Least diameter = min(maxDistA[i] + pathLength[i][j] + maxDistB[j])
	double min = INFINITY;
	for (i = 1; i < CMPSZ; i++) {
		sz1 = components[i].size();
		for (k = 0; k < i; k++) {
			sz2 = components[k].size();
			for (j = 0; j < sz1; j++) for (l = 0; l < sz2; l++)
				min = fmin(min, maxDist[i][j] + distance(vertex[components[i][j]], vertex[components[k][l]]) + maxDist[k][l]);
		}
	}
	output << fixed;
	output << setprecision(6);
	output << fmax(greatCis,min) << '\n';
}
