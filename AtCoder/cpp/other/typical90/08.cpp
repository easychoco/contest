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

void solve()
{
  ll n;
  string s;
  cin >> n >> s;

  string t;
  rep(i, n)
  {
    if (s[i] == 'a' || s[i] == 't' || s[i] == 'c' || s[i] == 'o' || s[i] == 'd' || s[i] == 'e' || s[i] == 'r')
    {
      t += s[i];
    }
  }

  ll sz = t.length();
  vector< vector<mint> > dp(7, vector<mint>(sz + 1, 0));
  if (t[0] == 'a') dp[0][0] = 1;
  repi(i, 1, sz)
  {
    rep(m, 7) dp[m][i] = dp[m][i - 1];
    if (t[i] == 'a') dp[0][i]++;
    else if (t[i] == 't') dp[1][i] += dp[0][i];
    else if (t[i] == 'c') dp[2][i] += dp[1][i];
    else if (t[i] == 'o') dp[3][i] += dp[2][i];
    else if (t[i] == 'd') dp[4][i] += dp[3][i];
    else if (t[i] == 'e') dp[5][i] += dp[4][i];
    else if (t[i] == 'r') dp[6][i] += dp[5][i];
  }
  show(dp[6][sz - 1].val());
}

int main()
{
  fastio;
  solve();

  return 0;
}