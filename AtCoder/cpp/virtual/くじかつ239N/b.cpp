// https://atcoder.jp/contests/abc121/tasks/abc121_c
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
  ll n, m;
  cin >> n >> m;
  vector<tuple<ll, ll>> dr(n);
  rep(i, n)
  {
    ll a, b;
    cin >> a >> b;
    dr[i] = make_tuple(a, b);
  }
  sort(ALL(dr));

  ll ans = 0;
  ll num = 0;
  rep(i, n)
  {
    ll a, b;
    tie(a, b) = dr[i];

    ans += min(b, m - num) * a;
    num += min(b, m - num);
    if (num == m) break;
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}