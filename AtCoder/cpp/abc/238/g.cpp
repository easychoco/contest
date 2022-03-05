#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=(a);i<(ll)(n);++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=(a);i<=(ll)(n);++i)
#define rrep(i,n) rrepi(i,n,0)
#define rrepi(i,n,a) for(ll i=(n);i>=(a);--i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define pb push_back
#define eb emplace_back

using namespace std;
using namespace atcoder;
using vb = vector<bool>;
using vvb = vector<vb>;
using ll = int_fast64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
using T = tuple<ll, ll, ll>;
using vt = vector<T>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void print() { cout << endl; }
template <class Head, class... Tail>
void print(Head &&head, Tail &&...tail){ cout << head << " "; print(std::forward<Tail>(tail)...); }
void printd(double d) { cout << std::fixed << setprecision(13) << d << endl; }
template <class T>
inline void printv(T &v){ for (auto a : v) print(a); }
template <class T>
inline void printvp(T &p){ for (auto [a, b] : p) print(a, b); }
template <class T>
inline void printvt(T &t){ for (auto [a, b, c] : t) print(a, b, c); }
void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head&& head, Tail&&... tail){ cerr << head << " "; debug(std::forward<Tail>(tail)...); }

ll toi(ll p){
  if (p == 2) return 0;
  if (p == 3) return 1;
  if (p == 5) return 2;
  if (p == 7) return 3;
  if (p == 11) return 4;
  if (p == 13) return 5;
  if (p == 17) return 6;
  if (p == 19) return 7;
  if (p == 23) return 8;
  if (p == 29) return 9;
  if (p == 31) return 10;
  if (p == 37) return 11;
  if (p == 41) return 12;
  if (p == 43) return 13;
  if (p == 47) return 14;
  if (p == 53) return 15;
  if (p == 59) return 16;
  if (p == 61) return 17;
  if (p == 67) return 18;
  if (p == 71) return 19;
  if (p == 73) return 20;
  if (p == 79) return 21;
  if (p == 83) return 22;
  if (p == 89) return 23;
  if (p == 97) return 24;
  if (p == 101) return 25;
  if (p == 103) return 26;
  if (p == 107) return 27;
  if (p == 109) return 28;
  if (p == 113) return 29;
  if (p == 127) return 30;
  if (p == 131) return 31;
  if (p == 137) return 32;
  if (p == 139) return 33;
  if (p == 149) return 34;
  if (p == 151) return 35;
  if (p == 157) return 36;
  if (p == 163) return 37;
  if (p == 167) return 38;
  if (p == 173) return 39;
  if (p == 179) return 40;
  if (p == 181) return 41;
  if (p == 191) return 42;
  if (p == 193) return 43;
  if (p == 197) return 44;
  if (p == 199) return 45;
  if (p == 211) return 46;
  if (p == 223) return 47;
  if (p == 227) return 48;
  if (p == 229) return 49;
  if (p == 233) return 50;
  if (p == 239) return 51;
  if (p == 241) return 52;
  if (p == 251) return 53;
  if (p == 257) return 54;
  if (p == 263) return 55;
  if (p == 269) return 56;
  if (p == 271) return 57;
  if (p == 277) return 58;
  if (p == 281) return 59;
  if (p == 283) return 60;
  if (p == 293) return 61;
  if (p == 307) return 62;
  if (p == 311) return 63;
  if (p == 313) return 64;
  if (p == 317) return 65;
  if (p == 331) return 66;
  if (p == 337) return 67;
  if (p == 347) return 68;
  if (p == 349) return 69;
  if (p == 353) return 70;
  if (p == 359) return 71;
  if (p == 367) return 72;
  if (p == 373) return 73;
  if (p == 379) return 74;
  if (p == 383) return 75;
  if (p == 389) return 76;
  if (p == 397) return 77;
  if (p == 401) return 78;
  if (p == 409) return 79;
  if (p == 419) return 80;
  if (p == 421) return 81;
  if (p == 431) return 82;
  if (p == 433) return 83;
  if (p == 439) return 84;
  if (p == 443) return 85;
  if (p == 449) return 86;
  if (p == 457) return 87;
  if (p == 461) return 88;
  if (p == 463) return 89;
  if (p == 467) return 90;
  if (p == 479) return 91;
  if (p == 487) return 92;
  if (p == 491) return 93;
  if (p == 499) return 94;
  if (p == 503) return 95;
  if (p == 509) return 96;
  if (p == 521) return 97;
  if (p == 523) return 98;
  if (p == 541) return 99;
  if (p == 547) return 100;
  if (p == 557) return 101;
  if (p == 563) return 102;
  if (p == 569) return 103;
  if (p == 571) return 104;
  if (p == 577) return 105;
  if (p == 587) return 106;
  if (p == 593) return 107;
  if (p == 599) return 108;
  if (p == 601) return 109;
  if (p == 607) return 110;
  if (p == 613) return 111;
  if (p == 617) return 112;
  if (p == 619) return 113;
  if (p == 631) return 114;
  if (p == 641) return 115;
  if (p == 643) return 116;
  if (p == 647) return 117;
  if (p == 653) return 118;
  if (p == 659) return 119;
  if (p == 661) return 120;
  if (p == 673) return 121;
  if (p == 677) return 122;
  if (p == 683) return 123;
  if (p == 691) return 124;
  if (p == 701) return 125;
  if (p == 709) return 126;
  if (p == 719) return 127;
  if (p == 727) return 128;
  if (p == 733) return 129;
  if (p == 739) return 130;
  if (p == 743) return 131;
  if (p == 751) return 132;
  if (p == 757) return 133;
  if (p == 761) return 134;
  if (p == 769) return 135;
  if (p == 773) return 136;
  if (p == 787) return 137;
  if (p == 797) return 138;
  if (p == 809) return 139;
  if (p == 811) return 140;
  if (p == 821) return 141;
  if (p == 823) return 142;
  if (p == 827) return 143;
  if (p == 829) return 144;
  if (p == 839) return 145;
  if (p == 853) return 146;
  if (p == 857) return 147;
  if (p == 859) return 148;
  if (p == 863) return 149;
  if (p == 877) return 150;
  if (p == 881) return 151;
  if (p == 883) return 152;
  if (p == 887) return 153;
  if (p == 907) return 154;
  if (p == 911) return 155;
  if (p == 919) return 156;
  if (p == 929) return 157;
  if (p == 937) return 158;
  if (p == 941) return 159;
  if (p == 947) return 160;
  if (p == 953) return 161;
  if (p == 967) return 162;
  if (p == 971) return 163;
  if (p == 977) return 164;
  if (p == 983) return 165;
  if (p == 991) return 166;
  if (p == 997) return 167;
  return -1000;
}

