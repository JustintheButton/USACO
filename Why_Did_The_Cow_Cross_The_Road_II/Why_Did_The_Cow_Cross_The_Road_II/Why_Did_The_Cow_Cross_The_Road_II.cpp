#include <bits/stdc++.h>
using namespace std;

int comp(int a, int b) {
    return (abs(a - b) <= 4);
}

int main()
{
    ifstream fin("nocross.in"); ofstream fout("nocross.out");
    int n; fin >> n; vector<int> a(n); vector<int> b(n); for (int i = 0; i < n; i++) { fin >> a[i]; } for (int i = 0; i < n; i++) { fin >> b[i]; }
    vector<vector<int>> dp(n, vector<int>(n)); dp[0][0] = comp(a[0], b[0]);
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][0] + comp(a[i], b[0]), 1);
    }
    for (int i = 1; i < n; i++) {
        dp[0][i] = min(dp[0][i - 1] + comp(a[0], b[i]), 1);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + comp(a[i], b[j]));
        }
    }
    fout << dp[n - 1][n - 1];
}
