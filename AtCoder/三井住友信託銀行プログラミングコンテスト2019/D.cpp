#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i = a;i < (ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SHOW(str,val) cout<<(str)<<" : "<<(val)<<endl;

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}

int kind[30010];

void solve()
{
  int n;
  string s;
  cin >> n >> s;
  vector< vector<int> > pos(10, vector<int>());
  for(int i = 0; i < n; ++i)
  {
    pos[s[i] - '0'].emplace_back(i);
  }
  int ans = 0;
  for(int p1 = 0; p1 < 10; ++p1)
  for(int p2 = 0; p2 < 10; ++p2)
  for(int p3 = 0; p3 < 10; ++p3)
  {
    if(pos[p1].size() * pos[p2].size() * pos[p3].size() == 0) continue;

    int i1 = pos[p1][0];
    int i3 = pos[p3].back();

    auto i2_itr = upper_bound(ALL(pos[p2]), i1);
    if (i2_itr == pos[p2].end()) continue;

    int i2 = *i2_itr;
    if (i1 < i2 && i2 < i3)
    {
      ans++;
    }
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}