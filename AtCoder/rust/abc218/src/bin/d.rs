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
    mut xy: [(usize, usize); n]
  }

  xy.sort_unstable();

  let mut st = HashSet::<(usize, usize)>::new();
  for v in xy.iter() {
    st.insert(*v);
  }

  let mut ans = 0;
  for i in 0..n {
    let (xi, yi) = xy[i];
    for j in i + 1..n {
      let (xj, yj) = xy[j];

      if xi < xj && yi < yj {
        if let Some(_) = st.get(&(xi, yj)) {
          if let Some(_) = st.get(&(xj, yi)) {
            ans += 1;
          }
        }
      }
    }
  }
  println!("{}", ans);
}
