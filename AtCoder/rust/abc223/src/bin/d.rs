#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque};

use std::collections::BinaryHeap;
use std::cmp::Reverse;

#[fastout]
fn main() {
  input! {
    n: usize,
    m: usize,
    ab: [(usize, usize); m]
  }

  let mut deg = vec![0; n]; // 入り次数
  let mut graph = vec![vec![]; n];
  for (mut a, mut b) in ab.into_iter() {
    a -= 1; b -= 1;
    graph[a].push(b);
    deg[b] += 1;
  }

  let mut sorted = vec![];
  let mut que = BinaryHeap::new();
  for v in 0..n {
    if deg[v] == 0 {
      que.push(Reverse(v));
    }
  }
  while let Some(Reverse(now)) = que.pop() {
    sorted.push(now + 1);
    for to in graph[now].iter() {
      deg[*to] -= 1;
      if deg[*to] == 0 {
        que.push(Reverse(*to));
      }
    }
  }

  if sorted.len() < n {
    println!("-1");
  } else {
    for i in 0..n {
      println!("{}", sorted[i]);
    }
  }
}
