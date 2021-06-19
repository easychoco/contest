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

// 最大公約数 : 3,4 ->  1
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

void solve()
{
  ll l, r;
  cin >> l >> r;
  if (l == 1) l++;
  ll ans = 0;
  repie(i, l, r)
  {
    ll le = (l - 1) / i + 1;
    ll re = r / i;

    if (le == 1 && re == 2) break;

    // [le, re] の中で互いに素な 2数の組み合わせの個数がわかれば解ける

    ans += (re - le + 1) * (re - le);
    repie(j, le, re)
    {
      ans -= (re / j - 1) * 2;
      if (re / j == 1) break;
    }
    cout << ans << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}