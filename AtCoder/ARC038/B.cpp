#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define Show(val) cout<<(val)<<" "
#define Showln(val) cout<<(val)<<endl

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void solve()
{
  ll h, w;
  cin >> h >> w;
  vector<string> s(h + 1);
  rep(i, h) { cin >> s[i]; s[i] += "#"; }
  s[h] = string(w + 1, '#');

  vector< vector<int> > score(h, vector<int>(w, 0));

  for(int i = h-1; i >= 0; i -= 2)
  for(int j = w-1; j >= 0; j -= 2)
  {
    for(int y = max(0, i - 1); y <= i; ++y){
      for(int x = max(0, j - 1); x <= j; ++x){
        if (s[y][x] == '.' && s[y+1][x+1] == '#' && s[y+1][x] == '#' && s[y][x+1] == '#')
        {
          score[y][x] = 1;
          if (y >= 1) s[y-1][x] = '#';
          if (x >= 1) s[y][x-1] = '#';
          if (x >= 1 && y >= 1) s[y-1][x-1] = '#';
        }
      }
    }
  }
  
  if (h == 1 && w == 1) cout << "Second";
  else if (h == 1) cout << ((score[0][1] == 1) ? "First" : "Second");
  else if (w == 1) cout << ((score[1][0] == 1) ? "First" : "Second");
  else if (score[1][0] == 1 || score[0][1] == 1 || score[1][1] == 1) cout << "First";
  else cout << "Second";
  cout << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}