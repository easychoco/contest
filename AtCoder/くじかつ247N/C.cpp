// https://atcoder.jp/contests/abc065/tasks/arc076_a
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

const ll MOD = 1000000007;

void solve()
{
  ll n, m;
  cin >> n >> m;
  if (abs(n - m) > 1)
  {
    show(0);
    return;
  }

  ll ans = 1LL;
  repi(i, 1, n + 1)
  {
    ans *= i;
    ans %= MOD;
  }
  repi(i, 1, m + 1)
  {
    ans *= i;
    ans %= MOD;
  }
  if (n == m) ans *= 2;
  show(ans % MOD);
}

int main()
{
  fastio;
  solve();

  return 0;
}