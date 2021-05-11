
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

func main{

}

main()