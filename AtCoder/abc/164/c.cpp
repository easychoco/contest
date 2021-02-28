#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

void solve()
{
	int n;
	cin >> n;

	map<string, int> m;
	for(int i = 0; i < n; ++i)
	{
		string s = "";
		cin >> s;
		m[s] = 1;
	}

	cout << m.size() << endl;

}

int main()
{
	solve();

	return 0;
}
