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

// a^n % mod を計算する O(log n)
ll powmod(ll a, ll n, ll mod) {
  ll ret = 1;
  while (n > 0) {
    if (n % 2 == 1) { ret = ret * a % mod; }
    a = a * a % mod;
    n /= 2;
  }
  return ret;
}

void solve()
{
  ll n;
  cin >> n;
  vector<ll> f(n);
  rep(i, n)
  {
    cin >> f[i];
    f[i]--;
  }

  vector<bool> come(n, false);
  ll cnt = 0;
  rep(start, n)
  {
    if (come[start]) continue;
    ll now = start;
    vector<bool> idx(come);
    
    while(!idx[now])
    {
      idx[now] = true;
      now = f[now];
    }

    come[start] = true;
    if (now == start)
    {
      cnt++;
      come = idx;
    }
  }

  show(powmod(2, cnt, 998244353LL) - 1);
}

int main()
{
  fastio;
  solve();

  return 0;
}