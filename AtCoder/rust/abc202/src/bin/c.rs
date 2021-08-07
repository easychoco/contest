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
    a: [usize; n],
    b: [usize; n],
    c: [usize; n],
  }

  let mut hist = vec![0; n + 1];
  for i in 0..n {
    hist[b[c[i] - 1]] += 1;
  }
  
  let mut ans: i64 = 0;
  for i in 0..n {
    ans += hist[a[i]];
  }
  println!("{}", ans);
}
