#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

int imos[32][100005];
int ians[100005];

void solve()
{
  int n, c, is, it, ic;
  cin >> n >> c;
  for(int i = 0; i < n; ++i)
  {
    cin >> is >> it >> ic;
     ic--;
    imos[ic][is - 1]++;
    imos[ic][it]--;
  }

  for(int ci = 0; ci < c; ++ci)
  {
    for(int i = 0; i <= 100000; ++i)
    {
      imos[ci][i + 1] = imos[ci][i] + imos[ci][i + 1];
      imos[ci][i] = min(1, imos[ci][i]);
      ians[i] += imos[ci][i];
    }
  }

  int ans = 0;
  for(int i = 0; i <= 100000; ++i)
  {
    ans = max(ans, ians[i]);
  }

  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}