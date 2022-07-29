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
    q: usize
  }

  let edge = 1001001001;
  let mut prev = vec![edge; n];
  let mut next = vec![edge; n];

  for _ in 0..q {
    input!{ v: usize }
    if v == 1 {
      input! {
        x: usize,
        y: usize 
      }
      let x = x - 1;
      let y = y - 1;
      next[x] = y;
      prev[y] = x;
    }
    
    if v == 2 {
      input! {
        x: usize,
        y: usize 
      }
      let x = x - 1;
      let y = y - 1;
      next[x] = edge;
      prev[y] = edge;
    }

    if v == 3 {
      input! { x: usize }
      let mut now = x - 1;
      while prev[now] != edge {
        now = prev[now];
      }
      let mut ans = vec![now + 1];
      while next[now] != edge {
        now = next[now];
        ans.push(now + 1);
      }
      print!("{}", ans.len());
      for v in ans.into_iter() {
        print!(" {}", v);
      }
      println!();
    }
  }
}
