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

void solve()
{
  int a, b;
  cin >> a >> b;
  vector<string> ans(100, string(100, '.'));

  int h = 0, w = 0;
  if (a == 1 && b == 1) ans[0][0] = '#';
  else if (a == 1) b++;
  a--;
  b--;

  while(a--)
  {
    ans[h + 1][w] = '#';
    ans[h][w + 1] = '#';
    ans[h + 1][w + 1] = '#';
    w += 2;
    if (w >= 100)
    {
      w = 0;
      h += 2;
    }
  }
  while(b--)
  {
    ans[h + 1][w + 1] = '#';
    w += 2;
    if (w >= 100)
    {
      w = 0;
      h += 2;
    }
  }

  cout << "100 100\n";
  for(const auto& s : ans) cout << s << endl;

}

int main()
{
  fastio;
  solve();

  return 0;
}