#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

class UnionFind{
public:
	vector<int> p;		// 親
	vector<int> rank;	// サイズ・各集合の根のみ有効
	UnionFind(int n){
		p.resize(n, -1);
		rank.resize(n, 1);
	}
	int root(int x){
		if(p[x] == -1)return x;
		else return p[x] = root(p[x]); // 深さを 1 にしている
	}
	void unite(int x, int y){
		x = root(x); y = root(y);
		if(x == y)return;
		if(rank[x] > rank[y]) swap(x, y); // rankの小さいものを下につける
		rank[y] += rank[x];
		p[x] = y;
	}
	//xが属すグループのサイズ
	int size(int x){ return rank[root(x)]; }
	bool same(int x, int y){ return (root(x) == root(y)); }
};

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	
	UnionFind ab(n);
	vector<int> fr(n, 0);
	vector< vector<int> > cd(n);

	for(int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		++fr[a];
		++fr[b];
		ab.unite(a, b);
	}

	for(int i = 0; i < k; ++i)
	{
		int c, d;
		cin >> c >> d;
		--c;
		--d;

		cd[c].push_back(d);
		cd[d].push_back(c);
	}


	for(int i = 0; i < n; ++i)
	{
		int ans = ab.size(i) - fr[i] - 1;
		for(int c : cd[i])
		{
			if (ab.same(i, c))--ans;
		}
		cout << ans << " ";
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}