#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars};
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
    abc: [(usize, usize, i64); m]
  }

  let mut cab = abc
    .into_iter()
    .map(|(a, b, c)| (c, a - 1, b - 1))
    .collect_vec();

  cab.sort_unstable();

  let mut ans: i64 = cab
    .iter()
    .map(|(c, _, _)| c)
    .sum();

  let mut uf = UnionFind::<usize>::new(n);
  for (cost, from, to) in cab.into_iter() {
    if !uf.equiv(from, to) {
      uf.union(from, to);
      ans -= cost;
    } else if cost < 0 {
      ans -= cost;
    }
  }
  println!("{}", ans);
}
