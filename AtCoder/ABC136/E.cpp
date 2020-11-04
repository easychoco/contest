#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define Show(val) cout<<(val)<<" "
#define Showln(val) cout<<(val)<<endl

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void solve()
{
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll sum = accumulate(ALL(a), 0LL);
  vector<ll> factors;
  for(ll f = 1; f * f <= sum; ++f)
  {
    if (sum % f == 0)
    {
      factors.emplace_back(f);
      if (f * f < sum) factors.emplace_back(sum / f);
    }
  }
  sort(RALL(factors));
  for(const auto& target : factors)
  {
    vector<ll> diff(n);
    ll sum_diff = 0;
    rep(i, n)
    {
      ll fm = a[i] % target;
      diff[i] = ((fm < target - fm) ? -fm : target - fm);      
      sum_diff += diff[i];
    }

    if (sum_diff > 0)
    {
      sort(RALL(diff));
      rep(i, sum_diff / target) diff[i] -= target;
    }
    else if (sum_diff < 0)
    {
      sort(ALL(diff));
      rep(i, -sum_diff / target) diff[i] += target;
    }

    ll cnt = 0;
    rep(i, n) if(diff[i] > 0) cnt += diff[i];
    if (cnt <= k)
    {
      cout << target << endl;
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