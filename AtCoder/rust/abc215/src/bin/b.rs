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
    mut n: i64
  }
  let mut ans = 0;
  while n > 0 {
    n /= 2;
    ans += 1;
  }
  println!("{}", ans - 1);
}
