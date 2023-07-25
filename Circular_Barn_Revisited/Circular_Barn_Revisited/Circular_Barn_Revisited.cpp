#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

ifstream fin("cbarn2.in"); 
ofstream fout("cbarn2.out");

int n, k;
vector<ll> r;
ll ans = LLONG_MAX;

int main()
{
    fin >> n >> k; r.resize(n); for (int i = 0; i < n; i++) { fin >> r[i]; }
    for (int fixed = 0; fixed < n; fixed++) {
        vector<vector<ll>> dp(k, vector<ll>(n, INT64_MAX)); dp[0][0] = 0;
        vector<ll> pfx(n + 1); for (int i = 0; i < n; i++) { pfx[i + 1] = pfx[i] + r[i]; }
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i - 1] + i * r[i];
        }
        for (int row = 1; row < k; row++) {
            for (int col = row; col < n; col++) {
                ll count = 0;
                for (int i = col - 1; i >= row - 1; i--) {
                    count += pfx[col + 1] - pfx[i + 2];
                    dp[row][col] = min(dp[row][col], dp[row - 1][i] + count);
                }
            }
        }
        ans = min(ans, dp[dp.size() - 1][dp[0].size() - 1]);
        r.push_back(r[0]); r.erase(r.begin());
    }
    fout << ans;
}
