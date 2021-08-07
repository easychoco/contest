#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  vector<int> dish(5);
  for(int i = 0; i < 5; ++i)
  {
    cin >> dish[i];
  }
  sort(dish.begin(), dish.end(), [](auto const& l, auto const& r){
    return (l-1) % 10 > (r-1) % 10;
  });

  ll ans = 0;
  for(int i = 0; i < 4; ++i)
  {
    ans += dish[i] + (10 - (dish[i] % 10)) % 10;
  }
  ans += dish[4];
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}