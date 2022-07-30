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
    s1: String,
    s2: String,
    s3: String,
    s4: String,
  }
  let mut vec = vec![s1, s2, s3, s4];
  vec.sort();
  let ans = if
     vec[0] == "2B" &&
     vec[1] == "3B" &&
     vec[2] ==  "H" &&
     vec[3] == "HR"
  {
    "Yes" 
  } else { 
    "No"
  };


  // vec.dedup();
  // let ans = if vec.len() == 4 { "Yes" } else { "No" };
  // let set: HashSet<String> = vec![s1, s2, s3, s4].iter().cloned().collect();
  // let ans = if set.len() == 4 { "Yes" } else { "No" };
  println!("{}", ans);
}
