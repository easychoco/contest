#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;
using P = pair<int, int>;

// 最大公約数 : 3,4 ->  1
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// 最小公倍数 : 3,4 -> 12
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve {
  int n;
  vector<int> f, primes;
  Sieve(int n=1):n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x;}
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x) {
    vector<int> fl = factorList(x);
    if (fl.size() == 0) return {};
    vector<P> res(1, P(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
  vector<pair<ll,int>> factor(ll x) {
    vector<pair<ll,int>> res;
    for (int p : primes) {
      int y = 0;
      while (x%p == 0) x /= p, ++y;
      if (y != 0) res.emplace_back(p,y);
    }
    if (x != 1) res.emplace_back(x,1);
    return res;
  }
};

void solve()
{
  int n;
  cin >> n;
  Sieve si(1000000);
  vector<int> a(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }
  vector<int> factors(1000001, 0);

  sort(ALL(a));
  vector<int> b(a);
  b.erase(unique(ALL(b)), b.end());
  for(const auto& bv : b)
  {
    for(const auto& v : si.factor(bv))
    {
      factors[v.first] = max(factors[v.first], v.second);
    }
  }

  mint m_lcm = 1;
  for(int i = 2; i <= 1000000; ++i)
  {
    mint mi = i;
    m_lcm *= mi.pow(factors[i]);
  }

  mint ans = 0;
  for(int i = 0; i < n; ++i)
  {
    mint ma = a[i];
    ans += m_lcm * ma.inv();
  } 

  cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}