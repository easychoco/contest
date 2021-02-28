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
  ll n, a;
  cin >> n;
  map<ll, ll> mp;
  for(int i = 0; i < n; ++i)
  {
    cin >> a;
    mp[a]++;
  }

  while(mp.size() > 1)
  {
    ll minx = mp.begin()->first;
    ll maxx = mp.rbegin()->first;
    mp[maxx - minx] += mp[maxx];
    mp.erase(maxx);
  }
  cout << mp.begin()->first;
}

int main()
{
  fastio;
  solve();

  return 0;
}