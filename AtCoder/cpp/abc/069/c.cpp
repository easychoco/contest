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
  ll n, a;
  cin >> n;
  int n2 = 0;
  int n4 = 0;
  for(int i = 0; i < n; ++i)
  {
    cin >> a;
    if (a % 4 == 0) n4++;
    else if (a % 2 == 0) n2++;
  }
  cout << ((n4 + n2 / 2 >= n / 2) ? "Yes" : "No");
}

int main()
{
  fastio;
  solve();

  return 0;
}