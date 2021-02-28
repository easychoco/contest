#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007LL // = 10^9 + 7

using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
  int n, q, a, b;
  cin >> n >> q;
  vector<P> infant(n);
  vector< multiset<P> > y(200001, multiset<P>());
  for(int i = 0; i < n; ++i)
  {
    cin >> a >> b;
    b--;
    infant[i] = P(a, b);
    y[b].insert(P(a, i));
  }

  multiset<P> ans;
  for(int i = 0; i < 200001; ++i)
  {
    if (!y[i].empty()) ans.insert(*(y[i].rbegin()));
  }

  int c, d;
  for(int i = 0; i < q; ++i)
  {
    cin >> c >> d;
    c--; d--;
    int rating = infant[c].first;
    int belong = infant[c].second;
    infant[c].second = d;
    P infa = P(rating, c);

    ans.erase(*(y[belong].rbegin()));
    if (!y[d].empty()) ans.erase(*(y[d].rbegin()));
  
    y[belong].erase(infa);
    y[d].insert(infa);

    if (!y[belong].empty()) ans.insert(*(y[belong].rbegin()));
    ans.insert(*(y[d].rbegin()));

    cout << (*ans.begin()).first << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}