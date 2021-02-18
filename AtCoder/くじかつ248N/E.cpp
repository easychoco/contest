// https://atcoder.jp/contests/abc095/tasks/arc096_b
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

void solve()
{
  ll n, c;
  cin >> n >> c;

  vector<P> ss(n);
  rep(i, n)
  {
    ll x, y;
    cin >> x >> y;
    ss[i] = P(x, y);
  }

  sort(ALL(ss));
  vector<ll> sumx(n), sumv(n);
  sumx[0] = ss[0].first;
  sumv[0] = ss[0].second;
  repi(i, 1, n)
  {
    ll x, v;
    tie(x, v) = ss[i];
    sumx[i] = sumx[i - 1] + x;
    sumv[i] = v;
  }

  ll li = 0;
  ll ri = 0;

  auto fl = [&](int idx){
    return sumv[idx] - sumx[idx];
  };
  auto fr = [&](int idx){
    return (c - sumv[idx]) - (sumx[n - 1] - sumx[idx]);
  };

  rep(i, n)
  {
    if ( fl(li) < fl(i) )
    {
      li = i;
    }
    if ( fr(ri) < fr(i) )
    {
      ri = i;
    }
  }

  show(fl(li), fr(ri));

  ll ans = 0;
  rep(i, n)
  {
    chmax(ans, fl(i) - sumx[i] + fr(ri));
    chmax(ans, fl(li) + fr(i) - (sumx[n - 1] - sumx[i]));
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}