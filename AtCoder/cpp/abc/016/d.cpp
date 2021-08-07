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

#define X first
#define Y second

ll cross(P v1, P v2)
{
  return v1.X * v2.Y - v1.Y * v2.X;
}

bool isCross(P f1, P t1, P f2, P t2)
{
  P vec1 = P(t1.X - f1.X, t1.Y - f1.Y);
  P vec2 = P(f2.X - f1.X, f2.Y - f1.Y);
  P vec3 = P(t2.X - f1.X, t2.Y - f1.Y);
  return ((cross(vec1, vec2) < 0) != (cross(vec1, vec3) < 0));
}

void solve()
{
  ll ax, ay, bx, by, n;
  cin >> ax >> ay >> bx >> by >> n;
  vector<ll> x(n + 1), y(n + 1);
  rep(i, n) cin >> x[i] >> y[i];
  x[n] = x[0];
  y[n] = y[0];

  P lf = P(ax, ay); // line from
  P lt = P(bx, by);

  ll cnt = 0;
  rep(i, n)
  {
    P ef = P(x[i], y[i]); // edge from
    P et = P(x[i + 1], y[i + 1]);
    bool ok = isCross(lf, lt, ef, et);
    ok &= isCross(ef, et, lf, lt);
    cnt += ok;
  }
  
  cout << 2 + (cnt - 2) / 2 << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}