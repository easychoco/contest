#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque};

fn battle (c1: char, c2: char) -> usize {
  if c1 == c2 { return 0 }
  else if c1 == 'G' && c2 == 'C' { return 1 }
  else if c1 == 'G' && c2 == 'P' { return 2 }
  else if c1 == 'C' && c2 == 'G' { return 2 }
  else if c1 == 'C' && c2 == 'P' { return 1 }
  else if c1 == 'P' && c2 == 'G' { return 1 }
  else if c1 == 'P' && c2 == 'C' { return 2 }
  100
}

#[fastout]
fn main() {
  input! {
    n: usize,
    m: usize,
    a: [Chars; 2 * n]
  }
  let mut score = vec![(0_i32, 0_i32); 2 * n];
  for i in 0..2 * n {
    score[i].1 = i as i32;
  }

  for i in 0..m {
    for j in 0..n {
      let p1 = score[j * 2].1 as usize;
      let p2 = score[j * 2 + 1].1 as usize;

      let result = battle(a[p1][i], a[p2][i]);
      if result == 1 { score[j * 2].0 -= 1 }
      if result == 2 { score[j * 2 + 1].0 -= 1 }
    }
    score.sort();
  }
  for i in 0..n * 2 {
    println!("{}", score[i].1 + 1);
  }
}
