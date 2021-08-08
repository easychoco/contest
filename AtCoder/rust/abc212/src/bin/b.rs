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
    x: Chars
  }
  let x1 = x[0] as i32 - '0' as i32;
  let x2 = x[1] as i32 - '0' as i32;
  let x3 = x[2] as i32 - '0' as i32;
  let x4 = x[3] as i32 - '0' as i32;

  let mut ans = "Strong";
  if x1 == x2 && x2 == x3 && x3 == x4 {
    ans = "Weak";
  }
  if (x1 + 1) % 10 == x2 && 
     (x2 + 1) % 10 == x3 && 
     (x3 + 1) % 10 == x4 {
      ans = "Weak";
  }
  println!("{}", ans);
}
