#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

#define X first
#define Y second

using namespace std;
using ll = long long;
using P = pair<int, int>;

const double PI = 3.14159265358979;

P mp[90090];
ll ans[90090];

void solve()
{
  int h, w, d, inum;
  cin >> h >> w >> d;
  for(int i = 1; i <= h; ++i) for(int j = 1; j <= w; ++j)
  {
    cin >> inum;
    mp[inum] = P(j, i);
  }

  for(int i = 1; i <= d; ++i)
  {
    P now_p = mp[i];
    ll cost = 0;
    int now = i + d;
    while(now <= h * w)
    {
      P next_p = mp[now];
      cost += abs(now_p.X - next_p.X) + abs(now_p.Y - next_p.Y);
      ans[now] = cost;
      now_p = next_p;
      now += d;
    }
  }

  int q, l, r;
  cin >> q;
  for(int i = 0; i < q; ++i)
  {
    cin >> l >> r;
    cout << ans[r] - ans[l] << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}