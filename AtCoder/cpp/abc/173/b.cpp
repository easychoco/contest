#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n;
  cin >> n;

  map<string, int> ans;
  for(int i = 0; i < n; ++i)
  {
    string s;
    cin >> s;
    ans[s]++;
  }
  cout << "AC x " << ans["AC"] << endl;
  cout << "WA x " << ans["WA"] << endl;
  cout << "TLE x " << ans["TLE"] << endl;
  cout << "RE x " << ans["RE"] << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}