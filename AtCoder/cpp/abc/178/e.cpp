#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define X first
#define Y second

using namespace std;
using ll = long long;
using P = pair<int, int>;

const double PI = 3.14159265358979;

void solve()
{
  ll n, x, y;
  cin >> n;
  vector<ll> d1(n);
  vector<ll> d2(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> x >> y;
    d1[i] = x + y;
    d2[i] = x - y;
  }
  sort(ALL(d1));
  sort(ALL(d2));
  cout << max(d1.back() - d1[0], d2.back() - d2[0]);
}

int main()
{
  fastio;
  solve();

  return 0;
}
