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
  string s, t;
  cin >> s >> t;
  string ans = s;
  bool ok = false;
  for(int i = s.length() - 1; i >= 0; --i)
  {
    bool in = true;
    for(int j = t.length() - 1; j >= 0; --j)
    {
      if (i + j >= s.length())
      {
        in = false;
        break;
      }
      in &= (s[i + j] == t[j] || s[i + j] == '?');
    }
    if (in)
    {
      for(int j = 0; j < t.length(); ++j)
      {
        ans[i + j] = t[j];
      }
      ok = true;
      break;
    }
  }
  for(int i = 0; i < ans.length(); ++i)
  {
    if (ans[i] == '?') ans[i] = 'a';
  }
  cout << (ok ? ans : "UNRESTORABLE");
}

int main()
{
  fastio;
  solve();

  return 0;
}