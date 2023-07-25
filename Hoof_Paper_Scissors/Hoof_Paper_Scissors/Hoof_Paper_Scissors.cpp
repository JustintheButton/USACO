#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> moves; //0 for hoof, 1 for paper, 2 for scissors 
vector<vector<vector<int>>> dp;

int main()
{
    ifstream fin("hps.in"); ofstream fout("hps.out");
    fin >> n >> k; moves.resize(n); 
    for (int i = 0; i < n; i++) {
        char c; fin >> c; if (c == 'H') { moves[i] = 0; } if (c == 'P') { moves[i] = 1; } if (c == 'S') { moves[i] = 2; }
    }
    dp.resize(n); 
    for (int i = 0; i < n; i++) {
        dp[i].resize(k + 1); for (int j = 0; j < k + 1; j++) { dp[i][j].resize(3, 0); }
    }
    if (moves[0] == 0) { dp[0][0][0] = 1; } if (moves[0] == 1) { dp[0][0][1] = 1; } if (moves[0] == 2) { dp[0][0][2] = 1; }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            if (j > 0) {
                dp[i][j][0] = max(dp[i - 1][j][0], max(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]));
                dp[i][j][1] = max(dp[i - 1][j][1], max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][2]));
                dp[i][j][2] = max(dp[i - 1][j][2], max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]));
            }
            else {
                dp[i][j][0] = dp[i - 1][j][0];
                dp[i][j][1] = dp[i - 1][j][1];
                dp[i][j][2] = dp[i - 1][j][2];
            }
            if (moves[i] == 0) { dp[i][j][0]++; } if (moves[i] == 1) { dp[i][j][1]++; } if (moves[i] == 2) { dp[i][j][2]++; }
        }
    }
    int ans = INT_MIN;
    for (auto i : dp[dp.size() - 1]) {
        for (auto j : i) {
            ans = max(ans, j);
        }
    }
    fout << ans;
}
