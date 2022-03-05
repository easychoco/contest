#[allow(unused_imports)]
use permutohedron::LexicalPermutation;
#[allow(unused_imports)]
use petgraph::{algo::is_cyclic_directed, graph::DiGraph};

fn tip_hashmap() {
  let mut mp: HashMap<usize, usize> = HashMap::new();

  // mp[key] を返す。なければ 0 で初期化する
  *mp.entry(key).or_insert(0);

  // 戻り値は value として扱える  
  *mp.entry(key).or_insert(0) += 1;
}

// a^n % mod を計算する O(log n)
fn powmod(a: i64, n: i64, m: i64) -> i64 {
  // (a ^ n) % mを計算する
  let mut ret = 1;
  let mut a = a;
  let mut n = n;
  while n > 0 {
    if n % 2 == 1 { ret =  ret * a % m }
    a = a * a % m;
    n /= 2;
  }
  ret
}

fn tip_combmod() {
  let m: i64 = 998244353;
  // let m: i64 = 1000000007;
  let sz = 400;
  let mut comb = vec![vec![0_i64; sz + 1]; sz + 1];
  comb[0][0] = 1;
  for i in 1..sz {
    comb[i][0] = 1;
    comb[i][i] = 1;
    for j in 0..i - 1 {
      comb[i][j + 1] = comb[i - 1][j] + comb[i - 1][j + 1];
      comb[i][j + 1] %= m;
    }
  }
}

fn tip_binary_search(){
  // めぐる式
  let f = |arg: i64| -> bool {
    return arg > 0;
  };
  let mut ac: i64 = 0;
  let mut wa: i64 = 1001001001001;
  while wa - ac > 1 {
    let wj: i64 = (wa + ac) / 2;
    if f(wj) { ac = wj; } else { wa = wj; }
  }
}

// 座標圧縮
// let a = compress(a) の形で使う[]
// https://atcoder.jp/contests/abc213/tasks/abc213_c
fn compress(v: Vec<usize>) -> Vec<usize> {
  let mut v = v.into_iter().enumerate().collect_vec();
  v.sort_unstable_by_key(|val| val.1);
  
  let mut now = v[0].1;
  let mut val = 0_usize;
  for (_, x) in v.iter_mut() {
    if now != *x {
      now = *x;
      val += 1;
    }
    *x = val;
  }
  v.sort_unstable();
  v.into_iter().map(|(_, x)| x).collect_vec()
}

// 最短経路に使うパスのインデックスを取得する
// cf. ABC222-E
fn tip_bfs_shortest_path() {
  let mut graph = vec![vec![]; n];
  for i in 0..n - 1 {
    let (u, v) = uv[i];
    let (u, v) = (u - 1, v - 1);
    graph[u].push((v, i));
    graph[v].push((u, i));
  }

  let inf = 1001001001;
  let mut use_count = vec![0; n - 1];

  let mut bfs_shortest_path_index = |from: usize, to: usize| {
    // prev[i] = (頂点, index)
    let mut prev = vec![(inf, inf); n];
    let mut dist = vec![inf; n];
    dist[from] = 0;

    let mut que = VecDeque::new();
    que.push_back(from);

    while let Some(now) = que.pop_front() {
      let depth = dist[now];
      if now == to { break }
      for &(next, idx) in graph[now].iter() {
        if depth + 1 < dist[next] {
          dist[next] = depth + 1;
          prev[next] = (now, idx);
          que.push_back(next);
        }
      }
    }

    let mut now = to;
    while now != from {
      use_count[prev[now].1] += 1;
      now = prev[now].0;
    }
  };
}

// topological sort
// トポロジカルソート
fn topological_sort) {
  let mut deg = vec![0; n]; // 入り次数
  let mut graph = vec![vec![]; n];
  for (mut a, mut b) in ab.into_iter() {
    a -= 1; b -= 1;
    graph[a].push(b);
    deg[b] += 1;
  }

  let mut sorted = vec![];
  let mut que = VecDeque::new();
  for v in 0..n {
    if deg[v] == 0 {
      que.push_back(v);
    }
  }
  while let Some(now) = que.pop_front() {
    sorted.push(now + 1);
    for to in graph[now].iter() {
      deg[*to] -= 1;
      if deg[*to] == 0 {
        que.push_back(*o));
      }
    }
  }
  if sorted.len() < n {
    println!("not DAG");
  }
}

// BIT
// binary indexed tree
// これは AtCoder では使えない。言語アップデート待ち。
// https://docs.rs/fenwick-tree/0.1.0/fenwick_tree/

// https://qiita.com/ngtkana/items/7d50ff180a4e5c294cb7
#[inline]
fn lsb(i: usize) -> usize {
    i & i.wrapping_neg()
}

struct Fenwick {
  table: Vec<i64>,
}
impl Fenwick {
  pub fn new(size: usize) -> Self {
      Self { table: vec![0; size] }
  }
  pub fn prefix_sum(&self, mut i: usize, m: i64) -> i64 {
    let mut res = 0;
    while i != 0 {
        res += self.table[i];
        res %= m;
        i -= lsb(i);
    }
    res
  }
  pub fn add(&mut self, mut i: usize, x: i64, m: i64) {
    i += 1;
    while i < self.table.len() {
        self.table[i] += x;
        self.table[i] %= m;
        i += lsb(i);
    }
  }
}

// UnionFind は petgraph 使ったほうがいい。 petgraph に関数がないときはこっちを使う
// https://docs.rs/petgraph/0.6.0/petgraph/unionfind/struct.UnionFind.html
// https://qiita.com/okm-uv/items/c721597792f2bb6db3b0
struct UnionFind {
  p: Vec<usize>, // 親
  rank: Vec<usize>	// サイズ・各集合の根のみ有効
}

#[allow(dead_code)]
impl UnionFind {
  fn new(size: usize) -> Self {
    UnionFind{
      p: (0..size).collect(),
      rank: vec![1; size]
    }
  }

  fn root(&mut self, x: usize) -> usize {
    if self.p[x] == x {
      x
    }
    else {
      self.p[x] = self.root(self.p[x]);
      self.p[x]
    }
  }

  fn unite(&mut self, x: usize, y: usize)  {
    let mut x = self.root(x);
    let mut y = self.root(y);
    if x == y { return /*false*/ }

    if self.rank[x] > self.rank[y] { std::mem::swap(&mut x, &mut y); }
    self.rank[y] += self.rank[x];
    self.p[x] = y;
    // true
  }

  fn root_num(self) -> usize {
    self.p.iter().enumerate().filter(|(idx, val)| idx == *val).count()
  }

  fn groups(self) -> std::collections::HashMap<usize, Vec<usize>> {
    let mut mp = std::collections::HashMap::new();
    for i in 0..self.p.len() {
      (*mp.entry(self.root(i)).or_insert(vec![])).push(i);
    }
    mp
  }

  fn size(&mut self, x: usize) -> usize {
    let root_x = self.root(x);
    self.rank[root_x]
  }

  fn same(&mut self, x: usize, y: usize) -> bool {
    self.root(x) == self.root(y)
  }
}
