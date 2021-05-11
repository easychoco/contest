#include <iostream>
#include <vector>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int x;
  cin >> x;
  vector<int> exps {1};
  for(int i = 2; i * i <= x; ++i)
  {
    int num = i * i;
    while(num <= x)
    {
      exps.emplace_back(num);
      num *= i;
    }
  }
  int ans = *std::max_element(exps.begin(), exps.end());
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}