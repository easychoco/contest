#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  int a, b;
  string s;
  cin >> a >> b >> s;
  bool ok = true;
  for(int i = 0; i < a; ++i)
  {
    ok &= isdigit(s[i]);
  }
  ok &= (s[a] == '-');
  for(int i = 0; i < b; ++i)
  {
    ok &= isdigit(s[a + 1 + i]);
  }

  cout << (ok ? "Yes" : "No");
}

int main()
{
  fastio;
  solve();

  return 0;
}