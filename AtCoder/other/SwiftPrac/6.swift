// https://atcoder.jp/contests/agc039/tasks/agc039_a
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

func main(){
  let s = readStr()
  let k = readInt()

  var len = 0
  var lens:[Int] = []

  let s_idx_start = s.index(s.startIndex, offsetBy: 0)
  let s_idx_end = s.index(s.endIndex, offsetBy: -1)
  var now:Character = s[s_idx_start]
  s.forEach{
    if $0 == now {
      len += 1
    }
    else {
      lens.append(len)
      len = 1
      now = $0
    }
  }
  lens.append(len)

  var ans = 0
  if (s[s_idx_start] != s[s_idx_end]){
    lens.forEach{
      ans += ($0 / 2) * k
    }
  }
  else {
    if lens.count == 1 {
      ans = lens.first! * k / 2
    }
    else{
      for i in 1..<lens.count - 1{
        ans += (lens[i] / 2) * k;
      }

      ans += lens.first! / 2 + lens.last! / 2
      ans += (lens.first! + lens.last!) / 2 * (k - 1)
    }
  }
  print(ans)
  
}

main()