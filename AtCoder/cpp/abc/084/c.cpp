#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  int n;
  cin >> n;
  int now = 0;
  vector<int> ans(n, 0);
  int c, s, f;
  for(int i = 0; i < n - 1; ++i)
  {
    cin >> c >> s >> f;
    for(int j = 0; j <= i; ++j)
    {
      ans[j] = max(ans[j], s);
      if (ans[j] % f > 0) ans[j] += f - (ans[j] % f);
      ans[j] += c;
    }
  }

  for(const auto& a : ans)
  {
    cout << a << endl;
  }

}

int main()
{
  fastio;
  solve();

  return 0;
}