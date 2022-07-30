#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque};

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
      (*mp.entry(i).or_insert(vec![])).push(i);
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

#[fastout]
fn main() {
  input! {
    n: usize,
    mut uvw: [(usize, usize, usize); n - 1]
  }

  uvw.sort_by_key(|v| v.2);
  let mut uf = UnionFind::new(n);
  let mut ans = 0;
  for (u, v, w) in uvw.into_iter() {
    let u = u - 1;
    let v = v - 1;
    ans += w * uf.size(u) * uf.size(v);
    uf.unite(u, v);
  }
  println!("{}", ans);
}
