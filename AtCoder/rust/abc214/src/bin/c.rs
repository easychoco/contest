#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars};
#[allow(unused_imports)]
use std::cmp::{max, min, Reverse};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque, BinaryHeap};

#[fastout]
fn main() {
  input! {
    n: usize,
    s: [usize; n],
    t: [usize; n]
  }

  let mut ans = vec![1001001001; n];
  let mut que = BinaryHeap::new();
  let t = t.into_iter().enumerate().collect_vec();
  for (idx, val) in t.into_iter() {
    que.push(Reverse((val, idx)));
  }

  while let Some(Reverse((val, idx))) = que.pop() {
    if ans[idx] > val {
      ans[idx] = val;
      que.push(Reverse((val + s[idx], (idx + 1) % n)));
    }
  }

  for i in 0..n {
    println!("{}", ans[i]);
  }
}
