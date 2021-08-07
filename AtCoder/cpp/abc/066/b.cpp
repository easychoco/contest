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
  string s;
  cin >> s;
  for(int i = s.length() - 2; i >= 0; i -= 2)
  {
    string sub = s.substr(0, i);
    bool ok = true;
    for(int j = 0; j < i / 2; ++j)
    {
      ok &= sub[j] == sub[i / 2 + j];
    }
    if(ok)
    {
      cout << i;
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