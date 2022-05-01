#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=(a);i<(ll)(n);++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=(a);i<=(ll)(n);++i)
#define rrep(i,n) rrepi(i,n,0)
#define rrepi(i,n,a) for(ll i=(ll)(n);i>=(ll)(a);--i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define pb push_back
#define eb emplace_back

using namespace std;
using namespace atcoder;
using vb = vector<bool>;
using vvb = vector<vb>;
using ll = int_fast64_t;
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
template <class Head, class... Tail>
void print(Head &&head, Tail &&...tail){ cout << head << " "; print(std::forward<Tail>(tail)...); }
void printd(double d) { cout << std::fixed << setprecision(13) << d << endl; }
template <class T>
inline void printv(T &v){ for (auto a : v) print(a); }
template <class T>
inline void printvp(T &p){ for (auto [a, b] : p) print(a, b); }
template <class T>
inline void printvt(T &t){ for (auto [a, b, c] : t) print(a, b, c); }
void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head&& head, Tail&&... tail){ cerr << head << " "; debug(std::forward<Tail>(tail)...); }

void solve()
{
  ll n, k;
  cin >> n >> k;

  vvl ys;
  ys.pb(vl(1, 0));
  rep(i, n)
  {
    ll t, y;
    cin >> t >> y;
    if (t == 1)
    {
      ys.pb(vl(1, y));
    }
    else
    {
      ys.back().pb(y);
    }
  }

  priority_queue<ll> max_que; // 除外した整数
  priority_queue<ll, vl, greater<ll>> min_que; // えらぶ整数

  max_que.push(-INF);
  min_que.push(INF);

  ll sum = 0;
  ll ans = -INF;
  rep(i, ys.size())
  {
    if (k - i + 1 < 0) break;
    // 後ろから ni まで見る
    ll ni = ys.size() - i - 1;
    repi(j, 1, ys[ni].size())
    {
      ll v = ys[ni][j];
      max_que.push(v);
    }

    // 除外したものより小さい数字を選んでいたら、除外済みの最大値と交換する
    while(min_que.top() < max_que.top())
    {
      min_que.push(max_que.top());
      max_que.push(min_que.top());

      sum += max_que.top();
      sum -= min_que.top();

      min_que.pop();
      max_que.pop();
    }

    // あふれていたら合計が大きくなるように選択する
    while((ll)max_que.size() > k - i + 1 || max_que.top() > 0)
    {
      min_que.push(max_que.top());
      sum += max_que.top();
      max_que.pop();      
    }

    // まだ除外できて、選んだ整数に負の数が含まれていたら除外する
    while((ll)max_que.size() < k - i + 1 && min_que.top() < 0)
    {
      max_que.push(min_que.top());
      sum -= min_que.top();
      min_que.pop();
    }

    chmax(ans, ys[ni][0] + sum);
  }
  print(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
