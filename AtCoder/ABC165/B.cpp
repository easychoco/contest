#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve()
{
	unsigned long long x;
	cin >> x;
	long double r = 100;
	int c = 0;
	while(true)
	{
		++c;
		r = (long long)(r) * 1.01;
		if(r >= x)
		{
			cout << c << endl;
			return;
		}
	}
}

int main()
{
	solve();

	return 0;
}