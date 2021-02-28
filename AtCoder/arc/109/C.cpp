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

string win(char s1, char s2)
{
  string chk{s1};
  if (s1 == s2) return chk;

  chk += s2;

  sort(ALL(chk));
  //PRS
  if (chk == "PR") return "P";
  if (chk == "PS") return "S";
  if (chk == "RS") return "R";

  cout << "\n\n\nout\n\n";
  return "\n\n\nout\n\n";
}

void solve()
{
  ll n, k;
  string s;
  cin >> n >> k >> s;

  string now = s;
  rep(lp, k)
  {
    string next = "";
    rep(ii, n)
    {
      next += win(now[(ii * 2) % n], now[(ii * 2 + 1) % n]);
    }
    now = next;
  }
  cout << now[0] << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}