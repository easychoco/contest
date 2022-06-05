#!/bin/sh

set -eu

run() {
  if [ ! $# -eq 1 ]; then
    echo "  args must be 2" 1>&2
    echo "    ex) ./run.sh 10" 1>&2
    return 1
  fi

  a gg a
  rm result -rf
  cd tools
  for i in $(seq "$1")
  do
    num=$(printf "%04d" "$((i - 1))")
    ../a.out < "in/${num}.txt" > "out/${num}"
    cargo run --release --bin vis "in/${num}.txt" "out/${num}" >> ../result
  done
  cd ../
  python3 calc.py "$1" < result
}

usage() {
  cat <<- END 1>&2

  ./run.sh 50
      a.cpp をコンパイルして
      tools/in/0000.txt から tools/in/0050.txt までのサンプルを試して 
      result に出力し、結果の最小・最大・平均・合計を出力する
END
}

run "$@"
