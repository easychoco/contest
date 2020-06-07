#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;
const int INF = 1000000007;


void solve()
{
	int n, l;
	cin >> n >> l;
	vector<int> hurdle(n + 4, INF);
	for(int i = 0; i < n; ++i)
	{
		cin >> hurdle[i];
	}

	int t1, t2, t3;	
	cin >> t1 >> t2 >> t3;

	vector<int> pos(l + 6, INF);
	int next_h = 0;

	pos[0] = 0;
	pos[1] = t1 + t3 * (hurdle[next_h] == 1);

	if (hurdle[next_h] <= 1)
	{
		next_h = min(next_h + 1, n - 1);
	}

	// 2
	{
		int ans = INF;

		// 2
		ans = min(ans, t1 + t2 + t3 * (hurdle[next_h] == 2));
		// pos[1] + 1
		ans = min(ans, pos[1] + t1 + t3 * (hurdle[next_h] == 2));

		pos[2] = ans;

		if (l == 2)
		{
			// 1 3
			ans = min(ans, t1 + (t1 + t2) / 2 + t3);
			// 3
			ans = min(ans, (t1 + t2) / 2 + t2);

			cout << ans;
			return;
		}
	}

	if (hurdle[next_h] <= 2)
	{
		next_h = min(next_h + 1, n - 1);
	}

	// 3
	{
		int hurdle_flag = 0;
		for(int i = 0; i < n; ++i)
		{
			hurdle_flag |= 1 << hurdle[i];
		}

		int ans = INF;

		// pos[2] + 1
		ans = min(ans, pos[2] + t1 + t3 * (hurdle[next_h] == 3));
		// pos[1] + 2
		ans = min(ans, pos[1] + t1 + t2 + t3 * (hurdle[next_h] == 3));
		
		pos[3] = ans;
		if (l == 3)
		{
			// 1 1 2
			ans = min(ans, t1 * 2 + (t1 + t2) / 2 + t3 * n);
			// 1 3
			ans = min(ans, (t1 + t2) * 3 / 2 + (1<<1 & hurdle_flag) * t3);
			// 3
			ans = min(ans, (t1 + t2) / 2 + t2 * 2);

			cout << ans;
			return;
		}
	}

	if (hurdle[next_h] <= 3)
	{
		next_h = min(next_h + 1, n - 1);
	}
	/*
	cout << pos[0] << endl;
	cout << pos[1] << endl;
	cout << pos[2] << endl;
	cout << pos[3] << endl;
	*/

	for(int i = 4; i <= l; ++i)
	{
		int ans = INF;

		// pos[i-1] + 1
		ans = min(ans, pos[i - 1] + t1 + t3 * (hurdle[next_h] == i));
		//cout << ans << " ";

		// pos[i-2] + 2
		ans = min(ans, pos[i - 2] + t1 + t2 + t3 * (hurdle[next_h] == i));
		//cout << ans << " ";
		
		// pos[i-4] + 4
		ans = min(ans, pos[i - 4] + t1 + t2 * 3 + t3 * (hurdle[next_h] == i));
		//cout << ans << " | ";

		pos[i] = ans;
		//cout << i << " " << next_h << " " << pos[i] << endl;

		if (hurdle[next_h] <= i)
		{
			next_h = min(next_h + 1, n - 1);
		}

		if (l == i + 3)
		{
			// 1 1 2
			ans = min(ans, pos[i - 3] + t1 * 2 + (t1 + t2) / 2 + t3 * n);
			// 1 3
			ans = min(ans, pos[i - 3] + (t1 + t2) * 3 / 2 + (1<<1 & hurdle_flag) * t3);
			// 3
			ans = min(ans, pos[i - 3] + (t1 + t2) / 2 + t2 * 2);

			cout << ans;
			return;

		}
	}

	/*
		// 行動1
		pos_1 = pos[i] + (t1 + t2) / 2;
		pos_2 = pos[i] + t1 + t2;
		pos_2 += ((i + 2 == hurdle[next_h + 0]) * t3);
		pos_2 += ((i + 2 == hurdle[next_h + 1]) * t3);

		// 行動2
		pos_2 = min(pos_2, pos[i] + (t1 + t2) / 2 + t2);
		pos_3 = pos[i] + (t1 + t2) / 2 + t2 * 2;
		pos_4 = pos[i] + t1 + t2 * 3;

		pos_4 += ((i + 4 == hurdle[next_h + 0]) * t3);
		pos_4 += ((i + 4 == hurdle[next_h + 1]) * t3);
		pos_4 += ((i + 4 == hurdle[next_h + 2]) * t3);
		pos_4 += ((i + 4 == hurdle[next_h + 3]) * t3);

		// 行動3
		pos_1 = min(pos_1, pos[i] + t1) + ((i + 1 == hurdle[next_h + 0]) * t3);

		cout << i << " " << pos[i] << endl;
		cout << pos_1 << " " << pos_2 << " " << pos_3 << " " << pos_4 << endl;

		pos[i + 1] = min(pos[i + 1], pos[i] + pos_1);
		pos[i + 2] = min(pos[i + 2], pos[i] + pos_2);
		pos[i + 3] = min(pos[i + 3], pos[i] + pos_3);
		pos[i + 4] = min(pos[i + 4], pos[i] + pos_4);
	}
	*/

	cout << pos[l];

}

int main()
{
	fastio;
	solve();

	return 0;
}