// セグメント木
// https://www.creativ.xyz/segment-tree-entrance-999/
// 使用関数の引数は全て1-index
// query() は半開区間
// ===================  問題ごとに設定 ====================
// !!使う前に init() を呼ぶ!!
const int N = 1 << 18;              // 葉の数、2の累乗数
const vl E(169, 0);                     // 演算での単位元
vl op(vl a, vl b) { vl ret = E; rep(i, 169) ret[i] = a[i] + b[i]; return ret; } // 使用する演算、可換
// =======================================================
vl node[N * 2 + 1];
void init(){
  for(int i = 0; i < N * 2 + 1; ++i) node[i] = E;
}
vl get(int i) { return node[i + N - 1]; }
void update(int i, vl x){ // i 番目の葉の値を x に変える
  i += N - 1; // i 番目の葉のノード番号
  node[i] = x;
  while (i > 0) {
    i = (i - 1) / 2; // ノード i の親ノードの番号に変える
    node[i] = op(node[i * 2 + 1], node[i * 2 + 2]); // 左右の子の値を計算しなおす
  }
}
vl query(int a, int b, int k = 0, int l = 0, int r = N){
  // [a, b) の区間に対するクエリについてノード k （区間 [l, r) 担当）が答える
  if (r <= a || b <= l) return E; // 区間が被らない場合は単位元を返す
  if (a <= l && r <= b) return node[k]; // ノード k の担当範囲がクエリ区間 [a, b) に完全に含まれる
  // 一部だけ範囲が被る場合は左右の子に委託する
  vl c1 = query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子に値を聞く
  vl c2 = query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子に値を聞く
  return op(c1, c2);
}

void solve()
{
  init();

  ll n, q;
  cin >> n >> q;
  rep(i, n)
  {
    ll num;
    cin >> num;
    map<ll, ll> primes;
    ll factor = 2;
    while(factor * factor <= num)
    {
      if (num % factor == 0)
      {
        primes[factor]++;
        num /= factor;
      }
      else ++factor;
    }
    primes[num]++;

    vl val = E;
    for (const auto& v : primes)
    {
      val[toi(v.first)] += v.second;
    }
    update(i + 1, val);
  }

  rep(_, q)
  {
    ll l, r;
    cin >> l >> r;
    vl v = query(l, r + 1);
    bool ok = true;
    rep(i, 169) ok &= (v[i] % 3 == 0);
    YN(ok);
  }

}

int main()
{
  fastio;
  solve();

  return 0;
}
