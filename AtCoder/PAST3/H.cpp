#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7
#define ALL(a) a.begin(),a.end()

using namespace std;
using ll = long long;
const int INF = 1000000007;


void solve()
{
	ll n, l;
	cin >> n >> l;
	vector<ll> hurdle(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> hurdle[i];
	}

	ll t1, t2, t3;	
	cin >> t1 >> t2 >> t3;

	vector<ll> pos(l + 6, INF);
  pos[0] = 0;
  for(int i = 0; i < l; ++i)
  {
    ll time_run = pos[i] + t1;
    if (*lower_bound(ALL(hurdle), i + 1) == i + 1) time_run += t3;
    pos[i + 1] = min(pos[i + 1], time_run);
    
    time_run = pos[i] + t1 + t2;
    if (*lower_bound(ALL(hurdle), i + 2) == i + 2) time_run += t3;
    pos[i + 2] = min(pos[i + 2], time_run);

    time_run = pos[i] + t1 + t2 * 3;
    if (*lower_bound(ALL(hurdle), i + 4) == i + 4) time_run += t3;
    pos[i + 4] = min(pos[i + 4], time_run);
  }

  // i = l-3
  ll time_l3 = pos[l - 3] + (t1 + t2) / 2 + t2 * 2;
  pos[l] = min(pos[l], time_l3);
  // i = l-2
  ll time_l2 = pos[l - 2] + (t1 + t2) / 2 + t2;
  pos[l] = min(pos[l], time_l2);
  // i = l-1
  ll time_l1 = pos[l - 1] + (t1 + t2) / 2;
  pos[l] = min(pos[l], time_l1);

	cout << pos[l];
}

int main()
{
	fastio;
	solve();

	return 0;
}