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
    s: [String; 3],
    t: Chars
  }
  let mut ans = String::from("");
  for c in t.into_iter() {
    if c == '1' {
      ans += &s[0];
    }
    if c == '2' {
      ans += &s[1];
    }
    if c == '3' {
      ans += &s[2];
    }
  }
  println!("{}", ans);
}
