#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque};

fn compress(v: Vec<usize>) -> Vec<usize> {
  let mut v = v.into_iter()
               .enumerate()
               .sorted_by_key(|val| val.1)
               .collect_vec();
  
  let mut now = v[0].1;
  let mut val = 0_usize;
  for (_, x) in v.iter_mut() {
    if now != *x {
      now = *x;
      val += 1;
    }
    *x = val;
  }
  v.sort();
  v.into_iter().map(|(_, x)| x).collect_vec()
}

#[fastout]
fn main() {
  input! {
    _: usize,
    _: usize,
    n: usize,
    ab: [(usize, usize); n]
  }

  let mut a = Vec::with_capacity(n);
  let mut b = Vec::with_capacity(n);
  for (_a, _b) in ab.into_iter() {
    a.push(_a);
    b.push(_b);
  }

  let a = compress(a);
  let b = compress(b);

  for i in 0..n {
    println!("{} {}", a[i] + 1, b[i] + 1);
  }
}
