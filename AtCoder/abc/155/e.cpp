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
	string s;
  cin >> s;
  s = '0' + s;

  // mat[i][j] = iを作るのに必要な数字
  vector<int> mat{ 0, 1, 2, 3, 4, 5, 14, 13, 12, 11};

  const int INF = 1<<30;

  // ちょうど払う
  vector<ll> score_tight(s.length() + 1, INF);
  // 多く払う
  vector<ll> score_more(s.length() + 1, INF);

  score_tight[0] = 0;
  rep(i, s.length())
  {
    int num = (s[i] - '0');

    score_tight[i + 1] = min({
      score_tight[i + 1],
      score_tight[i] + num,
      score_more[i]  + 10 - num,
    });

    score_more[i + 1] = min({
      score_more[i + 1],
      score_tight[i] + 1 + num,
      score_more[i]  + 9 - num,
    });
  }

  cout << score_tight[s.length()] << endl;
}

int main()
{
	fastio;
	solve();

	return 0;
}