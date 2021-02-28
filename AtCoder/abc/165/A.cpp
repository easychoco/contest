#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve()
{
	int k, a, b;
	cin >> k>>a>>b;

	for(int i = a; i <= b; ++i)
	{
		if(i % k == 0)
		{
			cout << "OK" << endl;
			return;
		}
	}
	cout << "NG" << endl;
}

int main()
{
	solve();

	return 0;
}