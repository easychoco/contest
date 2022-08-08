#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=(a);i<(ll)(n);++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=(a);i<=(ll)(n);++i)
#define rrep(i,n) rrepi(i,n,0)
#define rrepi(i,n,a) for(ll i=(n);i>=(ll)(a);--i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define pb push_back
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vs = vector<string>;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<long double, long double>;
using vp = vector<P>;
using vvp = vector<vp>;
using T = tuple<ll, ll, ll>;
using vt = vector<T>;
const ll INF = 1LL << 60;
void YN(bool a, string whenT="Yes", string whenF="No") { cout << (a ? whenT : whenF) << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void print() { cout << endl; }
template <class T>
void print(T &&t){ cout << t << endl; }
template <class Head, class... Tail>
void print(Head &&head, Tail &&...tail){ cout << head << " "; print(std::forward<Tail>(tail)...); }
void printd(long double d) { cout << std::fixed << setprecision(13) << d << endl; }
template <class T>
inline void printv(T &v){ for (auto a : v) print(a); }
template <class T>
inline void printp(T &p){ for (auto [a, b] : p) print(a, b); }
template <class T>
inline void printt(T &t){ for (auto [a, b, c] : t) print(a, b, c); }
void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head&& head, Tail&&... tail){ cerr << head << " "; debug(std::forward<Tail>(tail)...); }

long double sq_dist(P a, P b)
{
	long double dx = a.first - b.first;
	long double dy = a.second - b.second;
	return dx * dx + dy * dy;
}

long double dist(P a, P b)
{
	return sqrt(sq_dist(a, b));
}

bool same_line(P a, P b, P c)
{
	auto [x1, y1] = a;
	auto [x2, y2] = b;
	auto [x3, y3] = c;

	long double dx1 = x1 - x2;
	long double dy1 = y1 - y2;
	long double dx2 = x2 - x3;
	long double dy2 = y2 - y3;

	return abs(dy1 / dx1 - dy2 / dx2) < 1e-8;
}

void solve()
{
	ll n;
	cin >> n;
	vp pos(n);
	rep(i, n)
	{
		long double x, y;
		cin >> x >> y;
		pos[i] = P(x, y);
	}

	long double ans = INFINITY;
	rep(i1, n)
	rep(i2, i1)
	{
		{ // 2点を通る最小の円の場合も試してみる
			auto ce = [&](P a, P b)
			{
				long double x = (a.first + b.first) / 2.0;
				long double y = (a.second + b.second) / 2.0;
				return P(x, y);
			};

			long double r2 = sq_dist(pos[i1], pos[i2]) / 4.0;
			P center = ce(pos[i1], pos[i2]);

			bool ok = true;
			rep(i, n)
			{
				if (i == i1) continue;
				if (i == i2) continue;

				long double rr = sq_dist(center, pos[i]);
				ok &= rr - 1e-8 <= r2;
			}
			if (ok) chmin(ans, sqrt(r2));
		}

		rep(i3, i2)
		{
			if (same_line(pos[i1], pos[i2], pos[i3])) continue;

			auto [x1, y1] = pos[i1];
			auto [x2, y2] = pos[i2];
			auto [x3, y3] = pos[i3];

			// https://qiita.com/tydesign/items/2fd456f40f5aeeb461ff
			long double cx = ((y1 - y2) * (x3*x3 - x1*x1 + y3*y3 - y1*y1) - (y1 - y3) * (x2*x2 - x1*x1 + y2*y2 - y1*y1)) / (long double)(2.0 * (x1 - x2) * (y1 - y3) - 2.0 * (x1 - x3) * (y1 - y2));
			long double cy = ((x1 - x3) * (x2*x2 - x1*x1 + y2*y2 - y1*y1) - (x1 - x2) * (x3*x3 - x1*x1 + y3*y3 - y1*y1)) / (long double)(2.0 * (x1 - x2) * (y1 - y3) - 2.0 * (x1 - x3) * (y1 - y2));
			auto center = P(cx, cy);
			long double r2 = sq_dist(center, pos[i1]);

			bool ok = true;
			rep(i, n)
			{
				if (i == i1) continue;
				if (i == i2) continue;
				if (i == i3) continue;

				long double rr = sq_dist(center, pos[i]);
				ok &= rr - 1e-8 <= r2;
			}
			if (ok) chmin(ans, sqrt(r2));
		}
	}
	printd(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
