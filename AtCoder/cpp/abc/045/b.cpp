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
  string sa, sb, sc;
  cin >> sa >> sb >> sc;

  int ia = 1, ib = 0, ic = 0;
  char now = sa[0];
  while(1)
  {
    // Show(ia); Show(ib); Show(ic); Showln(now);
    if (now == 'a') { if (ia >= sa.length()){ cout << "A" << endl; return;} now = sa[ia++]; }
    else if (now == 'b') { if (ib >= sb.length()){ cout << "B" << endl; return;} now = sb[ib++]; }
    else if (now == 'c') { if (ic >= sc.length()){ cout << "C" << endl; return;} now = sc[ic++]; }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}