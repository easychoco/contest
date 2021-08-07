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
  ll n, k;
  cin >> n >> k;
  int d[8][8];
  rep(i, n) rep(j, n) cin >> d[i][j];

  vector<ll> perm(n);
  iota(ALL(perm), 0LL);
  ll ans = 0;
  do {
    ll dist = 0;
    rep(i, n - 1) dist += d[perm[i]][perm[i+1]];
    dist += d[perm.back()][perm[0]];

    if (dist == k) ans++;
  } while(next_permutation(ALL(perm)));
  cout << ans / n << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}