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

ll b[2][3], c[3][2];
map<string, tuple<ll, ll>> memo;

tuple<ll, ll> calcScore(string mp)
{
  ll sa = 0, sb = 0;
  rep(y, 2) rep(x, 3)
  {
    if ((mp[x + y * 3] == mp[x + (y+1) * 3])) sa += b[y][x];
    else sb += b[y][x];
  }
  rep(y, 3) rep(x, 2)
  {
    if ((mp[x + y * 3] == mp[(x+1) + y * 3])) sa += c[y][x];
    else sb += c[y][x];
  }
  return make_tuple(sa, sb);
}

tuple<ll, ll> dfs(string mp, int depth)
{
  if (memo.find(mp) != memo.end()) return memo[mp];
  if (depth >= 9)
  {
    // 盤面スコアを計算
    return memo[mp] = calcScore(mp);
  }
  
  tuple<ll, ll> ret{-1, -1};
  rep(i, 9)
  {
    if (mp[i] != '-') continue;

    string next = mp;
    if (depth & 1)
    { // 後攻
      next[i] = 'x';
      auto res_x = dfs(next, depth + 1);
      ll xb = get<1>(res_x);
      if (get<1>(ret) < xb) ret = res_x;
    }
    else
    { // 先攻
      next[i] = 'o';
      auto res_o = dfs(next, depth + 1);
      ll oa = get<0>(res_o);
      if (get<0>(ret) < oa) ret = res_o;
    }
  }
  return memo[mp] = ret;
}

void solve()
{
  rep(y, 2) rep(x, 3) cin >> b[y][x];
  rep(y, 3) rep(x, 2) cin >> c[y][x];

  ll ans_a, ans_b;
  tie(ans_a, ans_b) = dfs("---------", 0);
  cout << ans_a << "\n" << ans_b << "\n";
}

int main()
{
  fastio;
  solve();

  return 0;
}