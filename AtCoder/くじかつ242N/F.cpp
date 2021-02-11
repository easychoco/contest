// https://atcoder.jp/contests/arc100/tasks/arc100_b
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
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }

void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i, n)
  {
    cin >> a[i];
  }

  b[0] = a[0];
  repi(i, 1, n) b[i] = b[i - 1] + a[i];
  
  auto f = [&](ll le, ll mid, ll re){
    ll sum1 = b[le];
    ll sum2 = b[mid] - b[le];
    ll sum3 = b[re] - b[mid];
    ll sum4 = b[n - 1] - b[re];
    return make_tuple(sum1, sum2, sum3, sum4);
  };

  ll le = 0, re = 2;
  ll ans = 1LL << 60;
  repi(mid, 1, n - 1)
  {
    auto t1 = f(le, mid, re);
    ll score_l = abs(get<0>(t1) - get<1>(t1));
    while(true)
    {
      auto nt = f(le + 1, mid, re);
      if ( chmin( score_l, abs( get<0>(nt) - get<1>(nt) ) ) ) le++;
      else break;
      if (le + 1 == mid) break;
    }

    auto t2 = f(le, mid, re);
    ll score_r = abs(get<2>(t2) - get<3>(t2));
    while(true)
    {
      auto nt = f(le, mid, re + 1);
      if ( chmin( score_r, abs( get<2>(nt) - get<3>(nt) ) ) ) re++;
      else break;
      if (re + 1 == n) break;
    }

    ll s1, s2, s3, s4;
    tie(s1, s2, s3, s4) = f(le, mid, re);
    chmin(ans, max({s1,s2,s3,s4}) - min({s1,s2,s3,s4}));
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}