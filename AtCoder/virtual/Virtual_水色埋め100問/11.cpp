// https://atcoder.jp/contests/arc069/tasks/arc069_b
#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define Show(val) cout<<(val)<<" "
#define Showln(val) cout<<(val)<<endl

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void solve()
{
  ll n;
  string s;
  cin >> n >> s;

  string ans[4] = { "SS", "SW", "WS", "WW" };

  rep(ii, 4)
  {
    repi(i, 1, n)
    {
      bool sheep = (ans[ii][i] == 'S');
      if (sheep)
      {
        if (s[i] == 'o') ans[ii] += (ans[ii][i - 1] == 'S') ? "S" : "W";
        else ans[ii] += (ans[ii][i - 1] == 'S') ? "W" : "S";
      }
      else // if wolf
      {
        if (s[i] == 'o') ans[ii] += (ans[ii][i - 1] == 'W') ? "S" : "W";
        else ans[ii] += (ans[ii][i - 1] == 'W') ? "W" : "S";
      }      
    }
  }

  rep(i, 4)
  {
    bool ok = (ans[i][0] == ans[i][n]);
    if (ans[i][0] == 'S')
    {
      if (s[0] == 'o') ok &= (ans[i][1] == ans[i][n - 1]);
      else ok &= (ans[i][1] != ans[i][n - 1]);
    }
    else // if ans[i][0] == 'W'
    {
      if (s[0] == 'o') ok &= (ans[i][1] != ans[i][n - 1]);
      else ok &= (ans[i][1] == ans[i][n - 1]);      
    }

    if (ok)
    {
      cout << ans[i].substr(0, n) << endl;
      return;
    }
  }
  cout << "-1\n";
}

int main()
{
  fastio;
  solve();

  return 0;
}