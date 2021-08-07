#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve()
{
	double a, b, n;
	cin >> a >> b >> n;

	double x = min(n, b - 1);

	cout << floor(a * x / b) << endl;

}

int main()
{
	solve();

	return 0;
}