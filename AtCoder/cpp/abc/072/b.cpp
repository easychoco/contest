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
  for(int i = 0; i < s.length(); i += 2)
  {
    cout << s[i];
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}