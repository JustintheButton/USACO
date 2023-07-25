#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll dist(pii a, pii b) {
    return (pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main()
{
    ifstream fin("checklist.in"); ofstream fout("checklist.out");
    int H, G; fin >> H >> G; vector<pair<int, int>> h_loc(H + 1, {INT_MAX, INT_MAX}); vector<pair<int, int>> g_loc(G + 1, {INT_MAX, INT_MAX});
    for (int i = 1; i <= H; i++) { fin >> h_loc[i].first >> h_loc[i].second; }
    for (int i = 1; i <= G; i++) { fin >> g_loc[i].first >> g_loc[i].second; }
    vector<vector<pll>> dp(H + 1, vector<pll>(G + 1, { INT_MAX, INT_MAX })); dp[1][0] = { 0, INT_MAX };
    for (int i = 2; i <= H; i++) {
        dp[i][0].first = dp[i - 1][0].first + dist(h_loc[i], h_loc[i - 1]);
    }
    dp[1][1].second = dist(g_loc[1], h_loc[1]);
    for (int i = 2; i <= G; i++) {
        dp[1][i].second = dp[1][i - 1].second + dist(g_loc[i], g_loc[i - 1]);
    }
    for (int i = 2; i <= H; i++) {
        for (int j = 1; j <= G; j++) {
            dp[i][j].first = min(dp[i - 1][j].first + dist(h_loc[i - 1], h_loc[i]), dp[i - 1][j].second + dist(g_loc[j], h_loc[i]));
            dp[i][j].second = min(dp[i][j - 1].first + dist(h_loc[i], g_loc[j]), dp[i][j - 1].second + dist(g_loc[j], g_loc[j - 1]));
        }
    }
    fout << dp[H][G].first;
}
