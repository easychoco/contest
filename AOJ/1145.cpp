// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1145&lang=jp
// http://algoogle.hadrori.jp/aoj/1145/
#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

string s;
int n, cur = 0;

//今見ているところの数字を取得
int number()
{
	int ret = 0;
	while(isdigit(s[cur]))
	{
		ret = ret * 10 + s[cur++] - '0';
	}
	return ret;
}

int dfs(int sum) // sumはこれまで見た文字数
{
	if (cur == s.length()) // 最後まで来た
	{
		return 0;
	}
	if (s[cur] == '(') // 左カッコ
	{
		cur++; // 中に入る
		return dfs(sum);
	}
	if (s[cur] == ')') // 右カッコ
	{
		cur++; // 外に出る
		return 0;
	}
	if(isalpha(s[cur])) // 潜りきった
	{
		if (sum == n)
		{
			throw s[cur];
		}
		cur++;
		return 1 + dfs(sum + 1); // １文字先に
	}

	// 見ている文字は数字

	int m = number();
	int l; // 数字の後に来る文字の文字数
	int head = cur;

	// 数字の次にアルファベットなら
	if (isalpha(s[cur]))
	{
		l = 1;
		cur++;
	}
	else // それ以外（カッコ）なら
	{
		l = dfs(sum);
	}

	// 今見ている数字倍した後の範囲内にあるなら
	if (l * m + sum > n)
	{
		cur = head;
		n = (n - sum) % l; // これまで見ていた文字数(sum)分を消す
		dfs(0); // sumだけ消したので 0 で再探索
	}

	// 今見ている範囲内にはない
	return l * m + dfs(sum + l * m);	

}

char solve(){
	cur = 0;
	try{ dfs(0); }
	catch(char e){ return e;}
	return '0';
}

int main(){
	while(cin >> s >> n, s!="0") cout << solve() << endl;
	return 0;
}




