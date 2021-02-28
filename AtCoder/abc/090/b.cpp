#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  ll a, b;
  cin >> a >> b;
  auto f = [](ll n)
  {
    bool ret = true;
    string s = to_string(n);
    ret &= (s[0] == s[4]);
    ret &= (s[1] == s[3]);
    return ret;
  };
  int ans = 0;
  for(ll i = a; i <= b; ++i)
  {
    if(f(i))ans++;
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}