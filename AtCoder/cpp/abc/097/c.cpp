//#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  string s;
  int k;
  cin >> s >> k;
  set<char> ana;
  for(const char& c : s) ana.insert(c);

  vector<string> subset;
  for(const char c : ana)
  {
    for(int i = 0; i < s.length(); ++i)
    {
      if (s[i] == c)
      {
        for(int j = 1; i + j <= min((int)s.length(), i + k); ++j)
        {
          subset.emplace_back(s.substr(i, j));
        }
      }
    }
    if (subset.size() >= k)
    {
      sort(subset.begin(), subset.end());
      subset.erase( unique(subset.begin(), subset.end()), subset.end() );

      if (subset.size() >= k)
      {
        cout << subset[k - 1];
        return;
      }
    }
  }



}

int main()
{
  fastio;
  solve();

  return 0;
}