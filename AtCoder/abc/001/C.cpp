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

void solve(ll deg, ll dis)
{
  // 60でわって小数第二位を四捨五入
  dis *= 10;
  int spd = (dis / 6 + 5) / 10;

  if (spd <= 2)
  {
    cout << "C 0\n";
    return;
  }

  if (113 <= deg && deg <=337) Show("NNE");
  else if (337 < deg && deg <= 562) Show("NE");
  else if (562 < deg && deg <= 787) Show("ENE");
  else if (787 < deg && deg <= 1012) Show("E");
  else if (1012 < deg && deg <= 1237) Show("ESE");
  else if (1237 < deg && deg <= 1462) Show("SE");
  else if (1462 < deg && deg <= 1687) Show("SSE");
  else if (1687 < deg && deg <= 1912) Show("S");
  else if (1912 < deg && deg <= 2137) Show("SSW");
  else if (2137 < deg && deg <= 2362) Show("SW");
  else if (2362 < deg && deg <= 2587) Show("WSW");
  else if (2587 < deg && deg <= 2812) Show("W");
  else if (2812 < deg && deg <= 3037) Show("WNW");
  else if (3037 < deg && deg <= 3262) Show("NW");
  else if (3262 < deg && deg <= 3487) Show("NNW");
  else Show("N");

  if (spd <= 15) Showln("1");
  else if (spd <= 33) Showln("2");
  else if (spd <= 54) Showln("3");
  else if (spd <= 79) Showln("4");
  else if (spd <= 107) Showln("5");
  else if (spd <= 138) Showln("6");
  else if (spd <= 171) Showln("7");
  else if (spd <= 207) Showln("8");
  else if (spd <= 244) Showln("9");
  else if (spd <= 284) Showln("10");
  else if (spd <= 326) Showln("11");
  else Showln("12");
}

int main()
{
  fastio;

  ll deg, dis;
  cin >> deg >> dis;

  solve(deg, dis);

  return 0;
}