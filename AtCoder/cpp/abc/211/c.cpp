#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=(a);i<(ll)(n);++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=(a);i<=(ll)(n);++i)
#define rrep(i,n) rrepi(i,n,0)
#define rrepi(i,n,a) for(ll i=(n);i>=(a);--i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

using mint = modint1000000007;
 
void solve()
{
  string s;
  cin >> s;
 
  string t;
  ll nn = s.length();
  rep(i, nn)
  {
    if (s[i] == 'c' ||
        s[i] == 'h' ||
        s[i] == 'o' ||
        s[i] == 'k' ||
        s[i] == 'u' ||
        s[i] == 'd' ||
        s[i] == 'a' ||
        s[i] == 'i')
    {
      t += s[i];
    }
  }
 
  ll sz = t.length();
  vector< vector<mint> > dp(8, vector<mint>(sz + 1, 0));
  if (t[0] == 'c') dp[0][0] = 1;
  repi(i, 1, sz)
  {
    rep(m, 8) dp[m][i] = dp[m][i - 1];
    if (t[i] == 'c') dp[0][i]++;
    if (t[i] == 'h') dp[1][i] += dp[0][i];
    if (t[i] == 'o') dp[2][i] += dp[1][i];
    if (t[i] == 'k') dp[3][i] += dp[2][i];
    if (t[i] == 'u') dp[4][i] += dp[3][i];
    if (t[i] == 'd') dp[5][i] += dp[4][i];
    if (t[i] == 'a') dp[6][i] += dp[5][i];
    if (t[i] == 'i') dp[7][i] += dp[6][i];
  }
  show(dp[7][sz - 1].val());
}

int main()
{
  fastio;
  solve();

  return 0;
}