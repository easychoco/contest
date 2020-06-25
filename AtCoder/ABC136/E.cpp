#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);

	ll sum = 0;
	for(ll i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}

	vector<ll> divisor;
	for(int i = 1; i * i <= sum; ++i)
	{
		if (sum % i == 0)
		{
			divisor.emplace_back(sum / i);
			divisor.emplace_back(i);
		}
	}
	ll mid_divisor = divisor.back();
	sort(divisor.begin(),divisor.end(), greater<ll>());


	for(const auto& d : divisor)cout << d << " ";
	cout << endl;



	for(const auto& d : divisor)
	{	
		ll deviation = 0;
		ll sign = 0;
		cout << endl << 0;
		for(int i = 0; i < n; ++i)
		{
			ll mod = a[i] % d;
			deviation += ((mod > d / 2) ? d - mod : mod);

			if (i < n / 2)
			{
				sign += ((mod > d / 2) ? d - mod : -mod);
			}
			else
			{
				sign += ((mod > d / 2) ? mod - d : mod);
			}
			
			cout << " -> " << deviation;
		}
		cout << " : " << deviation << " / " << sign << endl;
		
		if (deviation <= k * 2)
		{
			cout << d;
			return;
		}
	}
	cout << 1;
}

int main()
{
	fastio;
	solve();

	return 0;
}