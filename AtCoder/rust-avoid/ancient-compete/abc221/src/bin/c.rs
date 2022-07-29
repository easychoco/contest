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
    n: Chars
  }

  let mut ans = 0;
  for mask in 0..1 << n.len() {
    let mut s = vec![];
    let mut t = vec![];
    for i in 0..n.len()
    {
      if (mask >> i & 1) == 1 { s.push(n[i]) }
      else { t.push(n[i]) }
    }
    s.sort();
    t.sort();
    let s = s.iter().rev().collect::<String>().parse::<usize>().unwrap_or(0);
    let t = t.iter().rev().collect::<String>().parse::<usize>().unwrap_or(0);
    ans = max(ans, s * t);
  }
  println!("{}", ans);
}
