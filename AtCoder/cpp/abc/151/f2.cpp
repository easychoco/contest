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
using P = complex<double>;
using PL = pair<ll, ll>;
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

using LP = pair<long double, long double>;

ll sq_dist(PL a, PL b)
{
	ll dx = a.first - b.first;
	ll dy = a.second - b.second;
	return dx * dx + dy * dy;
}

long double dist(PL a, PL b)
{
	return sqrt(sq_dist(a, b));
}

bool same_line(PL a, PL b, PL c)
{
	auto [x1, y1] = a;
	auto [x2, y2] = b;
	auto [x3, y3] = c;

	ll dx1 = x1 - x2;
	ll dy1 = y1 - y2;
	ll dx2 = x2 - x3;
	ll dy2 = y2 - y3;

	// dy1 / dx1 == dy2 / dx2
	return(dy1 * dx2 == dx1 * dy2);
}

const double EPS = 1e-9;
namespace std {
	bool operator < (const P& a, const P& b) { return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b); }
	bool operator == (const P& a, const P& b) { return abs(real(a) - real(b)) < EPS && abs(imag(a) - imag(b)) < EPS; }
	P operator / (const P& a, const double& b) { return P(real(a) / b, imag(a) / b); }
	P operator * (const P& a, const double& b) { return P(real(a) * b, imag(a) * b); }
}

P center(const P& a, const P& b, const P& c) {
	P x = 1.0 / conj(b - a), y = 1.0 / conj(c - a);
	return (y - x) / (conj(x) * y - x * conj(y)) + a;
}

void solve()
{
	ll n;
	cin >> n;
	vp pos(n);
	vector<PL> pp(n);

	rep(i, n)
	{
		ll x, y;
		cin >> x >> y;
		pos[i] = P(x, y);
		pp[i] = PL(x, y);
	}

	double ans = 100000.0;

	rep(i1, n)
	rep(i2, i1)
	{
		P ce = (pos[i1] + pos[i2]) / 2.0;
		double r = abs(pos[i1] - ce);
		bool ok = true;
		rep(i, n)
		{
			if (i == i1) continue;
			if (i == i2) continue;

			// double rr = abs(pos[i] - ce) - EPS;
			// ok &= (rr <= r);

			double d = abs(pos[i] - ce);
			ok &= (r > d - EPS);
		}
		if (ok) chmin(ans, r);
	}

	rep(i1, n)
	rep(i2, i1)
	rep(i3, i2)
	{
		if (same_line(pp[i1], pp[i2], pp[i3])) continue;

		P ce = center(pos[i1], pos[i2], pos[i3]);
		double r = abs(pos[i1] - ce);

		bool ok = true;
		rep(i, n)
		{
			if (i == i1) continue;
			if (i == i2) continue;
			if (i == i3) continue;

			// double rr = abs(pos[i] - ce) - EPS;
			// ok &= (rr <= r);

			double d = abs(pos[i] - ce);
			ok &= (r > d - EPS);
		}
		if (ok) chmin(ans, r);
		// print(ans);

		// auto [x1, y1] = pos[i1];
		// auto [x2, y2] = pos[i2];
		// auto [x3, y3] = pos[i3];

		// // https://qiita.com/tydesign/items/2fd456f40f5aeeb461ff
		// long double cx = ((y1 - y2) * (x3*x3 - x1*x1 + y3*y3 - y1*y1) - (y1 - y3) * (x2*x2 - x1*x1 + y2*y2 - y1*y1)) / (long double)(2 * (x1 - x2) * (y1 - y3) - 2 * (x1 - x3) * (y1 - y2));
		// long double cy = ((x1 - x3) * (x2*x2 - x1*x1 + y2*y2 - y1*y1) - (x1 - x2) * (x3*x3 - x1*x1 + y3*y3 - y1*y1)) / (long double)(2 * (x1 - x2) * (y1 - y3) - 2 * (x1 - x3) * (y1 - y2));
		// auto center = LP(cx, cy);
		// long double r2 = sq_dist(center, pos[i1]);
		// r2 = nextafter(r2, INFINITY);
		// // print(r2);

		// bool ok = true;
		// rep(i, n)
		// {
		// 	if (i == i1) continue;
		// 	if (i == i2) continue;
		// 	if (i == i3) continue;

		// 	long double rr = sq_dist(center, pos[i]);
		// 	rr -= 1e-8;
		// 	ok &= rr <= r2;
		// }
		// if (ok) chmin(ans, sqrt(r2));
	}
	printd(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
