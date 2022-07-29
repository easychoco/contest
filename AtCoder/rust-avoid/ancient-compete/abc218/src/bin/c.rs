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
    n: usize,
    s: [String; n],
    t: [String; n]
  }

  // Vec<string> を Vec<Vec<char>> にする
  let mut s = s.into_iter().map(|s| s.chars().collect_vec()).collect_vec();
  let t = t.into_iter().map(|t| t.chars().collect_vec()).collect_vec();

  let mut tp = Vec::<(usize, usize)>::new();
  let mut min_ty: usize = 1001001001;
  let mut min_tx: usize = 1001001001;

  for y in 0..n {
    for x in 0..n {
      if t[y][x] == '#' {
        tp.push((y, x));
        min_tx = min(min_tx, x);
        min_ty = min(min_ty, y);
      }
    }
  }

  let tp = tp
    .into_iter()
    .map(|(y, x)| (y - min_ty, x - min_tx))
    .collect_vec();

  for _ in 0..4 {
    let mut sp = Vec::<(usize, usize)>::new();
    let mut min_sy: usize = 1001001001;
    let mut min_sx: usize = 1001001001;
    for y in 0..n {
      for x in 0..n {
        if s[y][x] == '#' {
          sp.push((y, x));
          min_sx = min(min_sx, x);
          min_sy = min(min_sy, y);
        }
      }
    }

    let sp = sp
      .into_iter()
      .map(|(y, x)| (y - min_sy, x - min_sx))
      .collect_vec();

    if sp == tp {
      println!("Yes");
      return;
    }

    let mut rot = vec![vec!['.'; n]; n];
    for y in 0..n {
      for x in 0..n {
        rot[y][x] = s[x][n - y - 1];
      }
    }
    s = rot;
  }
  println!("No");
}
