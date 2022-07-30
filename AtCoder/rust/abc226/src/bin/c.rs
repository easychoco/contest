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
    n: usize
  }
  let mut t = Vec::<usize>::new();
  let mut graph = vec![vec![]; n];
  for i in 0..n {
    input! {
      _t: usize,
      k: usize,
      a: [usize; k]
    }
    t.push(_t);
    for to in a.into_iter() {
      graph[i].push(to - 1);
    }
  }

  let mut ans = 0;
  let mut come = vec![false; n];

  let mut que = VecDeque::new();
  que.push_back(n - 1);

  while let Some(now) = que.pop_front() {
    if come[now] { continue }
    ans += t[now];
    come[now] = true;
    for to in graph[now].iter() {
      que.push_back(*to);
    }
  }
  println!("{}", ans);
}
