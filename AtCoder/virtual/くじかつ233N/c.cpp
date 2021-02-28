// https://atcoder.jp/contests/keyence2019/tasks/keyence2019_b
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
  string s;
  cin >> s;
  if (s == "keyence")
  {
    cout << "YES\n";
    return;
  }

  rep(i, s.length())
  {
    rep(j, s.length() - i)
    {
      string ss = s.substr(0, i);
      if (ss == "keyence")
      {
        cout << "YES\n";
        return;
      }
      ss += s.substr(i + j);
      if (ss == "keyence")
      {
        cout << "YES\n";
        return;
      }
      
    }
  }
  cout << "NO\n";
}

int main()
{
  fastio;
  solve();

  return 0;
}