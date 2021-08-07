#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=a;i<=(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<ll, ll>;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

vector<ll> ok(10, -1);
vector<ll> num, nums;
ll ans = 0;

void dfs()
{
  if (nums.size() == 4)
  {
    vector<ll> hist(10, 0);
    rep(i, 4)
    {
      hist[nums[i]]++;
    }
    bool add = true;
    rep(i, 10)
    {
      if (ok[i] == 1 && hist[i] == 0) add = false;
    }
    ans += add;
    return;
  }
  for(auto v : num)
  {
    nums.emplace_back(v);
    dfs();
    nums.erase(prev(nums.end(), 1));
  }
}

void solve()
{
  string s;
  cin >> s;
  rep(i, 10)
  {
    if (s[i] == 'o') ok[i] = 1;
    else if (s[i] == '?') ok[i] = 0;
    if (s[i] != 'x') num.emplace_back(i);
  }
  dfs();
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}