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
    num: String
  }
  let v: Vec<i32> = num
    .split('.')
    .map(|x| x.parse().unwrap())
    .collect_vec();
  
  if v[1] <= 2 { println!("{}-", v[0]) }
  else if 7 <= v[1] { println!("{}+", v[0]) }
  else { println!("{}", v[0]) }
}
