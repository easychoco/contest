#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=(a);i<(ll)(n);++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=(a);i<=(ll)(n);++i)
#define rrep(i,n) rrepi(i,n,0)
#define rrepi(i,n,a) for(ll i=(n);i>=(a);--i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = int_fast64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

// 分数を扱う
// 偏角ソート用に演算子を指定する
// https://atcoder.jp/contests/abc225/editorial/2853
struct fraction {
  // y / x
  ll y, x;
  fraction(ll _y = 0, ll _x = 1): y(_y), x(_x) {}
  bool operator < (const fraction &other) const {
    return y * other.x < other.y * x;
  }
  bool operator <= (const fraction &other) const {
    return y * other.x <= other.y * x;
  }
  void show()
  {
    cout << y << " / " << x;
  }
};

void solve()
{
  ll n;
  cin >> n;
  // pair<to_frac, from_frac>
  vector<pair<fraction, fraction>> tilt(n);
  rep(i, n)
  {
    ll x, y;
    cin >> x >> y;
    tilt[i] = make_pair(
      fraction(y, x - 1),
      fraction(y - 1, x)
    );
  }

  sort(ALL(tilt));

  fraction last_pos(-1, 1);
  ll ans = 0;
  for(auto [to, from] : tilt)
  {
    if (last_pos <= from)
    {
      ans++;
      last_pos = to;
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
