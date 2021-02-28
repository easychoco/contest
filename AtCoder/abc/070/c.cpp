#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

// 最大公約数 : 3,4 ->  1
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

void solve()
{
  ll n, t;
  cin >> n;
  map<ll, ll> mp;
  ll l = 1;
  for(int i = 0; i < n; ++i)
  {
    cin >> t;
    ll g = gcd(l, t);
    l /= g;
    l *= t;
  }
  cout << l;
}

int main()
{
  fastio;
  solve();

  return 0;
}