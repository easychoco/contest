use std::str;
use std::collections::VecDeque;

#[derive(Debug)]
struct Node {
  prefix: String,
  is_leaf: bool,
  children: Vec<usize>,
}

impl Node {
  pub fn new() -> Node {
    Node {
      prefix: String::from("-"),
      is_leaf: false,
      children: vec![],
    }
  }
  pub fn from(c: &str) -> Node {
    std::assert_eq!(c.len(), 1, "arg is {}" , c);
    let mut node = Node::new();
    node.prefix = String::from(c);
    node
  }
}

pub struct Trie {
  nodes: Vec<Node>,
}

impl Trie {
  pub fn new() -> Trie {
    Trie { 
      nodes: vec![ Node {
          prefix: String::from("-"),
          is_leaf: false,
          children: vec![],
        }],
    }
  }

  pub fn insert(&mut self, s: &str) {
    std::assert!(s.len() > 0, "insert size <= 0");
    self.insert_dfs(s, 0);
  }

  fn insert_dfs(&mut self, s: &str, idx: usize) {
    // 入力文字の先頭を見る
    // マッチすれば次の文字を見る 
    // マッチしなければ追加する
    
    for &i in &self.nodes[idx].children {
      // みつかった
      if &self.nodes[i as usize].prefix == &s[0..1] {
        let child_idx: usize = i;
        self.insert_dfs(&s[1..], child_idx);
        return;
      }
    }

    // みつからなかった
    let mut next: Node = Node::from(&s[0..1]);
    next.is_leaf = s.len() == 1;

    let next_idx: usize = self.nodes.len();
    &self.nodes.push(next);
    &self.nodes[idx].children.push(next_idx);
    
    if s.len() > 1 {
      self.insert_dfs(&s[1..], next_idx);
    }
  }

  pub fn remove(&mut self, s: &str) {
    self.remove_dfs(s, 0);
  }

  fn remove_dfs(&mut self, s: &str, idx: usize) -> bool {
    if s.len() == 0 {
      if self.nodes[idx].is_leaf && self.nodes[idx].children.len() == 0 {
        self.nodes[idx].prefix = String::from("non");
        return true;
      }
      self.nodes[idx].is_leaf = false;
      return false;
    }

    for &i in &self.nodes[idx].children {
      // みつかった
      if &self.nodes[i as usize].prefix == &s[0..1] {
        let child_idx: usize = i;
        if self.remove_dfs(&s[1..], child_idx) && self.nodes[idx].children.len() == 1 {
          self.nodes[idx].is_leaf = false;
          self.nodes[idx].prefix = String::from("non");
          return true;
        }
        return false;
      }
    }
    false
  }

  pub fn exist(&self, s: &str) -> bool {
    self.exist_dfs(s, 0)
  }

  fn exist_dfs(&self, s: &str, idx: usize) -> bool {
    if s.len() == 0 {
      return self.nodes[idx].is_leaf;
    }

    for i in &self.nodes[idx].children {
      // みつかった
      if &self.nodes[*i as usize].prefix == &s[0..1] {
        return self.exist_dfs(&s[1..], *i);
      }
    }
    false
  }

  pub fn predict(&self, s: &str) -> Vec<String> {
    self.predict_impl(s, 0)
      .iter()
      .map(|suffix| String::from(s) + suffix)
      .collect()
  }

  fn predict_impl(&self, s: &str, idx: usize) -> Vec<String> {
    if s.len() == 0 {
      // ここでBFS をする
      let mut ret: Vec<String> = vec![];

      let mut q = VecDeque::new();
      for &i in &self.nodes[idx].children {
        let qi = i;
        q.push_back((qi, String::new()));
      }
      while let Some(front) = q.pop_front() {
        let (idx, s) = front;
        if &self.nodes[idx].prefix == "non" { continue; }
        let now = String::from(s) + &self.nodes[idx].prefix;
        if self.nodes[idx].is_leaf {
          ret.push(now.clone());
        }
        for &i in &self.nodes[idx].children {
          let qi = i;
          q.push_back((qi, now.clone()));
        }
      }
      return ret;
    }

    for &i in &self.nodes[idx].children {
      if &self.nodes[i].prefix == &s[0..1] {
        let child_idx = i;
        return self.predict_impl(&s[1..], child_idx);
      }
    }
    vec![]
  }
}

fn main () {
  let mut trie = Trie::new();
  trie.insert("abc");
  trie.insert("abca");
  trie.insert("abcaa");
  trie.insert("abcab");
  trie.insert("abcba");
  trie.insert("acab");
  for i in &trie.nodes {
    println!("{:?}", i);
  }

  println!("{:?}", trie.predict("a"));
  println!("{}", trie.exist("abc"));
  println!("{}", trie.exist("abcaa"));
  println!("{}", trie.exist("abcab"));
  println!("{}", trie.exist("abcba"));
  println!("{}", trie.exist("acab"));
  println!("------");
  println!("{}", trie.exist("abca"));
  println!("{}", trie.exist("abcb"));
  println!("{}", trie.exist("ac"));
  println!("{}", trie.exist("aca"));
  println!("{}", trie.exist("c"));
  println!("------");
  trie.remove("abc");
  trie.remove("abca");
  trie.remove("abcaa");
  trie.remove("abcab");
  trie.remove("abcba");
  trie.remove("acab");
  println!("{}", trie.exist("abc"));
  println!("{}", trie.exist("abcaa"));
  println!("{}", trie.exist("abcab"));
  println!("------");
  println!("{}", trie.exist("abcba"));
  println!("{}", trie.exist("acab"));
  println!("------");
  println!("{}", trie.exist("abca"));
  println!("{}", trie.exist("abcb"));
  println!("{}", trie.exist("ac"));
  println!("{}", trie.exist("aca"));
  println!("{}", trie.exist("c"));
  println!("------");
  trie.insert("abcab");
  for i in &trie.nodes {
    println!("{:?}", i);
  }
  println!("{:?}", trie.predict("a"));
}

/*
'abc'
'abcaa'
'abcab'
'abcba'
'acab'

* - a - b - c - a - a - b - b - a - c - a - b

'-'

Trie.node = [ -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]
Trie.node[-1].children = [ 0 ]
Trie.node[0].chidlren = [ 1, 8 ]
Trie.node[1].chidlren = [ 2 ]
Trie.node[2].chidlren = [ 3, 6 ]
Trie.node[3].chidlren = [ 4, 5 ]
Trie.node[4].chidlren = [ ]

'abcab' ->
idx = node[-1].children.any(s[0])
if exist idx = node[idx].children.any(s[1])
if exist idx = node[idx].children.any(s[2])
if exist idx = node[idx].children.any(s[3])
if exist idx = node[idx].children.any(s[4])
if not exist {
  next:Trie = Trie.new(...)
  Trie.node.push(next)
  node[idx].children.push(idx)
}

a0 -- b1 -- c2 -- a3 -- a4
  \           \      \- b5
   \           \- b6 -- a7
    \- c8 -- a9 -- b10


b -- b -- c -- a -- a
\          \     \- b
 \          \- b -- a
  \- c -- a -- b

c -- b -- c -- a -- a
\          \     \- b
 \          \- b -- a
  \- c -- a -- b


検索窓 [ ab      ]
もしかして： abcaa, abcab, abcca
*/
