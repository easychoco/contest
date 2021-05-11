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

// 最大公約数 : 3,4 ->  1
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// 最小公倍数 : 3,4 -> 12
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

void solve()
{
  ll t1, t2, a1, a2, b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

  ll dis_a1 = t1 * a1;
  ll dis_a2 = dis_a1 + t2 * a2;

  ll dis_b1 = t1 * b1;
  ll dis_b2 = dis_b1 + t2 * b2;

  if (dis_a2 == dis_b2)
  {
    cout << "infinity";
    return;
  }

  // dis_b2 < dis_a2 にする
  if (dis_a2 < dis_b2)
  {
    swap(dis_a1, dis_b1);
    swap(dis_a2, dis_b2);
  }

  // 1回も会わない
  if (dis_a1 > dis_b1)
  {
    cout << 0;
    return;
  }

  // dis_b2 < dis_a2
  // かつ
  // dis_a1 < dis_b1

  // 1ループあたりに開く距離
  // この距離だけaのスタート位置が増える
  ll diff = dis_a2 - dis_b2;
  ll diff_half = dis_b1 - dis_a1;

  // グラフ書いて試してみるとわかりやすかった......!!
  ll meet_num = ((diff_half - 1) / diff + 1);
  ll ans = 2 * meet_num - 1;

  if (diff_half % diff == 0) ans++;
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}