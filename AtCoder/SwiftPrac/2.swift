// https://atcoder.jp/contests/abc042/tasks/abc042_a
import Foundation

// １行文字列
func readStr() -> String {
  readLine()!
}

// １行整数
func readInt() -> Int {
  Int(readLine()!)!
}

// 空白文字で分割された文字列
func readSpStrs() -> [String] {
  readLine()!.components(separatedBy: " ")
}

// 空白文字で分割された整数
func readSpInts() -> [Int] {
  readSpStrs().map { Int($0)! }
}

// N行分の整数
func readInt(_ n: Int) -> [Int] {
  (1...n).map { _ in readInt() }
}

let input:[Int] = readSpInts()

var n5 = 0
var n7 = 0

input.forEach{
  switch $0 {
    case 5: n5 += 1
    case 7: n7 += 1
    default: fatalError()
  }
}

if n5 == 2 && n7 == 1 {
  print("YES")
}
else {
  print("NO")
}



