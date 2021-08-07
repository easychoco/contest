// https://atcoder.jp/contests/abc182/tasks/abc182_e
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

ll mp[1500][1500];
ll score[1500][1500];

void solve()
{
  ll h, w, n, m;
  cin >> h >> w >> n >> m;

  const ll LIGHT = 3;
  const ll BLOCK = 5;
  rep(i, n)
  {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    mp[a][b] = LIGHT;
  }
  rep(i, m)
  {
    ll c, d;
    cin >> c >> d;
    c--; d--;
    mp[c][d] = BLOCK;
  }

  rep(ii, 2)
  {
    rep(y, h)
    {
      ll le = 0;
      bool isBlock = true;
      rep(x, w)
      {
        if (mp[y][x] == LIGHT)
        {
          isBlock = false;
        }
        if (mp[y][x] == BLOCK)
        {
          if (!isBlock) repi(xx, le, x) score[y][xx] |= 1;
          le = x + 1;
          isBlock = true;
        }
      }
      if (!isBlock) repi(xx, le, w) score[y][xx] |= 1;
    }
    if (ii == 0) rep(y, 1500) rep(x, y) { swap(mp[y][x], mp[x][y]); swap(score[y][x], score[x][y]); }
    swap(h, w);
  }

  ll ans = 0;
  rep(y, 1500) rep(x, 1500) ans += score[y][x];

  Showln(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}