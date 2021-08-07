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

bool come[1010][1010][4];

void solve()
{
  ll h, w, rs, cs, rt, ct;
  cin >> h >> w >> rs >> cs >> rt >> ct;

  vector<string> mp(h);
  rep(i, h) { cin >> mp[i]; }

  rs--; cs--;
  rt--; ct--;

  const ll R = 0;
  const ll L = 1;
  const ll D = 2;
  const ll U = 3;

  deque<tuple<ll, ll, ll, ll>> que;
  que.emplace_front(-1, rs, cs, -1);
  ll ans = 1LL << 60;
  while (!que.empty())
  {
    ll cost, y, x, dir;
    tie(cost, y, x, dir) = que.front();
    que.pop_front();

    if (come[y][x][dir]) continue;
    come[y][x][dir] = true;

    if (y == rt && x == ct)
    {
      ans = cost;
      break;
    }

    // 右
    if (x + 1  < w && mp[y][x + 1] == '.')
    {
      if (dir == R) que.emplace_front(cost, y, x + 1, R);
      else que.emplace_back(cost + 1, y, x + 1, R);
    }

    // 左
    if (x - 1 >= 0 && mp[y][x - 1] == '.')
    {
      if (dir == L) que.emplace_front(cost, y, x - 1, L);
      else que.emplace_back(cost + 1, y, x - 1, L);
    }

    // 下
    if (y + 1  < h && mp[y + 1][x] == '.')
    {
      if (dir == D) que.emplace_front(cost, y + 1, x, D);
      else que.emplace_back(cost + 1, y + 1, x, D);
    }

    // 上
    if ( y - 1 >= 0 && mp[y - 1][x] == '.')
    {
      if (dir == U) que.emplace_front(cost, y - 1, x, U);
      else que.emplace_back(cost + 1, y - 1, x, U);
    }
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}