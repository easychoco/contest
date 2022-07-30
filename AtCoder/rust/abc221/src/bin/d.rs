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
    ab: [(usize, usize); n]
  }

  let mut event: HashMap<usize, i64> = HashMap::new();

  for (a, b) in ab.into_iter() {
    *event.entry(a).or_insert(0) += 1;
    *event.entry(a + b).or_insert(0) -= 1;
  }

  let mut event: Vec<(usize, i64)> = event.into_iter().collect();
  event.sort();
  
  let mut prev = 0;
  let mut now_val = 0;
  let mut ans = vec![0; n + 1];
  for (key, val) in event.into_iter() {
    ans[now_val as usize] += key - prev;
    now_val += val;
    prev = key;
  }
  for i in 1..=n {
    print!("{}", ans[i]);
    print!("{}", if i == n { '\n' } else { ' ' });
  }
}
