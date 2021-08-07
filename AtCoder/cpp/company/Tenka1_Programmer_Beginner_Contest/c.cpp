#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

// 8:08~8:46

void solve()
{
  int n, a_input;
  cin >> n;
  deque<int> a;
  for(int i = 0; i < n; ++i)
  {
    cin >> a_input;
    a.push_back(a_input);
  }
  sort(a.begin(), a.end());

  ll ans = 0;
  deque<int> b;
  b.push_back(a.back());
  a.pop_back();
  while(!a.empty())
  {
    ll af = a.front();
    ll ab = a.back();
    ll bf = b.front();
    ll bb = b.back();

    ll dff = abs(af - bf);
    ll dfb = abs(af - bb);
    ll dbf = abs(ab - bf);
    ll dbb = abs(ab - bb);
    ll dmax = max({dff, dfb, dbf, dbb});

    if (dmax == dff)
    {
      b.push_front(af);
      a.pop_front();
    }
    else if (dmax == dfb)
    {
      b.push_back(af);
      a.pop_front();
    }
    else if (dmax == dbf)
    {
      b.push_front(ab);
      a.pop_back();
    }
    else if (dmax == dbb)
    {
      b.push_back(ab);
      a.pop_back();
    }
    ans += dmax;
  }

  cout << ans;

}

int main()
{
  fastio;
  solve();

  return 0;
}