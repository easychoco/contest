#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int s;
  cin >> s;
  
  int ind = 1;

  set<int> st;
  st.insert(s);

  while(true)
  {
    ind++;
    s = ((s & 1) ? 3 * s + 1 : s / 2);
    if (st.find(s) != st.end())
    {
      cout << ind;
      return;
    }
    st.insert(s);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}