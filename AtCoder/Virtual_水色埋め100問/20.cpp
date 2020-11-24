// https://atcoder.jp/contests/abc099/tasks/abc099_d
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
  ll n, c;
  cin >> n >> c;
  vector< vector<ll> > dist(c, vector<ll>(c));
  vector< vector<ll> > color(n, vector<ll>(n));
  rep(from, c) rep(to, c) cin >> dist[from][to];
  rep(y, n) rep(x, n) { cin >> color[y][x]; color[y][x]--; }

  vector< vector<ll> > sc(3, vector<ll>(c, 0));
  rep(ci, c)
  {
    ll score = 0;
    rep(y, n) rep(x, n)
    {
      int idx = (x + y) % 3;
      sc[idx][ci] += dist[color[y][x]][ci];
    }
  }

  ll ans = 1LL<<60;
  rep(c1, c) rep(c2, c1) rep(c3, c2)
  {
    ll score = 1LL<<60;
    vector<int> p(3);
    iota(ALL(p), 0);
    do{
      chmin(score, sc[p[0]][c1] + sc[p[1]][c2] + sc[p[2]][c3]);
    }while(next_permutation(ALL(p)));
    chmin(ans, score);
  }
  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}