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
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for(int i = 0; i < h; ++i)
  {
    cin >> a[i];
    a[i] = '#' + a[i] + '#';
  }

  cout << string(w + 2, '#') << endl;
  for(const auto s : a) cout << s << endl;
  cout << string(w + 2, '#');
}

int main()
{
  fastio;
  solve();

  return 0;
}