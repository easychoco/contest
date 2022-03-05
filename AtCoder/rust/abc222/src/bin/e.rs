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
    k: i64,
    a: [usize; m],
    uv: [(usize, usize); n - 1]
  }

  let mut graph = vec![vec![]; n];
  for i in 0..n - 1 {
    let (u, v) = uv[i];
    let (u, v) = (u - 1, v - 1);
    graph[u].push((v, i));
    graph[v].push((u, i));
  }

  let inf = 1001001001;
  let mut use_count = vec![0; n - 1];

  let mut bfs_shortest_path_index = |from: usize, to: usize| {
    // prev[i] = (頂点, index)
    let mut prev = vec![(inf, inf); n];
    let mut dist = vec![inf; n];
    dist[from] = 0;

    let mut que = VecDeque::new();
    que.push_back(from);

    while let Some(now) = que.pop_front() {
      let depth = dist[now];
      if now == to { break }
      for &(next, idx) in graph[now].iter() {
        if depth + 1 < dist[next] {
          dist[next] = depth + 1;
          prev[next] = (now, idx);
          que.push_back(next);
        }
      }
    }

    let mut now = to;
    while now != from {
      use_count[prev[now].1] += 1;
      now = prev[now].0;
    }
  };

  for i in 1..m {
    bfs_shortest_path_index(a[i - 1] - 1, a[i] - 1);
  }

  let m = 998244353_usize;
  use_count.sort();
  let sum: usize = use_count.iter().sum();
  let mut sumv = 0;

  if max(k, -k) as usize > sum {
    println!("{}", 0);
    return;
  }

  // dp[i] = 枝を i まで見たとき、和が j になるときの組み合わせ
  let mut dp = vec![0_usize; sum * 2 + 1_usize];
  dp[sum] = 1;
  for i in 0..n - 1 {
    let mut next_dp = vec![0_usize; sum * 2 + 1_usize];
    sumv += use_count[i];
    for j in sum - sumv..=sum + sumv {
      if j + use_count[i] <= sum * 2 {
        next_dp[j] += dp[j + use_count[i]];
        next_dp[j] %= m;
      }
      if j >= use_count[i] {
        next_dp[j] += dp[j - use_count[i]];
        next_dp[j] %= m;
      }
    }
    dp = next_dp;
  }
  println!("{}", dp[(sum as i64 + k) as usize]);
}
