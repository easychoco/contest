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
  ll h, w, m, xin, yin;
  cin >> h >> w >> m;
  vector<P> block(m); // (x, y)
  rep(i, m)
  {
    cin >> yin >> xin;
    block[i] = P(xin - 1, yin - 1);
  }

  sort(ALL(block));
  ll non_grid = 0;
  set<ll> block_y;
  ll min_y0 = w + 1;
  rep(i, m)
  {
    ll x = block[i].first;
    ll y = block[i].second;
    if (x == 0)
    {
      if (i > 0) continue;
      repi(yi, y, h)
      {
        block_y.insert(yi);
      }
      non_grid += (h - y);
      continue;
    }
    if (y == 0)
    {
      if (chmin(min_y0, x)) non_grid += (w - x);
      continue;
    }

    if (min_y0 < x)
    {
      
      continue;      
    }

    block_y.insert(y);
    if (i > 0 && block[i - 1].first == x) continue;
    non_grid++;
    non_grid += distance(block_y.upper_bound(y), block_y.end());   
  }
  Showln(h * w - non_grid);
}

int main()
{
  fastio;
  solve();

  return 0;
}