#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

// https://onihusube.hatenablog.com/entry/2019/07/23/183851
template<typename Str>
auto regex_searches(Str& str, const std::regex& patern) {
	using std::begin;
	using std::end;
	using str_iterator_t = decltype(begin(str));

	struct wrap_regex_iterator {
	using iterator = std::regex_iterator<str_iterator_t>;

	auto begin() const noexcept -> iterator {
		return first;
	}

	auto end() const noexcept -> iterator {
		return last;
	}

	explicit operator bool() const noexcept {
		return first != last;
	}

	iterator first;
	iterator last;
	};

	return wrap_regex_iterator{{begin(str), end(str), patern}, {}};
}

void solve()
{
	string s;
	cin >> s;

	regex re("R+L+");
    smatch match;
	for (auto&& match : regex_searches(s, re))
	{
		int r_cnt = 0;
		int l_cnt = 0;
		for(int i = 0; i < match[0].length(); ++i)
		{
			if (match[0].str()[i] == 'R')r_cnt++;
			else l_cnt++;
		}
		for(int i = 0; i < r_cnt - 1; ++i) cout << "0 ";
		cout << (r_cnt + 1) / 2 +  l_cnt      / 2 << " ";
		cout <<  r_cnt      / 2 + (l_cnt + 1) / 2 << " ";
		for(int i = 0; i < l_cnt - 1; ++i) cout << "0 ";
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}