#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=a;i<=(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void show(T& begin, T& end) { for(auto itr = begin; itr != end; ++itr) cout<<(*itr)<<" "; cout<<endl; }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<ll> dist;
  repi(i, 1, n) if (i * 2 != n) dist.emplace_back(i);

  ll idx = 0;
  reverse(ALL(dist));
  vector<bool> hist(n * 2 * 1, 0);
  vector<bool> histmod(n, 0);
  repie(i, 1, m)
  {
    while(!(i + dist[idx] <= n && !hist[i] && !hist[i + dist[idx]] && !histmod[n - dist[idx]])) idx++;
    show(i, i + dist[idx]);
    
    histmod[dist[idx]] = true;
    histmod[n - dist[idx]] = true;
    hist[i] = true;
    hist[i + dist[idx]] = true;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}