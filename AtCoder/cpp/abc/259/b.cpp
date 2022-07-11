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
using P = pair<ll, ll>;
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
void printd(double d) { cout << std::fixed << setprecision(13) << d << endl; }
template <class T>
inline void printv(T &v){ for (auto a : v) print(a); }
template <class T>
inline void printp(T &p){ for (auto [a, b] : p) print(a, b); }
template <class T>
inline void printt(T &t){ for (auto [a, b, c] : t) print(a, b, c); }
void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head&& head, Tail&&... tail){ cerr << head << " "; debug(std::forward<Tail>(tail)...); }

// 行列クラス
// - 任意のサイズの行列同士の演算[+][-][x]
// - Matrix::E(int n) でn次単位行列
// - .val[][] で要素にアクセス
template<class T>
class Matrix {
protected:
  int size_y, size_x;

public:
  Matrix(int _y, int _x) {
    size_y = _y;
    size_x = _x;
    val = vector<vector<T>>(_y, vector<T>(_x, 0));
  }
  vector<vector<T>> val;

  Matrix operator - () {
    for(int y = 0; y < size_y; ++y)
    for(int x = 0; x < size_x; ++x) {
      this->val[y][x] *= -1;
    }
    return *this;
  }
  Matrix operator + (Matrix right) const {
    auto left = *this;
    if (!same_size(&right)) {
      cerr << "invalid size" << endl;
      return E(1);
    }

    auto ret = Matrix(size_y, size_x);
    for(int y = 0; y < size_y; ++y)
    for(int x = 0; x < size_x; ++x) {
      ret.val[y][x] = left.val[y][x] + right.val[y][x];
    }
    return ret;
  }
  Matrix operator - (Matrix right) const {
    return (*this + -right);
  }
  void operator += (Matrix right) { *this = *this + right; }
  void operator -= (Matrix right) { *this = *this - right; }
  Matrix operator * (Matrix right) const {
    auto left = *this;
    if (left.x() != right.y()) {
      cerr << "invalid size" << endl;
      return E(1);
    }

    auto ret = Matrix(left.y(), right.x());
    for(int y = 0; y < left.y(); ++y)
    for(int x = 0; x < right.x(); ++x) {
      for(int i = 0; i < left.x(); ++i) {
        ret.val[y][x] += left.val[y][i] * right.val[i][x];
      }
    }
    return ret;
  }
  void operator *= (Matrix right) { *this = *this * right; }

  // 2x1 をまわす
  // それ以外は弾いていない
  void rotate(int angle) {
    angle %= 360;
    double cs = cos(M_PI / 180.0 * (double)angle);
    double sn = sin(M_PI / 180.0 * (double)angle);
    Matrix<T> left = E(2);
    left.val[0][0] = cs;
    left.val[0][1] = -sn;
    left.val[1][0] = sn;
    left.val[1][1] = cs;
    *this = left * *this;
  }

  static Matrix E(int _size) {// ::演算子でアクセス
    auto ret = Matrix(_size, _size);
    for(int i = 0; i < _size; ++i) {
      ret.val[i][i] = 1;
    }
    return ret;
  }
  int x() const { return this->size_x; }
  int y() const { return this->size_y; }
  bool same_size(Matrix* other) const { return ((this->x() == other->x()) && (this->y() == other->y())); }
  void show() const {
    for(int y = 0; y < size_y; ++y) {
      for(int x = 0; x < size_x; ++x) {
        cout << std::fixed << setprecision(13) << val[y][x];
        if (x < size_x - 1) cout << " ";
      }
      cout << endl;
    }
  }
};

void solve()
{
  double x, y, d;
  cin >> x >> y >> d;
  auto mt = Matrix<double>(2, 1);
  mt.val[0][0] = x;
  mt.val[1][0] = y;
  mt.rotate(d);
  mt.show();
}

int main()
{
  fastio;
  solve();

  return 0;
}
