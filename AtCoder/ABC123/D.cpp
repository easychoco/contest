#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

struct Cake{
  ll sum, i, j, k;
  bool operator < (const Cake& other) const
  {
    return sum < other.sum;
  }
};

void solve()
{
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x), b(y), c(z);
  for(int i = 0; i < x; ++i) cin >> a[i];
  for(int i = 0; i < y; ++i) cin >> b[i];
  for(int i = 0; i < z; ++i) cin >> c[i];
  sort(a.begin(), a.end(), greater<ll>());
  sort(b.begin(), b.end(), greater<ll>());
  sort(c.begin(), c.end(), greater<ll>());

  int cnt = 0;
  set< tuple<ll, ll, ll> > seen;

  priority_queue<Cake> que;
  que.push( Cake{a[0] + b[0] + c[0], 0, 0, 0} );
  while(cnt++, cnt <= k)
  {
    Cake now = que.top();
    que.pop();
    cout << now.sum << endl;

    if (now.i + 1 < x && seen.find(make_tuple(now.i + 1, now.j, now.k)) == seen.end())
    {
      que.push( Cake{a[now.i + 1] + b[now.j] + c[now.k], now.i + 1, now.j, now.k} );
      seen.insert( make_tuple(now.i + 1, now.j, now.k) );
    }

    if (now.j + 1 < y && seen.find(make_tuple(now.i, now.j + 1, now.k)) == seen.end())
    {
      que.push( Cake{a[now.i] + b[now.j + 1] + c[now.k], now.i, now.j + 1, now.k} );
      seen.insert( make_tuple(now.i, now.j + 1, now.k) );
    }

    if (now.k + 1 < z && seen.find(make_tuple(now.i, now.j, now.k + 1)) == seen.end())
    {
      que.push( Cake{a[now.i] + b[now.j] + c[now.k + 1], now.i, now.j, now.k + 1} );
      seen.insert( make_tuple(now.i, now.j, now.k + 1) );
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}