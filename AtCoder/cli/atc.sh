#!/bin/sh

set -eu

atc() {
  CURRENT_DIR_PATH=$(pwd)

  REPOSITORY_ROOT=$(
    cd "$(dirname "$0")/.."
    pwd
  )

  COMMAND_ROOT="${REPOSITORY_ROOT}/cli/commands"

  if [ $# -eq 0 ]; then
    usage
    exit
  fi

  SUB_COMMAND="$1"
  shift
  case "$SUB_COMMAND" in
    # C++
    c|cp|cpp)
      SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/cpp.sh"
    ;;
    gg)
      SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/cpp.sh gg"
    ;;

    # Python
    p|py|python)
      SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/python.sh"
    ;;

    # Rust
    r|rs|rust)
      SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/rust.sh"
    ;;

    # common
    run)
      LANG=$(guess_lang "$CURRENT_DIR_PATH")
      SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/${LANG}/run.sh"
    ;;
    rin)
      LANG=$(guess_lang "$CURRENT_DIR_PATH")
      SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/${LANG}/rin.sh"
    ;;

    *)
      echo 'unknown' 1>&2
      usage
    ;;
  esac

  CURRENT_DIR_PATH="$CURRENT_DIR_PATH" \
  REPOSITORY_ROOT="$REPOSITORY_ROOT" \
  COMMAND_ROOT="$COMMAND_ROOT" \
  $SUBCOMMAND_SCRIPT "$@"
}

guess_lang() {
  # 抽出対象
  CPP="cpp"
  PYTHON="python"
  RUST="rust"

  LANG=$(echo "$CURRENT_DIR_PATH" | sed -r "s/.*\/AtCoder\/(${CPP}|${PYTHON}|${RUST}).*/\1/")
  if [ "$CURRENT_DIR_PATH" = "$LANG" ]; then
    echo "directory meybe wrong." 1>&2
    usage
    return 1;
  fi

  echo "$LANG"
}

usage() {
  cat <<- END 1>&2

[ atc.sh ]

  C++:
    atc cp abc xxx         [C++] ABCxxx を VSCode で開く
    atc cp arc xxx         [C++] ARCxxx を VSCode で開く
    atc cp agc xxx         [C++] AGCxxx を VSCode で開く
    atc cp mono xxx        [C++] xxx.cpp という名前のファイルを mono フォルダに作って VSCode で開く
    atc gg xxx             [C++] ./xxx.cpp をコンパイルする
    atc r|run              [C++] ./a.out
    atc rin                [C++] ./a.out < in
    atc cp template        [C++] C++ のプログラムテンプレートをコピーする

  Python:
    atc py abc xxx         [Python] ABCxxx を VSCode で開く
    atc py arc xxx         [Python] ARCxxx を VSCode で開く
    atc py agc xxx         [Python] AGCxxx を VSCode で開く
    atc py mono xxx        [Python] xxx.py という名前のファイルを mono フォルダに作って VSCode で開く
    atc r|run a            [Python] python a.py
    atc rin a              [Python] python a.py < in
    atc py template        [Python] Python のプログラムテンプレートをコピーする

  Rust:
    atc rust abc xxx       [Rust] ABCxxx を VSCode で開く
    atc rust arc xxx       [Rust] ARCxxx を VSCode で開く
    atc rust agc xxx       [Rust] AGCxxx を VSCode で開く
    atc rust mono xxx      [Rust] xxx.py という名前のファイルを mono フォルダに作って VSCode で開く
    atc r|run a            [Rust] cargo run a.rs
    atc rin a              [Rust] cargo run a.rs < in
    atc rust template      [Rust] Rust のプログラムテンプレートをコピーする

END
}

atc "$@"
