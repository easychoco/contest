#[allow(unused_imports)]
use proconio::{input, fastout, marker::Chars};
#[allow(unused_imports)]
use std::collections::{HashSet, HashMap, BTreeSet, VecDeque};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use itertools::Itertools;

#[fastout]
fn main() {
  input! {
    n: usize,
    q: usize,
    a: [u64; n],
    k: [u64; q]
  }

  let num: Vec<u64> = 
    a.into_iter()
    .enumerate()
    .map( |(i, v)| v - (i + 1) as u64)
    .collect();
 
  for i in 0..q {
    // k[i] <= num[i] を満たす最小の i
    let mut ok = 0;
    let mut ng = n;

    while ok != ng {
      let mid = (ok + ng) / 2;

      if k[i] <= num[mid] {
        ng = mid
      } else {
        ok = mid + 1
      }
    }

    println!("{}", k[i] + ok as u64);
  }
}