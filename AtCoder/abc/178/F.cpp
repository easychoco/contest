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
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  vector<ll> hist_a(n + 1, 0);
  vector<ll> hist_b(n + 1, 0);

  rep(i, n)
  {
    cin >> a[i];
    hist_a[a[i]]++;
  }
  rep(i, n)
  {
    cin >> b[i];
    hist_b[b[i]]++;
  }
  rep(i, n + 1)
  {
    if (hist_a[i] + hist_b[i] > n)
    {
      YN(0);
      return;
    }
  }

  reverse(ALL(b));

  rep(i, n)
  {
    if (a[i] == b[i])
    {
      rep(j, n)
      {
        if (b[j] != a[i])
        {
          swap(b[j], b[i]);
          break;
        }
        if (b[n - j - 1] != a[i])
        {
          swap(b[n - j - 1], b[i]);
          break;
        }
      }
    }
  }


  YN(1);
  rep(i, n) Show(b[i]);
}

int main()
{
  fastio;
  solve();

  return 0;
}