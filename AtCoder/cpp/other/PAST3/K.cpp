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
  ll n, q, f, t, x;
  cin >> n >> q;
  n++;
  vector<ll> desk(n); // 机の一番上にあるコンテナの番号
  vector<ll> task(n); // 各コンテナの下にあるコンテナ・机の番号
  repi(i, 1, n) desk[i] = i;
  repi(i, 1, n) task[i] = 1e6 + i;

  rep(i, q)
  {
    cin >> f >> t >> x;
    ll pf = desk[f];
    ll pt = desk[t];
    ll px = task[x];
    desk[f] = px;
    desk[t] = pf;
    task[x] = pt;
  }

  vector<ll> ans(n);
  repi(i, 1, n)
  {
    if (desk[i] == 1e6 + i) continue;
    ans[desk[i]] = i;
    ll ii = desk[i];
    while(task[ii] != 1e6 + i)
    {
      ans[task[ii]] = i;
      ii = task[ii];
    }
  }
  repi(i, 1, n) cout << ans[i] << endl;
}

int main()
{
	fastio;
	solve();

	return 0;
}