// https://atcoder.jp/contests/abc137/tasks/abc137_d
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
  ll n, m, a, b;
  cin >> n >> m;
  vector<tuple<ll, ll>> task(n);
  rep(i, n)
  {
    cin >> a >> b;
    task[i] = make_tuple(a, b);
  }

  sort(ALL(task));

  ll ans = 0;
  int ti = 0;
  priority_queue<int> que;
  repi(i, 1, m + 1)
  {
    // mからi日前
    if (ti < n)
    while(get<0>(task[ti]) <= i)
    {
      que.push(get<1>(task[ti]));
      ti++;
      if (ti >= n) break;
    }
    
    if(que.empty()) continue;
    ans += que.top();
    que.pop();
  }
  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}