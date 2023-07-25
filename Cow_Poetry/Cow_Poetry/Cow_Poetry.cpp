#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int MOD = 1e9 + 7;

int n, m, k;
map<int, vector<int>> words;
vector<ll> dp;
vector<int> word_lengths;
map<int, ll> ways;

ll expo(ll a, ll b) {
    ll ret = 1; a %= MOD;
    while (b > 0) {
        if (b % 2 == 1) {
            ret *= a; ret %= MOD;
        }
        a *= a; a %= MOD;
        b /= 2;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream fin("poetry.in"); ofstream fout("poetry.out");
    fin >> n >> m >> k; dp.resize(k + 1); word_lengths.resize(n);
    for (int i = 0; i < n; i++) {
        int a, b; fin >> a >> b; b--; words[b].push_back(a);
        word_lengths[i] = a;
    }
    dp[0] = 1;
    for (int i = 1; i < dp.size(); i++) {
        for (auto j : word_lengths) {
            if (i - j >= 0) {
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            }
        }
    }
    //counting the ways
    for (auto i : words) {
        for (auto j : i.second) {
            ways[i.first] += dp[k - j];
        }
    }
    //getting ans
    ll ans = 1;
    map<char, int> lines;
    for (int i = 0; i < m; i++) {
        char a; fin >> a;
        lines[a]++;
    }
    for (auto i : lines) {
        ll cur = 0;
        for (auto j : ways) {
            cur += expo(j.second, i.second);
            cur %= MOD;
        }
        ans *= cur;
        ans %= MOD;
    }
    fout << ans;
}
