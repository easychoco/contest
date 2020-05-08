#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve()
{
	int S, W;
	cin >> S >> W;
	cout << (S <= W ? "unsafe" : "safe") << endl;
}

int main()
{
	solve();

	return 0;
}