#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

// Segment Tree
// https://www.creativ.xyz/segment-tree-entrance-999/
// 使用関数の引数は全て1-index

// 問題ごとに設定
//--------------
// 葉の数、2の累乗数
const int N = 1 << 20;
// 演算での単位元
const ll E = 0;
// 使用する演算、非可換
ll op(ll a, ll b) { return a + b; }
//--------------

ll node[N * 2 + 1];
void init(){
  for(int i = 0; i < N * 2 + 1; ++i) node[i] = E;
}
ll get(int i) { return node[i + N - 1]; }
void update(int i, ll x)
{
  // i 番目の葉の値を x に変える
  i += N - 1; // i 番目の葉のノード番号
  node[i] = x;
  while (i > 0) {
    i = (i - 1) / 2; // ノード i の親ノードの番号に変える
    node[i] = op(node[i * 2 + 1], node[i * 2 + 2]); // 左右の子の min を計算しなおす
  }
}
ll query(int a, int b, int k, int l, int r)
{
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
	ll n, d, a, x, h;
  cin >> n >> d >> a;
  vector<P> m(n);
  init();
  for(int i = 0; i < n; ++i)
  {
    cin >> x >> h;
    m[i] = P(x, h);
  }
  sort(ALL(m));

  ll ans = 0;
  for(int now = 0; now < n; ++now)
  {
    ll now_hp = m[now].second - query(0, now + 1, 0, 0, N);
    if (now_hp <= 0) continue;
    ll num = (now_hp - 1) / a + 1LL;
    ans += num;
    ll damage = num * a;

    ll bomb_pos = m[now].first + 2LL * d;
    int idx = upper_bound(ALL(m), make_pair(bomb_pos, 1LL<<30)) - m.begin();
    // imos法
    update(now, get(now) + damage);
    update(idx, get(idx) - damage);
  }

  cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}