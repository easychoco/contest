#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars, marker::Usize1};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque};

#[fastout]
fn main() {
  input! {
    n: usize,
    m: usize,
    uv: [(Usize1, Usize1); m]
  }

  let mut graph = vec![vec![0; n]; n];
  for (u, v) in uv {
    graph[u][v] = 1;
    graph[v][u] = 1;
  }
  let mut ans = 0;
  for a in 0..n {
    for b in 0..a {
      for c in 0..b {
        ans += graph[a][b] * graph[a][c] * graph[b][c];
      }
    }
  }
  println!("{}", ans);
}
