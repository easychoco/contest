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

int hist[10];

void solve()
{
  string s;
  cin >> s;

  // 8の倍数は2の倍数 ^ 3
  // 下3桁が8の倍数ならOK := 8 * 125 = 1000
  for(auto c : s)
  {
    hist[(int)(c - '0')]++;
  }

  vector<int> his(10);
  for(int i = 8; i < 1000; i+=8)
  {
    rep(j, 10) his[j] = 0;

    if (i > 100) his[i / 100]++;
    if (i > 10) his[(i / 10) % 10]++;
    his[i % 10]++;

    if (i < 100 && s.length() >= 3) his[0]++;
    if (i == 8 && s.length() >= 2) his[0]++;

    bool ok = true;
    rep(j, 10) ok &= (hist[j] >= his[j]);
    if (ok)
    {
      YN(ok);
      return;
    }
  }
  YN(false);
}

int main()
{
  fastio;
  solve();

  return 0;
}