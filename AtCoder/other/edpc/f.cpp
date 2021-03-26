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

ll dp[3010][3010];

void solve()
{
  string s, t;
  cin >> s >> t;

  // dp[i][j] =  s を i 文字目, t を j 文字目までみたときの LCS

  repie(si, 1, s.length())
  repie(ti, 1, t.length())
  {
    if (s[si - 1] == t[ti - 1]) dp[si][ti] = dp[si - 1][ti - 1] + 1;
    else dp[si][ti] = max(dp[si - 1][ti], dp[si][ti - 1]);
  }

  string ans = "";
  ll si = s.length();
  ll ti = t.length();
  ll sc = dp[si][ti];
  while(sc > 0)
  {
    if (s[si - 1] == t[ti - 1])
    {
      ans += s[si - 1];
      si--;
      ti--;
      sc--;
    }
    else if (dp[si - 1][ti] == sc) si--;
    else ti--;
  }

  reverse(ALL(ans));
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}