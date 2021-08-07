#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  ll n, m, p, y;
  cin >> n >> m;
  vector<P> a(m);
  map<P, int> ump;
  map<int, map<int, P> > mp;
  for(int i = 0; i < m; ++i)
  {
    cin >> p >> y;
    P ind = P(p, y);
    a[i] = ind;
    ump[ind] = i;
    mp[p][y] = ind;
  }

  for(const auto& ip : mp)
  {
    int ind = 1;
    for(const auto& im : ip.second)
    {
      a[ump[im.second]].second = ind;
      ind++;
    }
  }

  cout << setfill('0') << right;
  for(const auto& city : a)
  {
    cout << setw(6) << city.first << setw(6) << city.second << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}