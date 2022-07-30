#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars};
#[allow(unused_imports)]
use std::cmp::{max, min, Reverse};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque, BinaryHeap};

#[fastout]
fn main() {
  input! {
    q: usize
  }

  // 累積和 accumulate
  let mut acc: i64 = 0;
  let mut que = BinaryHeap::new();

  for _ in 0..q {
    input! { p: usize }
    if p == 1 {
      input! { x: i64 }
      // x - acc を追加する
      // 小さい方から取り出すため Reverse を使う
      que.push(Reverse(x - acc));
    } else if p == 2 {
      input! { x: i64 }
      acc += x;      
    } else {
      // 一番小さい値を出力する
      // 追加したときと逆の計算 (ans + acc) をする
      let Reverse(ans) = que.pop().unwrap();
      println!("{}", ans + acc);
    }
  }
}
