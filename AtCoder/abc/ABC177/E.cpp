#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const double PI = 3.14159265358979;

// 最大公約数 : 3,4 ->  1
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

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
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> facs(1000010, 0);
  Sieve si(1000010);
  int cnt = 0;
  for(int i = 0; i < n; ++i)
  {
    cin >> a[i];
    if (a[i] == 1)cnt++;
  }
  sort(ALL(a));
  a.erase(unique(ALL(a)), a.end());
  ll old_n = n;
  n = a.size();

  ll check = a[0];
  for(const auto& va : a)
  {
    check = gcd(check, va);
  }

  if (check >= 2)
  {
    cout << "not coprime";
    return;
  }

  if (old_n != n)
  {
    if (cnt >= 2 && n + cnt - 1 == old_n)
    {

    }
    else
    {
      cout << "setwise coprime";
      return;
    }
    
  }

  for(const auto& va : a)
  {
    if (si.isPrime(va))
    {
      facs[va]++;
      if (facs[va] >= 2)
      {
        cout << "setwise coprime";
        return;  
      }
    }
    else
    {
      for(const auto& v : si.factor(va))
      {
        facs[v.first]++;
        if (facs[v.first] >= 2)
        {
          cout << "setwise coprime";
          return;  
        }
      }
    }
  }
  cout << "pairwise coprime";
}

int main()
{
  fastio;
  solve();

  return 0;
}