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
  ll n, d1, d2;
  cin >> n;
  int num = 0;
  for(int i = 0; i < n; ++i)
  {
    cin >> d1 >> d2;
    if (d1 == d2) num++;
    else num = 0;
    if (num >= 3)
    {
      cout << "Yes";
      return;
    }
  }
  cout << "No";
}

int main()
{
  fastio;
  solve();

  return 0;
}