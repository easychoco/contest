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
  ll n;
  cin >> n;
  vector<ll> p(n);
  vector<ll> pos(n);

  rep(i, n)
  {
    cin >> p[i];
    p[i]--;
    pos[p[i]] = i;
  }

  vector<ll> ans;
  vector<bool> used(n - 1, false);
  rep(i, n)
  {
    for(int j = pos[i] - 1; j >= i; --j)
    {
      if (used[j])
      {
        cout << "-1\n";
        return;
      }
      swap(p[j], p[j + 1]);
      pos[p[j]] = j;
      pos[p[j + 1]] = j + 1;
      ans.emplace_back(j + 1);
      used[j] = true;
    }
  }

  if (ans.size() != n - 1)
  {
    cout << "-1\n";
  }
  else
  {
    rep(i, n - 1) Showln(ans[i]);
  }
  
}

int main()
{
  fastio;
  solve();

  return 0;
}