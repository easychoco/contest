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

// https://www.creativ.xyz/segment-tree-entrance-999/
// 使用関数の引数は全て1-index
// query() は半開区間
// ===================  問題ごとに設定 ====================
// !!使う前に init() を呼ぶ!!
const int N = 1 << 19;              // 葉の数、2の累乗数
bitset<26> E(0);                     // 演算での単位元
bitset<26> op(bitset<26> a, bitset<26> b) { return bitset<26>(a | b); } // 使用する演算、可換
// =======================================================
vector<bitset<26>> node(N * 2 + 1, bitset<26>(0));
//ll node[N * 2 + 1];
void init(){
  for(int i = 0; i < N * 2 + 1; ++i) node[i] = E;
}
ll get(int i) { return node[i + N - 1].count(); }
void update(int i, ll x){ // i 番目の葉の値を x に変える
  i += N - 1; // i 番目の葉のノード番号
  node[i] = bitset<26>(1<<x);
  while (i > 0) {
    i = (i - 1) / 2; // ノード i の親ノードの番号に変える
    node[i] = op(node[i * 2 + 1], node[i * 2 + 2]); // 左右の子の値を計算しなおす
  }
}
bitset<26> query(int a, int b, int k = 0, int l = 0, int r = N){
  // [a, b) の区間に対するクエリについてノード k （区間 [l, r) 担当）が答える
  if (r <= a || b <= l) return E; // 区間が被らない場合は単位元を返す
  if (a <= l && r <= b) return node[k]; // ノード k の担当範囲がクエリ区間 [a, b) に完全に含まれる
  // 一部だけ範囲が被る場合は左右の子に委託する
  bitset<26> c1 = query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子に値を聞く
  bitset<26> c2 = query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子に値を聞く
  return op(c1, c2);
}

void solve()
{
	int n, q;
  string s;
  cin >> n >> s >> q;
  init();
  rep(i, n) update(i + 1, (ll)(s[i] - 'a'));

  int ia, ii, ic;
  char cc;
  rep(i, q)
  {
    cin >> ia;
    if(ia == 1) 
    {
      cin >> ii >> cc;
      update(ii, (ll)(cc - 'a'));
    }
    if (ia == 2)
    {
      cin >> ii >> ic;
      auto que = query(ii, ic + 1);
      cout << que.count() << endl;
    }
  }
}

int main()
{
	fastio;
	solve();

	return 0;
}