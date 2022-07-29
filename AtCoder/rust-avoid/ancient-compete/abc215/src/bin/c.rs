#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque};
use permutohedron::LexicalPermutation;

#[fastout]
fn main() {
  input! {
    s: Chars,
    k: usize
  }
  let mut t = s;
  t.sort_unstable();

  if k == 1 {
    for c in t {
      print!("{}", c);
    }
    return;
  }

  let mut cnt = 1;
  while t.next_permutation() {
    cnt += 1;
    if k == cnt {
      break;
    }
  }

  for c in t {
    print!("{}", c);
  }
}
