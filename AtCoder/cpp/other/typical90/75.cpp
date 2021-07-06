#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=a;i<=(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<ll, ll>;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

// 素数判定
bool isPrime(ll a) {
  if (a == 1) return false;
  for (ll i = 2; i * i <= a; i++) {
    if(a % i == 0) return false;
  }
  return true;
}

void solve()
{
  ll n;
  cin >> n;

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

  ll ans = 0;
  ll sum = 0;
  for(auto mp : primes)
  {
    sum += mp.second;
  }
  sum--;
  while(sum > 0)
  {
    sum /= 2;
    ans++;
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}