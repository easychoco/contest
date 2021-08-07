#[allow(unused_imports)]
use proconio::{input, fastout, marker::Chars};
#[allow(unused_imports)]
use std::collections::{HashSet, HashMap, BTreeSet, VecDeque};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use itertools::Itertools;

#[fastout]
fn main() {
  input! {
    n: usize,
    m: usize,
    ab: [(usize, usize); m]
  }
  let mut graph = vec![vec![0; 0]; n];
  for (mut a, mut b) in ab {
    a -= 1;
    b -= 1;
    graph[a].push(b);
    graph[b].push(a);
  }

  let m = 1000000007;
  let mut dp = vec![0_i32; n];
  let mut dist = vec![0; n];
  let mut que = VecDeque::<usize>::new();
  dp[0] = 1;
  dist[0] = 0;
  que.push_back(0);
  while let Some(now) = que.pop_front() {
    // BFS なので、初めて now に着いたときは最短経路になっている
    // now についたあとで que に残っているものは最短経路ではないので、この枝刈りができる
    if now == n - 1 { break }

    for &next in graph[now].iter() {
      if dist[next] == 0 {
        // 初めて来たとき
        dist[next] = dist[now] + 1;
        que.push_back(next);
        dp[next] += dp[now];
      } else if dist[next] == dist[now] + 1 {
        // 別のノードから最短経路で合流したとき
        dp[next] += dp[now];
      }
      dp[next] %= m;
    }
  }
  println!("{}", dp[n - 1]);
}
