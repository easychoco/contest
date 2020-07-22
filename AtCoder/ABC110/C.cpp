#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

string trans(string s)
{
  string s_tr = string(26, '0');
  string trans_s = "";

  int now = 0;
  for(int i = 0; i < s.length(); ++i)
  {
    int ind = (int)(s[i] - 'a');
    if (s_tr[ind] == '0')
    {
      s_tr[ind] = (char)(now + 'a');
      now++;
    }
    trans_s += s_tr[ind];
  }
  return trans_s;
}

void solve()
{
  string s, t;
  cin >> s >> t;

  cout << (trans(s) == trans(t) ? "Yes" : "No");
}

int main()
{
  fastio;
  solve();

  return 0;
}