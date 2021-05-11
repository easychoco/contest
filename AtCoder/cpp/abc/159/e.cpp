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
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  vector<vector<int>> white(h, vector<int>(w, 0));
  rep(i, h) cin >> s[i];
  rep(i, h) rep(j, w) white[i][j] = (int)(s[i][j] == '1');

  int ans = 200000;
  for(int i = 0; i < (1<<h); ++i)
  {
    int tmp = 0;
    int num = 0;
    vector<int> cut(h);
    cut[0] = 0;
    for(int j = 1; j < h; ++j)
    {
      if ( ((i & (1<<j)) > 0) != ((i & (1<<(j-1))) > 0) )
      {
        tmp++;
        num++;
      }
      cut[j] = num;
    }

    vector<int> count(num + 1, 0);
    int last_cut_w = -1;
    rep(j, w)
    {
      int max_white = 0;
      rep(i, h)
      {
        count[cut[i]] += white[i][j];
        chmax(max_white, count[cut[i]]);
      }
      if (max_white > k)
      {
        tmp++;
        if (last_cut_w == j - 1) 
        {
          tmp = 202020;
          break;
        }
        j--;
        last_cut_w = j - 1;
        fill(ALL(count), 0);
      }
    }
    chmin(ans, tmp);
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}