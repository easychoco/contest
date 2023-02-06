#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars, marker::Usize1};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque};

#[fastout]
fn main() {
  input! {
    n: usize,
    s: [String; n]
  }
  let mut for_count = 0;
  for s_i in s {
    if s_i == "For" {
      for_count += 1;
    }
  }

  if for_count * 2 >= n {
    println!("Yes");
  } else {
    println!("No");
  }
}
