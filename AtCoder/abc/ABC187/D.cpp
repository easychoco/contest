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
  ll n;
  cin >> n;

  vector<tuple<ll, ll>> t(n);
  ll all = 0;
  rep(i, n)
  {
    ll a, b;
    cin >> a >> b;
    t[i] = make_tuple(a*2 + b, a);
    all += a;
  }

  sort(RALL(t));
  ll sum = 0;
  rep(i, n)
  {
    ll a2b, a;
    tie(a2b, a) = t[i];
    sum += a2b - a;
    all -= a;
    if (sum > all)
    {
      cout << i + 1 << endl;
      return;
    }
  }
  cout << n << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}