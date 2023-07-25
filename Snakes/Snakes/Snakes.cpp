#include <bits/stdc++.h>
using namespace std;

ifstream fin("snakes.in"); ofstream fout("snakes.out");

using ll = long long;

int n, k;

vector<vector<ll>> dp;
vector<int> snakes;

int main()
{
    ll sum = 0;
    fin >> n >> k; dp.resize(n); for (int i = 0; i < n; i++) { dp[i].resize(k + 1, INT_MAX); }
    snakes.resize(n); for (int i = 0; i < n; i++) { fin >> snakes[i]; sum += snakes[i]; } dp[0][0] = snakes[0]; int mx = snakes[0];
    for (int i = 1; i < n; i++) { mx = max(snakes[i], mx); dp[i][0] = mx * (i + 1); } mx = INT_MIN;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < k + 1; j++) {
            mx = snakes[i];
            for (int k = i - 1; k >= 0; k--) {
                mx = max(mx, snakes[k + 1]);
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + mx * (i - k));
            }
        }
    }
    fout << dp[dp.size() - 1][dp[0].size() - 1] - sum;
}
