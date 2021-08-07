#[allow(unused_imports)]
use proconio::{input, fastout, marker::Chars};
#[allow(unused_imports)]
use std::collections::{HashSet, HashMap, BTreeSet, VecDeque};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use itertools::Itertools;

fn gcd(a: usize, b: usize) -> usize {
  if b > 0 { 
    gcd(b, a % b) 
  } else {
    a
  }
}

#[fastout]
fn main() {
  input! {
    n: usize,
    m: usize,
    mut ac: [(usize, usize); m]
  }

  let mut acc = n; // 累積 gcd
  let mut ans = 0;

  // コスト順にソートする
  // a が重複するけれど、答えには影響しないので重複除去しない
  ac.sort_by_key(|k| k.1);
  for (a, c) in ac {
    let prev = acc;
    acc = gcd(acc, a);
    ans += c * (prev - acc);
  }

  if acc != 1 {
    println!("{}", -1);
  } else {
    println!("{}", ans);
  }
}
