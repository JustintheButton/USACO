#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n, mod;

int main()
{
    ifstream fin("exercise.in"); ofstream fout("exercise.out");
    fin >> n >> mod;
    vector<int> prime;
    vector<bool> composite(n + 1, false);
    for (int i = 2; i <= n; i++) {
        if (!composite[i]) {
            prime.push_back(i);
            for (int j = 2 * i; j <= n; j+=i) {
                composite[j] = true;
            }
        }
    }
    vector<vector<ll>> dp(prime.size(), vector<ll>(n + 1));
    if (prime.size() == 0) { cout << 1; return 0; }
    dp[0][0] = 1; if (n >= 2) { dp[0][2] = 2; }
    //setting 2
    for (int i = 3; i <= n; i++) {
        if (i % 2 == 0) {
            if (dp[0][i / 2] != 0) { dp[0][i] = i; }
        }
    }
    for (int i = 1; i < prime.size(); i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            ll cur = prime[i];
            while (cur <= j) {
                dp[i][j] += (cur * dp[i - 1][j - cur]) % mod;
                cur *= prime[i]; cur %= mod;
            }
        }
    }
    ll ans = 0;
    for (auto i : dp[prime.size() - 1]) {
        ans += i;
        ans %= mod;
    }
    fout << ans;
}
