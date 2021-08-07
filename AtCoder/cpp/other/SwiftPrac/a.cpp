#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

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
  ll k;
  cin >> s >> k;

  ll sz = s.size();

  char now = s[0];
  ll len = 0;
  vector<ll> lens;
  rep(i, sz)
  {
    if (now == s[i])
    {
      len++;
    }
    else
    {
      lens.emplace_back(len);
      len = 1;
      now = s[i];
    }
  }
  lens.emplace_back(len);
  // for(const auto& v : lens) Show(v);
  // Showln("");

  ll ans = 0;
  if (s[0] != s.back())
  {
    for(const auto& l : lens)
    {
      ans += (l / 2) * k;
    }
  }
  else
  {
    if (lens.size() == 1) ans = lens[0] * k / 2;
    else
    {
      for(int i = 1; i < lens.size() - 1; ++i) ans += (lens[i] / 2) * k;
      ans += lens[0] / 2 + lens.back() / 2;
      ans += ((lens[0] + lens.back()) / 2) * (k - 1);
    }
  }
  Showln(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}