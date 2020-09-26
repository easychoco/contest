#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;

void solve()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  vector< vector<ll> > edge(n, vector<ll>(0));
  for(int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }

  for(int i = 0; i < n; ++i)
  {
    for(int j = i + 1; j < n; ++j)
    {
      int cnt = 0;
      if (abs(a[i] - a[j]) <= k) 
      {
        edge[i].emplace_back(j);
        cnt++;
        if (cnt > 100) break;
      }
    }
  }

  vector<ll> dist(n, 1);
  for(int i = 0; i < n; ++i)
  {
    for(const auto& v : edge[i])
    {
      dist[v] = max(dist[v], dist[i] + 1LL);
    }
  }
  cout << *max_element(ALL(dist));
}

int main()
{
  fastio;
  solve();

  return 0;
}