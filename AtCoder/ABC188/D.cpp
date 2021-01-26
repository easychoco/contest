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
  ll n, cost;
  cin >> n >> cost;
  map<ll, ll> a;
  map<ll, ll> b;
  rep(i, n)
  {
    ll ai, bi, ci;
    cin >> ai >> bi >> ci;
    a[ai] += ci;
    b[bi] += ci;
  }

  auto itr_a = a.begin();
  auto itr_b = b.begin();

  ll ans = 0;
  ll now = 0;
  ll sum = 0;

  while(true)
  {
    if (itr_a == a.end() && itr_b == b.end()) break;

    ll na = 1LL<<60;
    ll nb = 1LL<<60;
    if (itr_a != a.end()) na = itr_a->first;
    if (itr_b != b.end()) nb = itr_b->first;
    
    if (na <= nb)
    {
      ans += min(sum, cost) * (na - now);
      now = na;
      sum += itr_a->second;
      itr_a++;
    }
    else // if (na > nb)
    {
      ans += min(sum, cost) * (nb - now + 1);
      now = nb + 1;
      sum -= itr_b->second;
      itr_b++;
    }
    // Show(now); Show(na); Show(nb); Showln(ans);
  }
  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}