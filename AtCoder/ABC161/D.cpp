#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

const int POOL_SIZE = 11;

ll k;
int digit = 0;

ll nextLunlun(ll num)
{
	// num は lunlun の前提
	if ((int)log10(num) < (int)log10(num + 1))
	{
		return num + 1;
	}

	int a = num % 10;
	num /= 10;
	int b = num % 10;

	int loop_cnt = 0;
	while(num)
	{
		if (a - b < 1 && a * b != 81)
		{
			break;
		}

		a = b;
		num /= 10;
		b = num % 10;		
		loop_cnt++;
	}

	num = num * 10 + a + 1;
	for(int i = 0; i < loop_cnt; ++i)
	{
		num = num * 10 + a;
		a = max(0, a - 1);
	}
	return num;
}

void solve()
{
	cin >> k;
	//cout << nextLunlun(k) << endl;
	//return;

	ll cnt = 1;
	ll i = 1;
	
	while(i <= 3234566667)
	{
		if (cnt == k)
		{
			cout << i << endl;
			return;
		}
		i = nextLunlun(i);
		++cnt;
	}
}




void solve2()
{
	cin >> k;
	deque<ll> q;

	for(int i = 1; i <= 9; ++i)
	{
		q.push_back(i);
	}

	int cnt = 0;
	ll n = 0;
	while(cnt++ < k)
	{
		n = q.front();
		q.pop_front();

		if(n % 10 != 0)
		{
			q.push_back(n * 10 + n % 10 - 1);						
		}

		q.push_back(n * 10 + n % 10);

		if(n % 10 != 9)
		{
			q.push_back(n * 10 + n % 10 + 1);
		}
	}
	cout << n << endl;
}




int main()
{
	fastio;
	solve2();

	return 0;
}