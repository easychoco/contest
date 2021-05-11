#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve()
{
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	while(A * C > 0)
	{
		C -= B;
		if (C <= 0)
		{
			cout << "Yes" << endl;
			return;
		}

		A -= D;
		if (A <= 0)
		{
			cout << "No" << endl;
			return;
		}
	}
}

int main()
{
	solve();

	return 0;
}