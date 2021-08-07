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
  int n, m, a, b;
  cin >> n >> m;
  vector<vector<ll>> path(n);
  for(int i = 0; i < m; ++i)
  {
    cin >> a >> b;
    a--; b--;
    path[a].emplace_back(b);
    path[b].emplace_back(a);
  }

  for(const auto& vec : path)
  {
    cout << vec.size() << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
