// https://atcoder.jp/contests/abc138/tasks/abc138_e
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
  string s, t;
  cin >> s >> t;
  vector< vector<ll> > hist(26, vector<ll>());
  ll sz = s.length();
  rep(i, sz)
  {
    hist[(s[i] - 'a')].emplace_back(i + 1);
  }

  ll loop_cnt = 0;
  ll now_pos = 0;
  rep(i, t.length())
  {
    ll ch = (t[i] - 'a');
    if (hist[ch].size() == 0) { now_pos = -1; break; }

    if (sz * loop_cnt + hist[ch].back() <= now_pos) { loop_cnt++; now_pos = sz * loop_cnt; }
    auto itr = upper_bound(ALL(hist[ch]), now_pos - sz * loop_cnt);
    now_pos = *itr + sz * loop_cnt;
  }
  cout << now_pos << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}