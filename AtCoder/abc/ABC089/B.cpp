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
  char c;
  for(int i = 0; i < n; ++i)
  {
    cin >> c;
    if (c == 'Y')
    {
      cout << "Four";
      return;
    }
  }
  cout << "Three";
}

int main()
{
  fastio;
  solve();

  return 0;
}