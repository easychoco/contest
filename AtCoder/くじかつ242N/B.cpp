// https://atcoder.jp/contests/abc183/tasks/abc183_c
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
  ll n, k;
  cin >> n >> k;
  vector< vector<ll> > a(n, vector<ll>(n));
  rep(i, n) rep(j, n)
  {
    cin >> a[i][j];
  }

  vector<ll> co(n - 1);
  rep(i, n - 1) co[i] = i + 1;

  ll ans = 0;
  do {
    ll cost = a[0][co[0]] + a[co.back()][0];
    rep(i, n - 2) cost += a[co[i]][co[i + 1]];
    if (cost == k) ans++;
  } while(next_permutation(ALL(co)));

  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}