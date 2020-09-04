#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const double PI = 3.14159265358979;

void solve()
{
  ll n, h, ina, inb;
  cin >> n >> h;
  vector<ll> b(n);
  ll a_max = 0LL;
  for(int i = 0; i < n; ++i)
  {
    cin >> ina >> inb;
    a_max = max(a_max, ina);
    b[i] = inb;
  }

  sort(RALL(b));

  ll sum = 0;
  ll cnt = 0;
  for(const auto& bv : b)
  {
    if (bv <= a_max) break;

    sum += bv;
    cnt++;

    if (h <= sum){
      cout << cnt;
      return;
    }
  }
  cout << cnt + (h - sum - 1) / a_max + 1;
}

int main()
{
  fastio;
  solve();

  return 0;
}