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

void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) { cin >> a[i]; a[i] %= 200; }

  // map<mod, idx>
  map<ll, vector<ll>> mp;
  rep(i, n)
  {
    map<ll, vector<ll>> next = mp;
    for(auto m : mp)
    {
      if (next[(m.first + a[i]) % 200].size() > 0)
      {
        YN(true);
        cout << next[(m.first + a[i]) % 200].size() << " ";
        for(auto ai : next[(m.first + a[i]) % 200]) cout << ai + 1 << " ";
        cout << endl;
        cout << next[m.first].size() + 1 << " ";
        for (auto bi : next[m.first]) cout << bi + 1 << " ";
        cout << i + 1 << endl;
        return;
      }
      next[(m.first + a[i]) % 200] = m.second;
      next[(m.first + a[i]) % 200].emplace_back(i);
    }
    if (next[a[i]].size() > 0)
    {
      YN(true);
      cout << next[a[i]].size() << " ";
      for(auto ai : next[a[i]]) cout << ai + 1 << " ";
      cout << endl;
      cout << 1 << " " << i + 1 << endl;
      return;
    }
    next[a[i]].emplace_back(i);
    mp = next;
  }
  YN(false);
}

int main()
{
  fastio;
  solve();

  return 0;
}