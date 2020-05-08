// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=ja
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

constexpr int ARRAY_SIZE = 2000 + 10;

bool a[ARRAY_SIZE];
int seq[20];

void search(int, int);

int main()
{
	for(int i = 0; i < ARRAY_SIZE; ++i)
	{
		a[i] = false;
	}
	a[0] = true;

	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int in = 0;
		cin >> in;
		seq[i] = in;
	}

	search(n - 1, 0);

	int q;
	cin >> q;
	for(int i = 0; i < q; ++i)
	{
		int m = 0;
		cin >> m;
		cout << (a[m] ? "yes" : "no") << endl;
	}
	
	return 0;
}

void search(int index, int sum)
{
	if(index < 0)
	{
		a[sum] = true;
		return;
	}
	search(index - 1, sum);
	search(index - 1, sum + seq[index]);
}


