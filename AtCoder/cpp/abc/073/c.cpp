#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  int n, a;
  cin >> n;
  map<int, int> mp;
  for(int i = 0; i < n; ++i)
  {
    cin >> a;
    mp[a]++;
  }
  int ans = 0;
  for(const auto& m : mp)
  {
    ans += (m.second & 1);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}