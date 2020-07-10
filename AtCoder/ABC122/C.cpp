#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<int> cnt(n + 1, 0);
  for(int i = 1; i < n; ++i)
  {
    if (s[i - 1] == 'A' && s[i] == 'C') { cnt[i + 1]++; }
    cnt[i + 1] += cnt[i];
  }
  int l, r;
  for(int i = 0; i < q; ++i)
  {
    cin >> l >> r;
    cout << cnt[r] - cnt[l] << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}