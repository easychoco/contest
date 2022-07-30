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
    h: i32,
    w: i32,
    mp: [Chars; h]
  }

  // 右 下 左 上
  let dy = [0, 1, 0, -1];
  let dx = [1, 0, -1, 0];

  let py = [
    [-1, -1, 0, 0, 1, 1], // 右
    [0, 0, 0, 1, 1, 1], // 下
    [-1, -1, 0, 0, 1, 1], // 左
    [-1, -1, -1, 0, 0, 0], // 上
  ];
  let px = [
    [0, 1, 0, 1, 0, 1], // 右
    [-1, 0, 1, -1, 0, 1], // 下
    [-1, 0, -1, 0, -1, 0], // 左
    [-1, 0, 1, -1, 0, 1], // 上
  ];

  let mut ans = vec![vec![100100100; w as usize]; h as usize];
  let mut que = VecDeque::<(i32, i32, i32)>::new();
  que.push_front((0, 0, 0));
  ans[0][0] = 0;
  while let Some((y, x, pt)) = que.pop_front() {
    if y == h - 1 && x == w - 1 {
      println!("{}", pt);
      break;
    }
    for i in 0..4 {
      let ny = y + dy[i];
      let nx = x + dx[i];

      if ny < 0 || h <= ny { continue; }
      if nx < 0 || w <= nx { continue; }

      let ny = ny as usize;
      let nx = nx as usize;

      if ans[ny][nx] <= pt { continue; }
      if mp[ny][nx] == '.' {
        ans[ny][nx] = pt;
        que.push_front((ny as i32, nx as i32, pt));
      } else {
        for j in 0..6 {
          let npy = ny as i32 + py[i][j];
          let npx = nx as i32 + px[i][j];

          if npy < 0 || h <= npy { continue; }
          if npx < 0 || w <= npx { continue; }

          let npy = npy as usize;
          let npx = npx as usize;
    
          if ans[npy][npx] <= pt + 1 { continue; }
          ans[npy][npx] = pt + 1;
          que.push_back((npy as i32, npx as i32, pt + 1));
        }
      }
    }
  }
}
