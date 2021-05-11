// https://atcoder.jp/contests/abc129/tasks/abc129_e
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

using mint = modint1000000007;

// combination mod prime
// https://www.youtube.com/watch?v=8uowVvQ_-Mo&feature=youtu.be&t=1619
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
} c (4000);

void solve()
{
  string bit;
  cin >> bit;

  // dp2[i] = 上から i 桁が決まっていて、 A + B が bit 以下か不明な (A,B) の組み合わせの個数
  vector<mint> dp0(bit.length() + 1, 0);

  // dp1[i] = 上から i 桁が決まっていて、 A + B が bit 以下である (A,B) の組み合わせの個数
  vector<mint> dp1(bit.length() + 1, 0);

  dp0[0] = 1;
  dp1[0] = 0;

  repie(i, 1, bit.length())
  {
    if (bit[i - 1] == '0')
    {
      dp0[i] = dp0[i - 1];
      dp1[i] = dp1[i - 1] * 3;
    }
    else // if bit[i] == 1
    {
      dp0[i] = 2 * dp0[i - 1];
      dp1[i] = 3 * dp1[i - 1] + dp0[i - 1];
    }
  }
  mint ans = dp0.back() + dp1.back();
  show(ans.val());
}

int main()
{
  fastio;
  solve();

  return 0;
}