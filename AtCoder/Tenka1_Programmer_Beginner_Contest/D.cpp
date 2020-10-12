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
  ll n;
  cin >> n;

  ll k = 0;
  ll d = 1;
  while(k <= n)
  {
    k += d;
    d++;
    if (k != n) continue;

    ll i1 = 0;
    ll i2 = 1;
    vector< vector<ll> > s(d, vector<ll>(0));
    repi(i, 1, n+1)
    {
      s[i1].emplace_back(i);
      s[i2].emplace_back(i);
      i2++;
      if (i2 >= d)
      {
        i1++;
        i2 = i1 + 1;
      }
    }

    cout << "Yes\n" << d << "\n";
    rep(i, d)
    {
      cout << d - 1;
      for(const auto& v : s[i]) cout << " " << v;
      cout << endl;
    }
    return;
  }
  cout << "No";
}

int main()
{
  fastio;
  solve();

  return 0;
}