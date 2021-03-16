// https://atcoder.jp/contests/agc041/tasks/agc041_b
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
  ll n, m, v, p;
  cin >> n >> m >> v >> p;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  sort(ALL(a));

  // V 箇所に加点を M 回
  // そのあと、上位 P まで

  // a[n - arg] が問題に選ばれる
  auto f = [&](ll arg)
  {
    if (arg <= p) return true;

    // a[n - arg] の他に vv 箇所をプラスする
    ll vv = v - (p - 1) - (n - arg) - 1;

    // a[n - arg] のみを足し続けられるのでこの値を超えればOK
    if (vv <= 0) return (a[n - arg] + m) >= a[n - p];

    ll sum = 0;
    repie(i, n - arg + 1, n - p) sum += a[i] - a[n - arg];
    ll bunbo = (arg - p - vv);
    // max(重複しているけど最高効率でこれだけの回数あればいける, 最低限必要になる回数)
    return max(((sum - 1) / bunbo + 1), a[n - p] - a[n - arg]) <= m;
  };

  // ac個の問題が選ばれる
  ll ac = 1, wa = n + 1;
  while(wa - ac > 1)
  {
    ll wj = (ac + wa) / 2;
    if ( f(wj) ) ac = wj;
    else wa = wj;
  }

  show(ac);
}

int main()
{
  fastio;
  solve();

  return 0;
}