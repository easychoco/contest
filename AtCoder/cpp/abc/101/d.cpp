#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  //*
  ll n;
  cin >> n;
  while(n--, n >= 0)
  {
    int num = (n + 1);
    if (num % 10 != 9) continue;
    int a = 0;

    while(num > 0)
    {
      a += num % 10;
      num /= 10;
    }
    cout << (n + 1) << " " << a << " " << (n + 1) / (double)a << endl;
  }
  //*/

  /*
  ll n;
  cin >> n;
  int a = 1;
  int cnt = 0;

  while(n--, n >= 0)
  {
    cout << a;
    for(int i = 0; i < cnt; ++i) cout << 9;
    cout << endl;

    a++;
    if (a == 10)
    {
      cnt++;
      a = 1;
    }

  }
  //*/

}

int main()
{
  fastio;
  solve();

  return 0;
}