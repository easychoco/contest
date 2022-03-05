#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque};
#[allow(unused_imports)]
use petgraph::{algo::is_cyclic_directed, graph::DiGraph};

#[fastout]
fn main() {
  input! {
    _: usize,
    m: usize,
  }
  let mut edge: Vec<(usize, usize)> = Vec::new();
  for _ in 0..m {
    input!{
      k: usize,
      a: [usize; k],
    }
    for i in 0..k - 1 {
      edge.push((a[i], a[i + 1]));
    }
  }
  let graph = DiGraph::<(), (), usize>::from_edges(&edge);
  let ans = if is_cyclic_directed(&graph) { "No" } else { "Yes" };
  println!("{}", ans);
}
