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
  int n, k, a;
  cin >> n >> k;
  vector<ll> bin(n, 0);
  map<ll, ll> mp;
  for(int i = 0; i < n; ++i)
  {
    cin >> a;
    a--;
    bin[a]++;
  }
  bin.erase(remove(ALL(bin), 0), bin.end());
  sort(ALL(bin));
  cout << accumulate(bin.begin(), bin.begin() + max(0, (int)bin.size() - k), 0LL);
}

int main()
{
  fastio;
  solve();

  return 0;
}