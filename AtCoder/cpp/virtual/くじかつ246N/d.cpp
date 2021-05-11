// https://atcoder.jp/contests/arc080/tasks/arc080_b
#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

int ans[100][100];

void solve()
{
  ll h, w, n;
  cin >> h >> w >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  int dx[4] = { 1, 0, -1, 0 };
  int dy[4] = { 0, 1, 0, -1 };
  int di = 0;
  int xi = 0, yi = 0;
  int color = 0;
  rep(i, h * w)
  {
    ans[yi][xi] = color + 1;
    a[color]--;
    if (a[color] <= 0) color++;

    ll nx = xi + dx[di];
    ll ny = yi + dy[di];
    if (nx < 0 || w <= nx || ny < 0 || h <= ny || ans[ny][nx] != 0) di = (di + 1) % 4;
    xi += dx[di];
    yi += dy[di];
  }

  rep(y, h)
  {
    rep(x, w) cout << ans[y][x] << " ";
    show();
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}