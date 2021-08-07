#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

// 素数判定
bool isPrime(int a)
{
    if (a == 1) return false;
    for (int i = 2; i * i <= a; i++)
	{
        if(a % i == 0) return false;
    }
    return true;
}

void solve()
{
	int x;
	cin >> x;
	for(int i = x; i < 2 * x; ++i)
	{
		if(isPrime(i))
		{
			cout << i;
			return;
		}
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}