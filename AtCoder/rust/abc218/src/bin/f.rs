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
    st: [(usize, usize); m]
  }

  let st = st
    .into_iter()
    .map(|(s, t)| (s - 1, t - 1))
    .enumerate()
    .collect_vec();
  
  let mut graph = vec![vec![]; n];
  for &(idx, (s, t)) in st.iter() {
    graph[s].push((t, idx));
  }

  let inf = 1001001001;
  let bfs = |invalid_idx: usize| {
    // vec[(depth, from_edge_idx)]
    let mut dist = vec![(inf, 0); n];
    dist[0].0 = 0;

    let mut que = VecDeque::new();
    que.push_back(0_usize);

    while let Some(now) = que.pop_front() {
      let depth = dist[now].0;
      for &(to, idx) in graph[now].iter() {
        if idx != invalid_idx && depth + 1 < dist[to].0 {
          dist[to] = (depth + 1, idx);
          que.push_back(to);
        }
      }
    }
    dist
  };

  let dist = bfs(m);
  if dist[n - 1].0 == inf {
    for _ in 0..m {
      println!("-1");
    }
    return;
  }
  let mut shortest_path = vec![false; m];
  let mut now = n - 1;
  while now != 0 {
    let edge_idx = dist[now].1;
    shortest_path[edge_idx] = true;
    now = (st[edge_idx].1).0;
  }
  for i in 0..m {
    let mut ans = dist[n - 1].0;
    if shortest_path[i] {
      let d = bfs(i);

      ans = if d[n - 1].0 == inf {
        -1
      } else {
        d[n - 1].0
      };
    }
    println!("{}", ans);
  }
}
