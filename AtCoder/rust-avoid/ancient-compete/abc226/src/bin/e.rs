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
    m: usize,
    uv: [(usize, usize); m]
  }

  if n != m {
    println!("0");
    return;
  }

  let mut graph = vec![vec![]; n];
  for i in 0..m {
    let (from, to) = uv[i];
    let from = from - 1;
    let to = to - 1;

    graph[from].push((to, i));
    graph[to].push((from, i));
  }

  let mut shown_node = vec![false; n];
  let mut shown_edge = vec![false; m];
  let m = 998244353_i64;
  let mut ans = 1_i64;
  for now in 0..n {
    if shown_node[now] { continue; }

    let mut que = VecDeque::<usize>::new();
    que.push_back(now);

    let mut node = 0;
    let mut edge = 0;

    while let Some(now) = que.pop_front() {
      if shown_node[now] { continue; }
      shown_node[now] = true;
      node += 1;
      for (to, i) in graph[now].iter() {
        if !shown_edge[*i] {
          edge += 1;
          shown_edge[*i] = true;
        }
        que.push_back(*to);
      }
    }

    if node == edge {
      ans *= 2;
      ans %= m;
    }
    else {
      ans = 0;
      break;
    }
  }
  println!("{}", ans);
}
