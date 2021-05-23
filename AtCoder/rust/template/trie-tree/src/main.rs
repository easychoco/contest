use std::str;
use std::collections::LinkedList;

pub struct Trie {
  node: char,
  is_leaf: bool,
  children: Vec<Box<Trie>>,
}

impl Trie {
  pub fn new() -> Trie {
    Trie {
      node: '*',
      is_leaf: false,
      children: vec![],
    }
  }

  pub fn exist(&self, s: &str) -> bool {
    let mut 
  }

  pub fn insert(&self, s: &str) {

  }

  pub fn remove(&self, s: &str) {
    
  }
}

fn main () {

}
