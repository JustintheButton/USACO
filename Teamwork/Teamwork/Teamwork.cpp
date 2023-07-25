#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ifstream fin("teamwork.in");
ofstream fout("teamwork.out");

int n, k;
vector<int> dp;
vector<int> vec;

int main()
{
	fin >> n >> k;
	dp.resize(n); vec.resize(n);
	for (int i = 0; i < n; i++) { fin >> vec[i]; }
	dp[0] = vec[0];
	for (int last = 1; last < n; last++) {
		ll mx = vec[last] + dp[last - 1];
		int team_max = vec[last];
		for (int back = 1; back < k; back++) {
			if (last - back < 0) { break; }
			team_max = max(team_max, vec[last-back]);
			ll best_so_far = 0;
			if (last - back != 0) { best_so_far = dp[last - back - 1]; }
			mx = max(mx, ll(team_max * (back + 1) + best_so_far));
		}
		dp[last] = mx;
	}
	fout << dp[dp.size() - 1];
}
