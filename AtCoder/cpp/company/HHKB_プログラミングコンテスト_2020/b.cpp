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
  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  for(int i = 0; i < h; ++i)
  {
    cin >> s[i];
  }

  ll ans = 0;
  rep(y, h) rep(x, w)
  {
    if (s[y][x] == '#') continue;
    if (y + 1 < h) if (s[y + 1][x] == '.') ans++;
    if (x + 1 < w) if (s[y][x + 1] == '.') ans++;
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}