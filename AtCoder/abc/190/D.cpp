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
  ll nn;
  cin >> nn;

  if (nn == 1)
  {
    cout << "2\n";
    return;
  }

  ll n = nn;
  map<ll, ll> primes;
  ll factor = 2;
  while(factor * factor <= n)
  {
    if (n % factor == 0)
    {
      primes[factor]++;
      n /= factor;
    }
    else ++factor;
  }
  primes[n]++;

  ll ans = 1;
  for(const auto& it : primes)
  {
    if (it.first % 2 == 1) ans *= (it.second + 1);
  }
  cout << ans * 2 << endl;
  
}

int main()
{
  fastio;
  solve();

  return 0;
}