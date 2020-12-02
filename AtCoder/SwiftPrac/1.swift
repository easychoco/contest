// https://atcoder.jp/contests/arc104/tasks/arc104_b
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

let input = readSpStrs()
let n = Int(input[0])!
let s = input[1]

var sa:[Int] = [0]
var st:[Int] = [0]
var sc:[Int] = [0]
var sg:[Int] = [0]

var na = 0
var nt = 0
var nc = 0
var ng = 0

s.forEach {
  if $0 == "A" { na += 1 }
  if $0 == "T" { nt += 1 }
  if $0 == "C" { nc += 1 }
  if $0 == "G" { ng += 1 }

  sa.append(na)
  st.append(nt)
  sc.append(nc)
  sg.append(ng)
}

var ans = 0
for i in 0..<n{
  for j in i..<n{
    let a_num = sa[j + 1] - sa[i]
    let t_num = st[j + 1] - st[i]
    let c_num = sc[j + 1] - sc[i]
    let g_num = sg[j + 1] - sg[i]

    if a_num == t_num && c_num == g_num {
      ans += 1
    }
  }
}

print(ans)

