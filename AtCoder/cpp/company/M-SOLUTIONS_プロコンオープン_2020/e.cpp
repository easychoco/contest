#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  ll n, x_in, y_in, p_in;
  cin >> n;
  vector<tuple<ll, ll, ll>> city;
  for(int i = 0; i < n; ++i)
  {
    cin >> x_in >> y_in >> p_in;
    city[i] = make_tuple(x_in, y_in, p_in);
  }

  


}

int main()
{
  fastio;
  solve();

  return 0;
}