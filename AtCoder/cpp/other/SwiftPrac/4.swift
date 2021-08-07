// https://atcoder.jp/contests/abc044/tasks/abc044_a
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

let input:[Int] = readInt(4)
var n = input[0]
var k = input[1]
var x = input[2]
var y = input[3]

var ans = 0
ans += x * min(n, k)
ans += y * max(0, n - k)
print(ans)