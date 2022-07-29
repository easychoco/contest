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
    mut edge: [(usize, usize, usize); m]
  }

  // INF で初期化した N x N の二次元配列を作る
  const INF: i64 = 1 << 60;
  let mut dist = vec![ vec![INF; n]; n];
  for i in 0..n {
    dist[i][i] = 0;
  }

  for i in 0..m {
    let (from, to, cost) = edge[i];
    dist[from - 1][to - 1] = cost as i64;
  }

  let mut ans = 0;
  for k in 0..n { // k のノードを経由する
    for from in 0..n { // 開始点
      for to in 0..n { // 終了点
        dist[from][to] = min(dist[from][to], dist[from][k] + dist[k][to]);
        if dist[from][to] != INF { ans += dist[from][to]; }
      }
    }
  }
  println!("{}", ans);
}
