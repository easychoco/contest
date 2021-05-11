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
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;

  string ss = s1 + s2 + s3;
  sort(ALL(ss));
  ss.erase(unique(ALL(ss)), ss.end());

  if (ss.length() > 10)
  {
    show("UNSOLVABLE");
    return;
  }

  ss += string(10 - ss.length(), (char)('z' + 1));

  vector<ll> mp(28, 0);
  do {
    rep(i, 10) mp[(int)(ss[i] - 'a')] = i;

    if (mp[(int)(s1[0] - 'a')] == 0) continue;
    if (mp[(int)(s2[0] - 'a')] == 0) continue;
    if (mp[(int)(s3[0] - 'a')] == 0) continue;

    ll sum1, sum2, sum3;
    sum1 = sum2 = sum3 = 0;

    rep(i, s1.length()){ sum1 = sum1 * 10 + mp[(int)(s1[i] - 'a')]; }
    rep(i, s2.length()){ sum2 = sum2 * 10 + mp[(int)(s2[i] - 'a')]; }
    rep(i, s3.length()){ sum3 = sum3 * 10 + mp[(int)(s3[i] - 'a')]; }

    if (sum1 + sum2 == sum3)
    {
      show(sum1); show(sum2); show(sum3);
      return;
    }

  } while(next_permutation(ALL(ss))); 

  show("UNSOLVABLE");
}

int main()
{
  fastio;
  solve();

  return 0;
}