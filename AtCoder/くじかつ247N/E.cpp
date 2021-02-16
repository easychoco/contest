// https://atcoder.jp/contests/abc184/submissions
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

const int dx[4] = { 0, 1, 0, -1};
const int dy[4] = { 1, 0, -1, 0};
bool come[2000][2000];
bool used[26];
void solve()
{
  ll h, w;
  cin >> h >> w;
  vector<string> mp(h);
  rep(i, h) cin >> mp[i];

  vector<P> warp[26];

  ll sy, sx;
  rep(y, h) rep(x, w)
  {
    if (mp[y][x] == '.') {}
    else if (mp[y][x] == 'G') {}
    else if (mp[y][x] == 'S') { sy = y; sx = x; }
    else if (mp[y][x] == '#') { come[y][x] = true; }
    else warp[(int)(mp[y][x] - 'a')].emplace_back(P(y, x));
  }


  //           y,  x, cost
  queue<tuple<ll, ll, ll>> que;
  que.emplace(sy, sx, 0);
  while(!que.empty())
  {
    ll y, x, cost;
    tie(y, x, cost) = que.front();
    que.pop();

    if (mp[y][x] == 'G')
    {
      show(cost);
      return;
    }

    if (come[y][x]) continue;
    come[y][x] = true;

    if (isalpha(mp[y][x]) && mp[y][x] != 'S')
    {
      int ia = (int)(mp[y][x] - 'a');
      if (!used[ia])
      for(P p : warp[ia])
      {
        ll wy, wx;
        tie(wy, wx) = p;
        que.emplace(wy, wx, cost + 1);
      }
      used[ia] = true;
    }

    rep(i, 4)
    {
      ll nx = x + dx[i];
      ll ny = y + dy[i];

      if (nx < 0 || w <= nx || ny < 0 || h <= ny) continue;
      if (come[ny][nx]) continue;
      que.emplace(ny, nx, cost + 1);
    }
  }
  show(-1);
}

int main()
{
  fastio;
  solve();

  return 0;
}