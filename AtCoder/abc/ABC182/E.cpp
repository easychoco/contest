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

int mp[1505][1505];

void solve()
{
  ll h, w, n, m;
  cin >> h >> w >> n >> m;
  vector<ll> ly(n), lx(n), by(m), bx(m);
  rep(i, n)
  {
    cin >> ly[i] >> lx[i];
    ly[i]--; lx[i]--;
  }
  rep(i, m)
  {
    cin >> by[i] >> bx[i];
    by[i]--; bx[i]--;
  }

  const int LIGHT = 10;
  const int BLOCK = -5;

  // light
  rep(i, n) mp[ly[i]][lx[i]] = LIGHT;

  // block
  rep(i, m) mp[by[i]][bx[i]] = BLOCK;

  // 横
  rep(ii, 2)
  {
    rep(y, h)
    {
      ll sx = 0;
      bool last_light = false;
      rep(x, w)
      {
        if (mp[y][x] == LIGHT)
        {
          for(int i = sx; i < x; ++i) mp[y][i] = 1;
          sx = x + 1;
          last_light = true;
        }
        else if (mp[y][x] == BLOCK)
        {
          if (last_light) for(int i = sx; i < x; ++i) mp[y][i] = 1;
          sx = x + 1;
          last_light = false;
        }
        else if (x == w - 1 && last_light)
        {
          for(int i = sx; i <= x; ++i) mp[y][i] = 1;
        }
      }
    }
    if (ii == 1) break;

    // 転置
    rep(x, 1505) rep(y, x) swap(mp[x][y], mp[y][x]);
    swap(h, w);
  }

  ll ans = 0;
  rep(y, h) rep(x, w) ans += (mp[y][x] > 0);
  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}