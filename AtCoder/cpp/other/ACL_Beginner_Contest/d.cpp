#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;

// Segment Tree
// https://www.creativ.xyz/segment-tree-entrance-999/
// 使用関数の引数は全て1-index
// ===================  問題ごとに設定 ====================
const int N = 1 << 22;              // 葉の数、2の累乗数
const ll E = 0;                     // 演算での単位元
ll op(ll a, ll b) { return max(a, b); } // 使用する演算、非可換
// !!使う前に init() を呼ぶ!!
// =======================================================
ll node[N * 2 + 1];
void init(){
  for(int i = 0; i < N * 2 + 1; ++i) node[i] = E;
}
ll get(int i) { return node[i + N - 1]; }
void update(int i, ll x){ // i 番目の葉の値を x に変える
  i += N - 1; // i 番目の葉のノード番号
  node[i] = x;
  while (i > 0) {
    i = (i - 1) / 2; // ノード i の親ノードの番号に変える
    node[i] = op(node[i * 2 + 1], node[i * 2 + 2]); // 左右の子の min を計算しなおす
  }
}
ll query(int a, int b, int k = 0, int l = 0, int r = N){
  // [a, b) の区間に対するクエリについてノード k （区間 [l, r) 担当）が答える
  if (r <= a || b <= l) return E; // 区間が被らない場合は単位元を返す
  if (a <= l && r <= b) return node[k]; // ノード k の担当範囲がクエリ区間 [a, b) に完全に含まれる
  // 一部だけ範囲が被る場合は左右の子に委託する
  ll c1 = query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子に値を聞く
  ll c2 = query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子に値を聞く
  return op(c1, c2);
}

void solve()
{
  ll n, k;
  cin >> n >> k;
  init();
  vector<ll> a(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }

  for(int i = 0; i < n; ++i)
  {
    ll le = max(0LL, a[i] - k);
    ll re = min(a[i] + k, 300000LL);
    ll score = query(le, re + 1);
    update(a[i], score + 1);
  }
  cout << query(0, N);
}

int main()
{
  fastio;
  solve();

  return 0;
}