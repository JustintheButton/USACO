#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXW = 1e6;
int dp[MAXW + 1];

int main()
{
    ifstream fin("talent.in");
    ofstream fout("talent.out");
    int n, w; fin >> n >> w;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        fin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < n; i++) {
        for (int j = MAXW; j >= v[i].first; j--) {
            if (j == v[i].first) {
                dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
            }
            else {
                if (dp[j - v[i].first] != 0) {
                    dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
                }
            }
        }
    }
    ll ans = 0;
    for (int i = w; i <= MAXW; i++) {
        ans = max(ans, ll(double((double(dp[i]) / double(i)) * 1000)));
    }
    fout << ans;
}