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
    q: usize,
    ab: [(usize, usize); n - 1],
    cd: [(usize, usize); q]
  }
  // vec![初期値; 個数]
  let mut graph = vec![vec![0; 0 as usize]; n];
  for i in 0..n - 1 as usize {
    let (a, b) = ab[i];
    // 無向グラフなので、双方向の辺をつくる
    graph[a - 1].push(b - 1);
    graph[b - 1].push(a - 1);
  }

  // queue をつかって BFS をする
  // ここで stack をつかえば DFS になる
  let mut que: VecDeque<usize> = VecDeque::new();

  // 0 の街からはじめる
  que.push_back(0);

  let INF = 1 << 30;

  // 0 の街からの距離を dist に保存する
  // 0 の街 (自分自身) への距離は 0 
  let mut dist = vec![INF; n];
  dist[0] = 0;

  // que が空になるまでループする
  while let Some(now) = que.pop_front() {
    // いまは now の街にいて、now の街からいける街を for でループする
    for next in &graph[now] {
      // 借用権にひっかからないようにコピーして、ついでに shadowing する
      let next = *next;
      
      // すでに来た街かを確認して、来ていたらなにもしない
      if dist[next] != INF { continue; }
      
      // 距離を更新して、次の街に行く
      dist[next] = dist[now] + 1;
      que.push_back(next);
    }
  }

  for i in 0..q {
    let (c, d) = cd[i];
    // 距離の和 (差でも可) が偶数なら街、奇数なら道路で出会う
    let ans = if (dist[c - 1] + dist[d - 1]) % 2 == 0 { "Town" } else  { "Road" };
    println!("{}", ans);
  }
}
