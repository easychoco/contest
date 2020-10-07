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
  ll n, q;
  cin >> n >> q;
  n++;
	vector<ll> col(n), row(n);
  rep(i, n) col[i] = row[i] = i;
  n--;

  ll que, a, b;
  bool t = false;
  rep(i, q)
  {
    cin >> que;
    if(que == 3)
    {
      t = !t;
      continue;
    }
    
    cin >> a >> b;
    if(que == 1)
    {
      if (t) swap(col[a], col[b]);
      else   swap(row[a], row[b]);
    }
    if(que == 2)
    {
      if (t) swap(row[a], row[b]);
      else   swap(col[a], col[b]);
    }
    if(que == 4)
    {
      ll ans = 0;
      // cout << row[a] << " " << row[b] << " " << col[a] << " " << col[b] << " : ";
      if (t) ans = n * (row[b] - 1) + col[a] - 1;
      else   ans = n * (row[a] - 1) + col[b] - 1;
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