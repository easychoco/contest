// https://atcoder.jp/contests/abc129/tasks/abc129_d
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

  vector< vector<ll> > scorev(h, vector<ll>(w, 0));
  vector< vector<ll> > scoreh(h, vector<ll>(w, 0));
  rep(y, h)
  {
    ll sc = 0;
    rep(x, w)
    {
      if (mp[y][x] == '.')
      {
        sc++;
        scoreh[y][x] = sc;
      }
      if (mp[y][x] == '#')
      {
        sc = 0;
        scoreh[y][x] = 0;
      }
    }
    for(int x = w - 2; x >= 0; --x)
    {
      if (scoreh[y][x + 1] > 0 && scoreh[y][x] > 0) scoreh[y][x] = scoreh[y][x + 1];
    }
  }

  rep(x, w)
  {
    ll sc = 0;
    rep(y, h)
    {
      if (mp[y][x] == '.')
      {
        sc++;
        scorev[y][x] = sc;
      }
      if (mp[y][x] == '#')
      {
        sc = 0;
        scorev[y][x] = 0;
      }
    }
    for(int y = h - 2; y >= 0; --y)
    {
      if (scorev[y + 1][x] > 0 && scorev[y][x] > 0) scorev[y][x] = scorev[y + 1][x];
    }
  }

  ll ans = 0;
  rep(y, h)
  {
    rep(x, w)
    {
      chmax(ans, scorev[y][x] + scoreh[y][x]);
    }
  }
  show(ans - 1);
}

int main()
{
  fastio;
  solve();

  return 0;
}