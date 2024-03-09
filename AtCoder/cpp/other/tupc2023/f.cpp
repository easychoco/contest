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
using P = pair<ll, vl>;
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
inline void printp(T &p){ for (auto [a, b] : p) { cout << a << endl; for (auto v : b) cout << v << " "; cout << endl; } }
template <class T>
inline void printt(T &t){ for (auto [a, b, c] : t) print(a, b, c); }
void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head&& head, Tail&&... tail){ cerr << head << " "; debug(std::forward<Tail>(tail)...); }

void solve()
{
  ll q;
  cin >> q;

  // front: 最新
  // back: 最古
  deque<P> acc{P(1, vl{1})};
  ll seq_sz = 1;
  rep(i, q)
  {
    ll t, x;
    cin >> t >> x;

    if (t == 3)
    {
      ll pos = x;
      ll maybe = INF;

      if (seq_sz < pos)
      {
        print(-1);
        continue;
      }

      for (const auto& query : acc)
      {
        // 圧縮すれば高々 60クエリなので、計算量は 60 * Q におさまる
        if (pos == 0) break;
        ll acc_sz = (ll)query.second.size();
        if (query.first == 1)
        {
          if (pos <= acc_sz)
          {
            if (maybe == INF)
            {
              maybe = query.second[acc_sz - pos];
            }
            pos = 0;
          }
          else
          {
            pos -= acc_sz;
          }
        }
        else if (query.first == 2)
        {
          // 2 の演算をする前に pos が奇数だったら maybe を更新する
          for (auto itr = query.second.rbegin(); itr != query.second.rend(); ++itr)
          {
            if (pos & 1 && maybe == INF)
            {
              maybe = *itr;
            }
            pos /= 2;
          }
        }
      }

      if (pos == 0 && maybe != INF) print(maybe);
      else print(-1);
    }
    else
    {
      if (acc[0].first != t)
      {
        acc.push_front(P(t, vl{x}));
      }
      else
      { // query の種類が一致
        acc[0].second.push_back(x);
      }
      if (seq_sz > 2'000'000'000) continue; // オーバーフロー対策
      if (t == 1) seq_sz += 1;
      if (t == 2) seq_sz *= 2;
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
