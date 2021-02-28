// https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_a
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
  ll x, y;
  cin >> x >> y;
  x--; y--;
  ll prize[4] = { 300000, 200000, 100000, 0 };
  chmin(x, 3LL);
  chmin(y, 3LL);

  ll ans = 0;
  ans += prize[x] + prize[y];
  if (x == y && x == 0) ans += 400000;
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}