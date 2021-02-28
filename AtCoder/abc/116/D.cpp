#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  ll n, k, t, d;
  cin >> n >> k;
  vector<P> sushi(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> t >> d;
    sushi[i] = P(t, d);
  }
  sort(sushi.rbegin(), sushi.rend());

  map<ll, vector<ll>> mp;
  map<ll, ll> mp_max;
  for(const auto& s : sushi)
  {
    mp[s.first].emplace_back(s.second);
  }

  for(const auto& m : mp)
  {
    for(const auto& v : m.second)
    {
      cout << v << " ";
    }
    cout << endl;
  }

}

int main()
{
  fastio;
  solve();

  return 0;
}