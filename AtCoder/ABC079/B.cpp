#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  ll lnum[87] = {2, 1};
  for(int i = 2; i <= 86; ++i)
  {
    lnum[i] = lnum[i - 1] + lnum[i - 2];
  }

  int n;
  cin >> n;
  cout << lnum[n];
}

int main()
{
  fastio;
  solve();

  return 0;
}