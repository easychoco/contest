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
  string s;
  cin >> s;
  bool seen[26] = {};
  for(const auto& c : s)
  {
    seen[c - 'a'] = true;
  }
  for(int i = 0; i < 26; ++i)
  {
    if (!seen[i])
    {
      cout << (char)(i + 'a');
      return;
    }
  }
  cout << "None";
}

int main()
{
  fastio;
  solve();

  return 0;
}