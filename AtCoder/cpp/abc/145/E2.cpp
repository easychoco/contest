#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i = a;i < (ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SHOW(str,val) cout<<(str)<<" : "<<(val)<<endl;

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}

void solve()
{
	int n, t;
  cin >> n >> t;
  vector<P> food(n);
  rep(i, n) cin >> food[i].first >> food[i].second;
  sort(ALL(food));
  vector<ll> dp(6010, 0);
  rep(i, n) for(int j = t - 1; j >= 0; --j)
  {
    ll a = food[i].first;
    ll b = food[i].second;
    dp[j + a] = max(dp[j] + b, dp[j + a]);
  }
  cout << *max_element(ALL(dp));
}

int main()
{
	fastio;
	solve();

	return 0;
}