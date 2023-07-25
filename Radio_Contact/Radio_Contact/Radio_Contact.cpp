#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dist(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main()
{
    ifstream fin("radio.in"); ofstream fout("radio.out");
    int n, m; fin >> n >> m; pair<int, int> f; pair<int, int> b; fin >> f.first >> f.second >> b.first >> b.second;
    vector<pair<int, int>> fpos(n + 1); vector<pair<int, int>> bpos(m + 1);
    fpos[0] = f; bpos[0] = b;
    for (int i = 1; i <= n; i++) {
        fpos[i] = fpos[i - 1];
        char c; fin >> c; 
        if (c == 'N') { fpos[i].second++; }
        else if(c == 'E') { fpos[i].first++; }
        else if (c == 'W') { fpos[i].first--; }
        else if (c == 'S') { fpos[i].second--; }
    }
    for (int i = 1; i <= m; i++) {
        bpos[i] = bpos[i - 1];
        char c; fin >> c;
        if (c == 'N') { bpos[i].second++; }
        else if (c == 'E') { bpos[i].first++; }
        else if (c == 'W') { bpos[i].first--; }
        else if (c == 'S') { bpos[i].second--; }
    }
    vector<vector<int>> dp(n+1, vector<int>(m + 1));
    for (int i = 1; i <= m; i++) {
        dp[0][i] = dp[0][i-1] + dist(fpos[0], bpos[i]);
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][0] + dist(fpos[i], bpos[0]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + dist(fpos[i], bpos[j]);
        }
    }
    fout << dp[n][m];
}
