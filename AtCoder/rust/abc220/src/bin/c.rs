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
    n: i64,
    a: [i64; n],
    mut x: i64
  }
  let sum: i64 = a.iter().sum();
  let mut ans = (x / sum) * n;
  x %= sum;
  for v in a.iter() {
    ans += 1;
    x -= v;
    if x < 0 {
      break;
    }
  }
  println!("{}", ans);
}
