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
  rep(i, h) cin >> s[i];

  // tuple<y, x, depth>
  queue<tuple<ll, ll, ll>> que;
  rep(y, h) rep(x, w)
  {
    if (s[y][x] == '#') que.emplace(y, x, 0);
  }
  ll ans = 0;
  while(!que.empty())
  {
    ll x, y, depth;
    tie(y, x, depth) = que.front();
    chmax(ans, depth);
    que.pop();
    if (x-1 >= 0 && s[y][x-1] == '.') { s[y][x-1] = '#'; que.emplace(y, x-1, depth + 1); }
    if (x+1 <  w && s[y][x+1] == '.') { s[y][x+1] = '#'; que.emplace(y, x+1, depth + 1); }
    if (y-1 >= 0 && s[y-1][x] == '.') { s[y-1][x] = '#'; que.emplace(y-1, x, depth + 1); }
    if (y+1 <  h && s[y+1][x] == '.') { s[y+1][x] = '#'; que.emplace(y+1, x, depth + 1); }
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}