#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=a;i<=(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<ll, ll>;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

using mint = modint1000000007;

void solve()
{
  ll h, w;
  cin >> h >> w;
  string mp[h];
  rep(i, h) cin >> mp[i];

  vector< vector<mint> > ans(1010, vector<mint>(1010, 0));

  ans[0][0] = 1;
  rep(y, h) rep(x, w)
  {
    if (mp[y][x] == '#') continue;

    ll nx, ny;

    // 右
    nx = x + 1;
    ny = y;
    if (nx < w && mp[ny][nx] != '#')
    {
      ans[ny][nx] += ans[y][x];
    }

    // 下
    nx = x;
    ny = y + 1;
    if (ny < h && mp[ny][nx] != '#')
    {
      ans[ny][nx] += ans[y][x];
    }
  }
  show(ans[h - 1][w - 1].val());
}

int main()
{
  fastio;
  solve();

  return 0;
}