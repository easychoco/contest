#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque};

fn dfs(now: usize, parent: usize, graph: &Vec<Vec<usize>>) {
  print!("{} ", now + 1);

  for &next in graph[now].iter() {
    if next == parent { continue; }
    dfs(next, now, graph);
    print!("{} ", now + 1);
  }
}

#[fastout]
fn main() {
  input! {
    n: usize,
    ab: [(usize, usize); n - 1]
  }

  let mut graph = vec![vec![]; n];
  for &(a, b) in ab.iter() {
    graph[a - 1].push(b - 1);
    graph[b - 1].push(a - 1);
  }
  for i in 0..n {
    graph[i].sort();
  }
  dfs(0, 0, &graph);
}
