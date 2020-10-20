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
  ll n;
  cin >> n;
  vector<ll> a(n);
  cin >> a[0];
  ll ans = n;
  ll inc_cnt = 0;
  repi(i, 1, n)
  {
    cin >> a[i];
    if (a[i - 1] < a[i]) inc_cnt++;
    else
    {
      ans += inc_cnt * (inc_cnt + 1) / 2;
      inc_cnt = 0;
    }
  }

  ans += inc_cnt * (inc_cnt + 1) / 2;
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}