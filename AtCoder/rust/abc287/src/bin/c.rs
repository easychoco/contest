#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{input, fastout, marker::Chars, marker::Usize1};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque};

use petgraph::unionfind::UnionFind;

#[fastout]
fn main() {
  input! {
    n: usize,
    m: usize,
    uv: [(Usize1, Usize1); m]
  }

  let mut ans = "Yes";
  let mut deg = vec![0_usize; n];
  if n != m + 1 {
    ans = "No";
  }
  let mut uf = UnionFind::<usize>::new(n);
  for (u, v) in uv {
    if !uf.union(u, v) {
      ans = "No";
    }
    deg[u] += 1;
    deg[v] += 1;
    if deg[u] > 2 || deg[v] > 2 {
      ans = "No";
    }
  }
  println!("{}", ans);
}
