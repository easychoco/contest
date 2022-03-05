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
    x: Chars,
    n: usize,
    s: [String; n]
  }
  let mut order = x
    .iter()
    .enumerate()
    .map(|(idx, val)| (val, idx))
    .collect_vec();

  order.sort_unstable();
  
  let mut t = s
    .iter()
    .enumerate()
    .map(|(idx, val)| (val.chars().map(|c| order[c as usize - 'a' as usize].1 as u8 as char).collect::<String>(), idx))
    .collect_vec();
  
  t.sort_unstable();

  for (_, idx) in t.into_iter() {
    println!("{}", s[idx]);
  }
}
