#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n + 2);
  int sum = 0;
  a[0] = 0;
  a.back() = 0;
  for(int i = 1; i <= n; ++i)
  {
    cin >> a[i];
    sum += abs(a[i] - a[i - 1]);
  }
  sum += abs(a[n]);

  for(int i = 1; i <= n; ++i)
  {
    if (
      (a[i - 1] <= a[i] && a[i] <= a[i + 1]) ||
      (a[i - 1] >= a[i] && a[i] >= a[i + 1])
    )
    {
      cout << sum << endl;
    }
    else
    {
      cout << sum - min(abs(a[i] - a[i - 1]), abs(a[i] - a[i + 1])) * 2  << endl;
    }
    
  }

}

int main()
{
  fastio;
  solve();

  return 0;
}