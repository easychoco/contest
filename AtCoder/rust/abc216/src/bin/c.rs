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
    mut n: usize
  }
  let mut ans = String::new();
  while n > 1 {
    if n % 2 == 1 {
      ans += "A";
    }
    ans += "B";
    n /= 2;
  }
  ans += "A";
  let mut reversed = String::new();
  for c in ans.chars() {
    reversed = String::from(c.to_string() + &reversed);
  }
  println!("{}", reversed);
}
