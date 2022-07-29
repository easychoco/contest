#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque};

#[fastout]
fn main() {
  input! {
    n: usize,
    ab: [(usize, usize); n - 1]
  }
  
  let mut graph = vec![vec![]; n];
  for (a, b) in ab.into_iter() {
    let a = a - 1;
    let b = b - 1;
    graph[a].push(b);
    graph[b].push(a);
  }

  for v in graph.into_iter() {
    if v.len() == n - 1 {
      println!("Yes");
      return;
    }
  }
  println!("No");
}
