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

void solve()
{
  ll h, w;
  cin >> h >> w;
  vector<string> mp(h);
  rep(i, h) cin >> mp[i];

  vector< vector<ll> > dp(h, vector<ll>(w, 0));
  vector< vector<ll> > point(h, vector<ll>(w, 0));
  rep(y, h) rep(x, w)
  {
    if ((y + x) % 2)
    {
      if (mp[y][x] == '+') point[y][x] = 1;
      else point[y][x] = -1;
    }
    else
    {
      if (mp[y][x] == '+') point[y][x] = -1;
      else point[y][x] = 1;
    }
  }

  // 点数差：Takahashiがプラス
  for(ll y = h - 2; y >= 0; --y)
  {
    dp[y][w - 1] = dp[y + 1][w - 1] + point[y + 1][w - 1];
  }
  for (ll x = w - 2; x >= 0; --x)
  {
    dp[h - 1][x] = dp[h - 1][x + 1] + point[h - 1][x + 1];
  }

  for(ll y = h - 2; y >= 0; --y)
  {
    for (ll x = w - 2; x >= 0; --x)
    {
      ll l = dp[y + 1][x] + point[y + 1][x];
      ll r = dp[y][x + 1] + point[y][x + 1];
      dp[y][x] = ((x + y) % 2) ? min(l, r) : max(l, r);
    }
  }

  if (dp[0][0] == 0) show("Draw");
  else if (dp[0][0] > 0) show("Takahashi");
  else show("Aoki");
}

int main()
{
  fastio;
  solve();

  return 0;
}