#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int dp[101][101][101]; //i = current day, j = number of breakouts, k = what the counter is supposed to be
int n;
vector<int> vec;

int main()
{
    cin >> n; vec.resize(n); for (int i = 0; i < n; i++) { cin >> vec[i]; } 
    //dp[1][1][0] = (vec[0] == 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int m = 0;
            for (int a = 0; a <= 100; a++) { m = max(m, dp[i - 1][j - 1][a]); }
            dp[i][j][0] = m;
            for (int k = 1; k <= 100; k++) {
                dp[i][j][k] = dp[i - 1][j][k - 1] + (k == vec[i - 1]);
            }
        }
    }
    vector<int> ans(n);
    for (int j = 1; j <= n; j++) {
        for (int k = 0; k <= 100; k++) {
            ans[j - 1] = max(dp[n][j][k], ans[j - 1]);
        }
    }
    for (auto i : ans) {
        cout << i << "\n";
    }
}
