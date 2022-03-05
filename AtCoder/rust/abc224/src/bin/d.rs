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
    m: usize,
    mut uv: [(usize, usize); m],
    p: [usize; 8]
  }
  let mut graph = vec![vec![]; 9];
  for (from, to) in uv.iter() {
    let from = from - 1;
    let to = to - 1;
    graph[from].push(to);
    graph[to].push(from);
  }

  let mut goal = vec![10; 9];
  let mut first = p
    .iter()
    .map(|v| {
      let v = v - 1;
      goal[v] = v;
      v.to_string()
    })
    .collect::<String>()
  ;
  first += "-";
  
  let goal = goal
    .into_iter()
    .map(|v| {
      if v == 10 { String::from("-") }
      else { v.to_string() }
    })
    .collect::<String>()
  ;

  let mut shown = HashSet::<String>::new();
  let mut que = VecDeque::<(String, usize)>::new();

  que.push_back((String::from(&first), 0));
  shown.insert(String::from(&first));

  while let Some((now, depth)) = que.pop_front() {
    if now == goal {
      println!("{}", depth);
      return;
    }

    let mut to = 0;
    for (idx, c) in now.chars().enumerate() {
      if c == '-' {
        to = idx;
      }
    }
    for from in graph[to].iter() {
      let mut next = now.chars().collect_vec();
      next.swap(to, *from);
      let next = next.iter().collect::<String>();

      if shown.contains(&next) { continue }
      shown.insert(String::from(&next));
      que.push_back((String::from(&next), depth + 1));
    }
  }

  println!("-1");
  
}
