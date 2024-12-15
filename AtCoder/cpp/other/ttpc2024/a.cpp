#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=(a);i<(ll)(n);++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=(a);i<=(ll)(n);++i)
#define rrep(i,n) rrepi(i,n,0)
#define rrepi(i,n,a) for(ll i=(n);i>=(ll)(a);--i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define pb push_back
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vs = vector<string>;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
using T = tuple<ll, ll, ll>;
using vt = vector<T>;
const ll INF = 1LL << 60;
void YN(bool a, string whenT="Yes", string whenF="No") { cout << (a ? whenT : whenF) << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void print() { cout << endl; }
template <class T>
void print(T &&t){ cout << t << endl; }
template <class Head, class... Tail>
void print(Head &&head, Tail &&...tail){ cout << head << " "; print(std::forward<Tail>(tail)...); }
void printd(double d) { cout << std::fixed << setprecision(13) << d << endl; }
template <class T>
inline void printv(T &v){ for (auto a : v) print(a); }
template <class T>
inline void printp(T &p){ for (auto [a, b] : p) print(a, b); }
template <class T>
inline void printt(T &t){ for (auto [a, b, c] : t) print(a, b, c); }
void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head&& head, Tail&&... tail){ cerr << head << " "; debug(std::forward<Tail>(tail)...); }

// this is J

void solve()
{
  ll h, w;
  cin >> h >> w;

  if (h != w) {
    print("No");
    return;
  }

  vs ans_2 {
    "<^",
    "v>"
  };

  vs ans_3 {
    "<<^",
    "v.^",
    "v>>"
  };

  vs ans_5 {
    "^>>>>",
    "^.v.v",
    "^>.<v",
    "^.^.v",
    "<<<<v"
  };

  vs ans(h, string(h, '.'));

  // 外枠から3層ずつ埋める
  // 引数：埋める範囲の最外殻 (0から)
  auto padding = [&](ll layer) {
    // 最外殻の範囲
    ll l = layer * 3;
    ll r = h - layer * 3 - 1;
    ll u = layer * 3;
    ll d = h - layer * 3 - 1;

    // 1層を埋める
    {
      // 上
      repie(i, l, r - 1) ans[u][i] = '<';
      // 右
      repie(i, u, d - 1) ans[i][r] = '^';
      // 下
      repie(i, l + 1, r) ans[d][i] = '>';
      // 左
      repie(i, u + 1, d) ans[i][l] = 'v';
    }

    // 2層を埋める
    {
      // 上
      for (ll i = l + 2; i <= r - 2; i += 2) {
        ans[u + 1][i] = 'v';
      }
      // 右
      for (ll i = u + 2; i <= d - 2; i += 2) {
        ans[i][r - 1] = '<';
      }
      // 下
      for (ll i = l + 2; i <= r - 2; i += 2) {
        ans[d - 1][i] = '^';
      }
      // 左
      for (ll i = u + 2; i <= d - 2; i += 2) {
        ans[i][l + 1] = '>';
      }
    }

    // 3層を埋める
    {
      // 上
      for (ll i = l + 3; i <= r - 3; i += 2) {
        ans[u + 2][i] = '^';
      }
      // 右
      for (ll i = u + 3; i <= d - 3; i += 2) {
        ans[i][r - 2] = '>';
      }
      // 下
      for (ll i = l + 3; i <= r - 3; i += 2) {
        ans[d - 2][i] = 'v';
      }
      // 左
      for (ll i = u + 3; i <= d - 3; i += 2) {
        ans[i][l + 2] = '<';
      }
    }
  };

  if (h > 6) {
    for (ll i = 0; i < h / 6; ++i) {
      padding(i);
    }
  }

  if (h == 2) {
    print("Yes");
    printv(ans_2);
    return;
  }

  if (h % 6 == 3) {
    rep(y, 3)
    rep(x, 3)
    {
      ans[h / 2 - 1 + y][h / 2 - 1 + x] = ans_3[y][x];
    }
    print("Yes");
    printv(ans);
    return;
  }

  if (h % 6 == 5) {
    rep(y, 5)
    rep(x, 5)
    {
      ans[h / 2 - 2 + y][h / 2 - 2 + x] = ans_5[y][x];
    }
    print("Yes");
    printv(ans);
    return;
  }

  print("No");
  return;

  // if (h == 2 && w == 2) {
  //   print("Yes");
  //   print("<^");
  //   print("v>");
  //   return;
  // }

  // if (h == 3 && w == 3) {
  //   print("Yes");
  //   print("<<^");
  //   print("v.^");
  //   print("v>>");
  //   return;
  // }

  // if (h == 5 && w == 5) {
  //   print("Yes");
  //   print("^>>>>");
  //   print("^.v.v");
  //   print("^>.<v");
  //   print("^.^.v");
  //   print("<<<<v");
  //   return;
  // }

  // if (h == 9 && w == 9) {
  //   print("Yes");
  //   print("<<<<<<<<^");
  //   print("v.v.v.v.^");
  //   print("v>.^.^.<^");
  //   print("v.<<<^>.^");
  //   print("v>.v.^.<^");
  //   print("v.<v>>>.^");
  //   print("v>.v.v.<^");
  //   print("v.^.^.^.^");
  //   print("v>>>>>>>>");
  //   return;
  // }

  // if (h == 11 && w == 11) {
  //   print("Yes");
  //   print("<<<<<<<<<<^");
  //   print("v.v.v.v.v.^");
  //   print("v>.^.^.^.<^");
  //   print("v.<<<<<^>.^");
  //   print("v>.v.v.^.<^");
  //   print("v.<v>.<^>.^");
  //   print("v>.v.^.^.<^");
  //   print("v.<v>>>>>.^");
  //   print("v>.v.v.v.<^");
  //   print("v.^.^.^.^.^");
  //   print("v>>>>>>>>>>");
  // }

  // if (h == 17 && w == 17) {
  //   print("Yes");
  //   print("<<<<<<<<<<<<<<<<^");
  //   print("v.v.v.v.v.v.v.v.^");
  //   print("v>.^.^.^.^.^.^.<^");
  //   print("v.<<<<<<<<<<<^>.^");
  //   print("v>.v.v.v.v.v.^.<^");
  //   print("v.<v>.^.^.^.<^>.^");
  //   print("v>.v.<<<<<^>.^.<^");
  //   print("v.<v>.v.v.^.<^>.^");
  //   print("v>.v.<v>.<^>.^.<^");
  //   print("v.<v>.v.^.^.<^>.^");
  //   print("v>.v.<v>>>>>.^.<^");
  //   print("v.<v>.v.v.v.<^>.^");
  //   print("v>.v.^.^.^.^.^.<^");
  //   print("v.<v>>>>>>>>>>>.^");
  //   print("v>.v.v.v.v.v.v.<^");
  //   print("v.^.^.^.^.^.^.^.^");
  //   print("v>>>>>>>>>>>>>>>>");
  //   return;
  // }

  // print("Yes");
  // printv(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
