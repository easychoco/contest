#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque};

use std::collections::BinaryHeap;
use std::cmp::Reverse;

#[fastout]
fn main() {
  input! {
    q: usize
  }

  let mut pool = VecDeque::new();
  let mut heap = BinaryHeap::new();
  for _ in 0..q {
    input!(n: usize);
    if n == 1 {
      input!(x: usize);
      pool.push_back(x);
    }
    if n == 2 {
      if let Some(Reverse(top)) = heap.pop() {
        println!("{}", top);
      }
      else if let Some(top) = pool.pop_front() {
        println!("{}", top);
      }
    }
    if n == 3 {
      while let Some(v) = pool.pop_front() {
        heap.push(Reverse(v));
      }
    }
  }
}
