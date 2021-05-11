// https://atcoder.jp/contests/agc023/tasks/agc023_b
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
  ll n;
  cin >> n;
  vector<string> mp(n);
  rep(i, n) cin >> mp[i];
  
  ll ans = 0;
  rep(a, n)
  {
    bool ok = true;
    rep(y, n)
    {
      rep(x, y)
      {
        int yy = (y + a) % n;
        int xx = (x + a) % n;
        ok = (mp[yy][x] == mp[xx][y]);
        if (!ok) break;
      }
      if (!ok) break;
    }

    ans += (ok);
  }

  cout << ans * n << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}