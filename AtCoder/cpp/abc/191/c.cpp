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
  ll h, w;
  cin >> h >> w;
  vector<string> mp(h);
  rep(i, h) cin >> mp[i];

  vector<string> s{
    "....",
    "...#",
    "..#.",
    "..##",
    ".#..",
    ".#.#",
    ".##.",
    ".###",
    "#...",
    "#..#",
    "#.#.",
    "#.##",
    "##..",
    "##.#",
    "###.",
    "####"
  }; 

  vector<ll> score{
    0,
    1,
    1,
    0,
    1,
    0,
    2,
    1,
    1,
    2,
    0,
    1,
    0,
    1,
    1,
    0
  };

  ll ans = 0;
  repi(y, 1, h)
  {
    repi(x, 1, w)
    {
      string ss = "";
      ss += mp[y-1][x-1];
      ss += mp[y-1][x];
      ss += mp[y][x-1];
      ss += mp[y][x];
      rep(i, 16) if (ss == s[i]) ans += score[i];
    }
  }
  Showln(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}