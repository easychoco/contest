#[allow(unused_imports)]
use proconio::{input, fastout, marker::Chars};
#[allow(unused_imports)]
use std::collections::{HashSet, HashMap, BTreeSet, VecDeque};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use itertools::Itertools;

fn c_to_usize(c: char) -> usize {
  // a: 97 / A : 65
  // println!("a: {} / A : {}", 'a' as usize, 'A' as usize);
  if c.is_ascii_lowercase() {
    c as usize - 97 + 26
  } else {
    c as usize - 65
  }
}

fn s_to_usize(s: &[char]) -> usize {
  s.iter()
   .map(|&c| c_to_usize(c))
   .fold(0, |digit, c| digit * 52 + c)
}

#[fastout]
fn main() {
  input! {
    n: usize,
    s: [Chars; n]
  }

  let MAX_N: usize = 52 * 52 * 52;
  let mut graph_rev = vec![vec![0; 0 as usize]; MAX_N];
  let mut in_degree_rev = vec![0; MAX_N];
  let mut ans = vec![0; MAX_N];
  let mut input_tail_idx = vec![0; n];

  for (i, s) in s.into_iter().enumerate() {
    let head_idx = s_to_usize(&s[0..3]);
    let tail_idx = s_to_usize(&s[s.len() - 3..]);

    // 後退解析をするので、逆向きに辺を張る
    graph_rev[tail_idx].push(head_idx);
    // 入り次数を記録する
    in_degree_rev[head_idx] += 1;
    // 答えを出すときのために値を保存しておく
    input_tail_idx[i] = tail_idx;
  }

  // 0: 不明 or loop 
  // 1: 勝ち
  // 2: 負け
  let undefined = 0;
  let win = 1;
  let lose = 2;

  let mut que: VecDeque<usize> = VecDeque::new();
  for i in 0..MAX_N {
    if in_degree_rev[i] == 0 {
      // 端点を開始点にする
      // 端点は複数個あるので for で全探索している
      que.push_back(i);

      // 端点は [負けノード]
      ans[i] = lose;
    }
  }

  while let Some(now) = que.pop_front() {
    for next in &graph_rev[now] {
      let next = *next;
      if ans[next] != undefined { continue; }
      
      in_degree_rev[next] -= 1;
      if ans[now] == lose {
        // next から [負けノード] に遷移できるなら
        // next は [勝ちノード]
        ans[next] = win;
        que.push_back(next);
      }
      else if in_degree_rev[next] == 0 {
        // next のノードから遷移できるノードが全て勝ちノードなら
        // next は [負けノード]
        ans[next] = lose;
        que.push_back(next);
      }
    }
  }
  
  for i in 0..n {
    let to = ans[input_tail_idx[i]];
    let mut ans_str = "";
    if to == undefined { ans_str = "Draw" }
    if to == win { ans_str = "Aoki" }
    if to == lose { ans_str = "Takahashi" }
    println!("{}", ans_str);
  }
}
