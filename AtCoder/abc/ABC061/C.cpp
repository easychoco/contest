#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const double PI = 3.14159265358979;

void solve()
{
  ll n, k, a, b;
  cin >> n >> k;
  vector<P> num(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> a >> b;
    num[i] = P(a, b);
  }
  sort(ALL(num));
  ll sum = 0;
  for(const auto& p : num)
  {
    sum += p.second;
    if (sum >= k)
    {
      cout << p.first;
      return;
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
