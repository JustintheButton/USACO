#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int m, n, c;

vector<int> money;
map<int, set<int>> inv;
vector<vector<ll>> dp;

ifstream fin("time.in"); ofstream fout("time.out");

void init() {
	fin >> n >> m >> c; money.resize(n); 
	for (int i = 0; i < n; i++) { fin >> money[i]; }
	for (int i = 0; i < m; i++) { int a, b; fin >> a >> b; a--; b--; inv[b].insert(a); }
	dp.resize(1001); for (int i = 0; i < 1001; i++) { dp[i].resize(n, LLONG_MIN); }
	dp[0][0] = 0;
}

ll solve() {
	ll ans = 0;
	for (int i = 1; i < 1001; i++) {
		for (int j = 0; j < n; j++) {
			ll optimal = LLONG_MIN;
			for (auto k : inv[j]) {
				optimal = max(optimal, dp[i - 1][k]);
			}
			if (optimal == LLONG_MIN) { continue; }
			optimal += ((i-1) * (i-1) * c);
			optimal += money[j];
			optimal -= (i * i * c);
			dp[i][j] = optimal;
			if (j == 0) {
				ans = max(ans, optimal);
			}
		}
	}
	return ans;
}

int main()
{
	init();
	fout << solve();
}
