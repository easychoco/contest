// https://atcoder.jp/contests/arc059/tasks/arc059_b
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

  if (s.length() == 2)
  {
    if (s[0] == s[1]) cout << "1 2\n";
    else cout << "-1 -1\n";
    return;
  }

  rep(i, s.length() - 2)
  {
    if (s[i] == s[i + 1] || s[i] == s[i + 2] || s[i + 1] == s[i + 2])
    {
      cout << i + 1 << " " << i + 3 << endl;
      return;
    }
  }

  cout << "-1 -1\n";
}

int main()
{
  fastio;
  solve();

  return 0;
}