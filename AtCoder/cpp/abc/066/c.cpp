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
  ll n;
  cin >> n;
  vector<ll> a(n);
  bool front = true;
  for(int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }

  for(int i = n - 1; i >= 0; i -= 2) cout << a[i] << " ";
  for(int i = (n & 1); i < n; i += 2) cout << a[i] << " ";
}

int main()
{
  fastio;
  solve();

  return 0;
}