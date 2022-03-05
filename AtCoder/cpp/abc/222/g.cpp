#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=(a);i<(ll)(n);++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=(a);i<=(ll)(n);++i)
#define rrep(i,n) rrepi(i,n,0)
#define rrepi(i,n,a) for(ll i=(n);i>=(a);--i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

void solve()
{
  ll t;
  cin >> t;
  rep(_, t)
  {
    ll n;
    cin >> n;
    if (n % 2 == 0) n /= 2;
    if (n % 5 == 0)
    {
      show(-1);
      continue;
    }

    if (n == 1)
    {
      show(1);
      continue;
    }

    ll num = n;
    map<ll, ll> primes;
    ll factor = 2;
    while(factor * factor <= num)
    {
      if (num % factor == 0)
      {
        primes[factor]++;
        num /= factor;
      }
      else ++factor;
    }
    primes[num]++;

    ll ans = (--primes.end())->first - 1;
    show(ans);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
