// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_C&lang=ja
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <list>

using namespace std;

#define PI 3.14159265358979

class Coord
{
public:
	Coord(double _x, double _y) : x(_x), y(_y)
	{
	}

	void println() const
	{
		printf("%.8f %.8f\n", x, y);
		// cout << setprecision(8) << x << " " << setprecision(8) << y << endl;
	}

	const double x;
	const double y;
};

list<Coord> coords;

void solve(const Coord start, const Coord dest, list<Coord>::iterator &c)
{
	static const double sq3 = sqrt(3.0);
	double vec_x = (dest.x - start.x);
	double vec_y = (dest.y - start.y);

	double x1 = (start.x * 2.0 + dest.x) / 3.0;
	double y1 = (start.y * 2.0 + dest.y) / 3.0;

	double x2 = start.x + (3.0 * vec_x - sq3 * vec_y) / 6.0;
	double y2 = start.y + (sq3 * vec_x + 3.0 * vec_y) / 6.0;

	double x3 = (start.x + dest.x * 2.0) / 3.0;
	double y3 = (start.y + dest.y * 2.0) / 3.0;
	
	coords.insert(c, Coord(x1, y1));
	coords.insert(c, Coord(x2, y2));
	coords.insert(c, Coord(x3, y3));
}

int main()
{
	coords.push_back(Coord(0.0, 0.0));
	coords.push_back(Coord(100.0, 0.0));
	
	int n = 0;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		auto c = coords.begin();
		while(next(c) != coords.end())
		{
			Coord start = *c;
			c++;
			Coord dest = *c;
			solve(start, dest, c);
		}
	}

	for_each(coords.begin(), coords.end(), [](Coord& c) { c.println(); });

	return 0;
}