#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i = a;i < (ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SHOW(str,val) cout<<(str)<<" : "<<(val)<<endl;

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}

void solve()
{
  int na, nb;
  cin >> na >> nb;
  vector<int> a(na), b(nb);
  rep(i, na) cin >> a[i];
  rep(i, nb) cin >> b[i];

  sort(ALL(a));
  sort(ALL(b));

  int both = 0;
  int all_num = 0;
  
  rep(i, na)
  {
    auto lower = lower_bound(ALL(b), a[i]);
    auto upper = upper_bound(ALL(b), a[i]);
    both += (lower != upper && lower != a.end());
  }

  all_num = na + nb - both;
  cout << setprecision(7) << (double)(both) / (double)(all_num);
  
}

int main()
{
  fastio;
  solve();

  return 0;
}