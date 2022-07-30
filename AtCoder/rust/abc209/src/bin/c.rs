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
    mut c: [u64; n]
  }
  c.sort();
  let MOD = 1000000007;
  let mut ans: u64 = 1;
  for i in 0..n as usize {
    ans *= c[i] - i as u64;
    ans %= MOD;
  }
  println!("{}", ans);
}
