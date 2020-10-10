#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i = a;i < (ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SHOW(str,val) cout<<(str)<<" : "<<(val)<<endl;

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}

void solve()
{
	int n, q;
  string s;
  cin >> n >> s >> q;
  vector< set<int> > pos(26);
  rep(i, n) pos[(int)(s[i] - 'a')].insert(i);

  int ia, ib, ic;
  char cc;
  rep(i, q)
  {
    cin >> ia;
    if (ia == 1)
    {
      cin >> ib >> cc;
      ib--;
      pos[(int)(s[ib] - 'a')].erase(ib);
      pos[(int)(cc - 'a')].insert(ib);
      s[ib] = cc;
    }
    if (ia == 2)
    {
      cin >> ib >> ic;
      ib--; ic--;
      int ans = 0;
      rep(j, 26)
      {
        if (pos[j].empty()) continue;
        auto itr = pos[j].lower_bound(ib);
        ans += (itr != pos[j].end() && *itr <= ic);
      }
      cout << ans << endl;
    }
  }
}

int main()
{
	fastio;
	solve();

	return 0;
}