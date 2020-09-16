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
  int n, a;
  cin >> n;
  vector<int> bin(100010);
  for(int i = 0; i < n; ++i)
  {
    cin >> a;
    bin[max(0, a - 1)]++;
    bin[a + 2]--;
  }
  for(int i = 0; i < 100005; ++i)
  {
    bin[i + 1] += bin[i];
  }
  cout << *max_element(ALL(bin));

}

int main()
{
  fastio;
  solve();

  return 0;
}