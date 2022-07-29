#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque};

use std::mem::swap;

fn gcd(a: i64, b: i64) -> i64 {
  if b == 0 { a }
  else { gcd(b, a % b) }
}

#[fastout]
fn main() {
  input! {
    n: usize,
    xy: [(i64, i64); n]
  }

  let mut set = HashSet::<(i64, i64)>::new();
  for i1 in 0..n {
    for i2 in i1 + 1..n {
      let dx = xy[i1].0 - xy[i2].0;
      let dy = xy[i1].1 - xy[i2].1;

      let gd = gcd(dx, dy);

      let x = dx / gd;
      let y = dy / gd;

      set.insert(( x,  y));
      set.insert((-x, -y));
    }
  }
  println!("{}", set.len());
}
