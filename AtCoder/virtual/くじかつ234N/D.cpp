// https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_c
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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  sort(ALL(a));
  deque<ll> deq;
  deq.push_front(a[0]);
  ll fi = 1;
  ll bi = n - 1;
  ll ans = 0;
  while(fi <= bi)
  {
    ll af = a[fi];
    ll ab = a[bi];

    ll df = deq.front();
    ll db = deq.back();

    ll ff = abs(af - df);
    ll fb = abs(af - db);
    ll bf = abs(ab - df);
    ll bb = abs(ab - db);

    ll max_dif = max({ff, fb, bf, bb});
    ans += max_dif;
    if (max_dif == ff)
    {
      deq.push_front(a[fi]);
      fi++;
    }
    else if (max_dif == fb)
    {
      deq.push_back(a[fi]);
      fi++;
    }
    else if (max_dif == bf)
    {
      deq.push_front(a[bi]);
      bi--;      
    }
    else if (max_dif == bb)
    {
      deq.push_back(a[bi]);
      bi--;
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