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
    mut s: Chars
  }

  let s = s
    .iter()
    .map(|&c| match c {
      '6' => '9',
      '9' => '6',
       x  =>  x
    })
    .rev()
    .collect::<String>();

  println!("{}", s);
}
