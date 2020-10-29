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
  int n, k, c;
  string s;
  cin >> n >> k >> c >> s;

  ll cnt = 0;
  vector<bool> may(n, false);
  vector<ll> must;
  rep(i, n)
  {
    if (s[i] == 'o')
    {
      may[i] = true;
      i += c;
      cnt++;
    }
  }
  if (cnt > k) return;
  for(int i = n - 1; i >= 0; --i)
  {
    if (s[i] == 'o')
    {
      if (may[i])
      {
        must.emplace_back(i);
      }
      i -= c;
    }
  }
  for(int i = must.size() - 1; i >= 0; --i) Showln(must[i] + 1);
}

int main()
{
	fastio;
	solve();

	return 0;
}