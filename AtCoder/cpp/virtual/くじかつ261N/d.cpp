// https://atcoder.jp/contests/abc181/tasks/abc181_e
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

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<ll> h(n);
  vector<ll> w(m);
  rep(i, n) cin >> h[i];
  rep(i, m) cin >> w[i];
  sort(ALL(h));
  sort(ALL(w));


  if (n == 1)
  {
    ll ans = 1LL << 60;
    rep(i, m) chmin(ans, abs(h[0] - w[i]));
    show(ans);
    return;
  }

  vector<ll> d0;
  vector<ll> d1;
  rep(i, n / 2)
  {
    d0.emplace_back(abs(h[i * 2] - h[i * 2 + 1]));
    d1.emplace_back(abs(h[i * 2 + 1] - h[i * 2 + 2]));
  }

  vector<ll> b0(d0);
  vector<ll> b1(d1);

  repi(i, 1, n / 2) b0[i] += b0[i - 1];
  repi(i, 1, n / 2) b1[i] += b1[i - 1];

  ll ans = 1LL << 60;
  rep(i, n / 2 + 1)
  {
    ll hi = i * 2;
    auto itr = lower_bound(ALL(w), h[hi]);

    ll score = abs(*itr - h[hi]);
    if (itr != w.begin())
    {
      itr--;
      chmin(score, h[hi] - *itr);
    }

    // d0 を前から i 個
    // d1 を後から i 個
    score += b1.back();
    if (i > 0)
    {
      score += b0[i - 1];
      score -= b1[i - 1];
    }
    chmin(ans, score);
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}