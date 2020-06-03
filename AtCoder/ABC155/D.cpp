#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	ll n, k;
	cin >> n >> k;

	vector<ll> a_posi;
	vector<ll> a_nega;
	ll a;
	for(int i = 0; i < n; ++i)
	{
		cin >> a;
		// 0 はpositiveグループ
		(a >= 0) ? a_posi.emplace_back(a) : a_nega.emplace_back(a);
	}

	ll all_pair = n * (n - 1) / 2;

	sort(a_posi.begin(), a_posi.end());
	sort(a_nega.begin(), a_nega.end());

	// 愚直にやるとO(n^2)でしぬ
	// O(n)に抑えなきゃ
	// 尺取りっぽくして計算量抑えられる？？？

	ll posi_size = a_posi.size();
	ll nega_size = a_nega.size();

	// 別グループどうし
	ll nega_cnt = posi_size * nega_size;
	// 同グループどうし
	ll posi_cnt = ( posi_size * (posi_size - 1) + nega_size * (nega_size - 1) ) / 2;

	bool find_inverse = false;
	bool isNegative = true;

	cout << "posi_size : " << posi_size << " nega_size : " << nega_size << endl;
	cout << "posi_cnt  : " << posi_cnt  << " nega_cnt  : " << nega_cnt  << endl;

	if (k <= nega_cnt / 2)
	{
		isNegative = true;
		find_inverse = false;
		cout << "come1" << endl;
	}
	else if (k <= nega_cnt)
	{
		k = nega_cnt - k + 1;
		isNegative = true;
		find_inverse = true;
		cout << "come2" << endl;
	}
	else if (k - nega_cnt <= posi_cnt / 2)
	{
		k -= nega_cnt;
		isNegative = false;
		find_inverse = false;
		cout << "come3" << endl;
	}
	else
	{
		k = (nega_cnt + posi_cnt) - k + 1;
		isNegative = false;
		find_inverse = true;
		cout << "come4" << endl;
	}

	cout << "k is " << k << endl;
	
	// ここまで O(n log n)

	ll posi_index = 0;
	ll nega_index = 0;

	bool fin_posi = true;

	// O(k / 4) = O(5e9)....
	if (isNegative && !find_inverse)
	{
		for(ll i = 0; i < k; ++i)
		{
			if (posi_index == posi_size - 1)
			{
				nega_index++;
				continue;
			}
			if (nega_index == nega_size - 1)
			{
				posi_index++;
				continue;
			}
			if (a_posi[posi_index] * a_nega[nega_index + 1] < a_posi[posi_index + 1] * a_nega[nega_index])
			{
				nega_index++;
			}
			else
			{
				posi_index++;
			}
		}
	}
	else if (isNegative && find_inverse)
	{
		posi_index = posi_size - 1;
		nega_index = nega_size - 1;
		for(ll i = 0; i < k; ++i)
		{
			if (posi_index == 0)
			{
				nega_index--;
				continue;
			}
			if (nega_index == 0)
			{
				posi_index--;
				continue;
			}
			if (a_posi[posi_index] * a_nega[nega_index - 1] > a_posi[posi_index - 1] * a_nega[nega_index])
			{
				nega_index--;
			}
			else
			{
				posi_index--;
			}
		}
	}
	else if (!isNegative && !find_inverse)
	{
		for(ll i = 0; i < k; ++i)
		{
			if (posi_index == posi_size - 1)
			{
				nega_index++;
				continue;
			}
			if (nega_index == nega_size - 1)
			{
				posi_index++;
				continue;
			}
			if (a_posi[posi_index] * a_posi[posi_index + 1] < a_nega[nega_index + 1] * a_nega[nega_index])
			{
				posi_index++;
				fin_posi = true;
			}
			else
			{
				nega_index++;
				fin_posi = false;
			}
		}
	}
	else if (!isNegative && find_inverse)
	{
		posi_index = posi_size - 1;
		nega_index = nega_size - 1;
		for(ll i = 0; i < k; ++i)
		{
			if (posi_index == 0)
			{
				nega_index--;
				fin_posi = false;
				continue;
			}
			if (nega_index == 0)
			{
				posi_index--;
				fin_posi = true;
				continue;
			}
			if (a_posi[posi_index] * a_posi[posi_index - 1] < a_nega[nega_index - 1] * a_nega[nega_index])
			{
				nega_index--;
				fin_posi = false;
			}
			else
			{
				posi_index--;
				fin_posi = true;
			}
		}
	}
	else
	{
		while(true) cout << "fsdasdfsd";
	}

	cout << "negative : " << isNegative << " inv : " << find_inverse << " fin_posi : " <<  fin_posi << endl;
	cout << "posi : " << posi_index << " nega : " << nega_index << endl;

	if (isNegative)
	{
		cout << a_posi[posi_index] * a_nega[nega_index];
	}
	else if (fin_posi)
	{
		cout << a_posi[posi_index] * a_posi[posi_index + (find_inverse ? 1 : -1)];
	}
	else
	{
		cout << a_nega[nega_index] * a_nega[nega_index + (find_inverse ? 1 : -1)];
	}
	
}

int main()
{
	fastio;
	solve();

	return 0;
}