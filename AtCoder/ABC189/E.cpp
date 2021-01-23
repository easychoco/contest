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

class Matrix {
protected:
  int size_y, size_x;

public:
  Matrix(int _y, int _x) {
    size_y = _y;
    size_x = _x;
    val = vector<vector<ll>>(_y, vector<ll>(_x, 0));
  }
  vector<vector<ll>> val;

  Matrix operator - () {
    for(int y = 0; y < size_y; ++y)
    for(int x = 0; x < size_x; ++x) {
      this->val[y][x] *= -1;
    }
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
    for(int y = 0; y < ret.val.size(); ++y)
    for(int x = 0; x < ret.val[0].size(); ++x) {
      for(int i = 0; i < left.x(); ++i) {
        ret.val[y][x] += left.val[y][i] * right.val[i][x];
      }
    }
    return ret;
  }
  void operator *= (Matrix right) { *this = *this * right; }

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
  void print() const {
    for(int y = 0; y < size_y; ++y) {
      for(int x = 0; x < size_x; ++x) {
        cout << val[y][x] << " ";
      }
      cout << endl;
    }
  }
};

class AffineMatrix : public Matrix {
public:
  AffineMatrix() : Matrix(3, 3){ val[2][2] = 1; }
  void operator = (Matrix other) {
    this->val = other.val;
    this->size_x = other.x();
    this->size_y = other.y();
  }
  void zoom(int _x, int _y) {
    Matrix mat = Matrix::E(3);
    mat.val[0][0] = _x;
    mat.val[1][1] = _y;
    *this = mat * (*this);
  }
  void move(int _x, int _y) {
    Matrix mat = Matrix::E(3);
    mat.val[0][2] = _x;
    mat.val[1][2] = _y;
    *this = mat * (*this);
  }
  void rotate(int _angle) { // 原点中心に反時計回り
    if (_angle == 90) {
      AffineMatrix mat;
      mat.val[0][1] = -1;
      mat.val[1][0] = 1;
      *this = mat * (*this);
    }
    else if (_angle == 180) {
      AffineMatrix mat;
      mat.val[0][0] = -1;
      mat.val[1][1] = -1;
      *this = mat * (*this);      
    }
    else if (_angle == 270) {
      AffineMatrix mat;
      mat.val[0][1] = 1;
      mat.val[1][0] = -1;
      *this = mat * (*this);      
    }
    else if (_angle == 360) {
      // do nothing
    }
    else {
      // { cos -sin   0}{ x }
      // { sin  cos   0}{ y }
      // {   0    0   1}{ 1 }
    }
    
  }
  void skew_x(int _angle) {
      // {   1  0  0}{ x }
      // { tan  1  0}{ y }
      // {   0  0  1}{ 1 }
  }
  void skew_y(int _angle) {
      // {  1  tan   0}{ x }
      // {  0    1   0}{ y }
      // {  0    0   1}{ 1 }
  }
  void flip_x() { zoom(-1, 1); }
  void flip_y() { zoom(1, -1); }
};

void solve()
{
  ll n;
  cin >> n;
  vector<tuple<ll, ll>> pos(n);
  rep(i, n)
  {
    ll x, y;
    cin >> x >> y;
    pos[i] = make_tuple(x, y);
  }

  ll m;
  cin >> m;
  vector<ll> op(m);
  vector<ll> pp(m);
  rep(i, m)
  {
    cin >> op[i];
    if (op[i] >= 3) cin >> pp[i];
  }

  ll q;
  cin >> q;
  vector<tuple<ll, ll, ll>> query(q);
  rep(i, q)
  {
    ll a, b;
    cin >> a >> b;
    b--;
    query[i] = make_tuple(a, b, i);
  }

  sort(ALL(query));

  AffineMatrix mat;
  mat = mat.E(3);
  ll qi = 0;
  vector<string> ans(q);
  rep(i, m + 1)
  {
    while(get<0>(query[qi]) <= i)
    {
      ll a, b, index;
      tie(a, b, index) = query[qi];
      Matrix p = Matrix(3, 1);
      p.val[0][0] = get<0>(pos[b]);
      p.val[1][0] = get<1>(pos[b]);
      p.val[2][0] = 1;
      p = mat * p;
      ans[index] = "" + to_string(p.val[0][0]) + " " + to_string(p.val[1][0]);
      qi++;
      if (qi >= q) break;
    }

    if (qi >= q) break;

    // 左にかける
    if (op[i] == 1)
    {
      mat.rotate(270);
    }
    if (op[i] == 2)
    {
      mat.rotate(90);
    }
    if (op[i] == 3)
    {
      mat.move(-pp[i], 0);
      mat.flip_x();
      mat.move(pp[i], 0);
    }
    if (op[i] == 4)
    {
      mat.move(0, -pp[i]);
      mat.flip_y();
      mat.move(0, pp[i]);
    }
  }
  rep(i, q) Showln(ans[i]);
}

int main()
{
  fastio;
  solve();

  return 0;
}