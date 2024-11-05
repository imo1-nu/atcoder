#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

vector<vector<ll>> G;
vector<vector<ll>> dp;
vector<char> C;

ll mod = 1000000007;

void dfs (int pos, int par) {
    ll val1 = 1, val2 = 1;
    for (int i : G[pos]) {
        if (i == par) continue;
        dfs(i, pos);
        if (C[pos] == 'a') {
            val1 *= (dp[i][0] + dp[i][2]);
            val2 *= (dp[i][0] + dp[i][1] + 2ll * dp[i][2]); // 切らないとき: dp[i][0] + dp[i][1] + dp[i][2], 切るとき: dp[i][2]
        }
        else {
            val1 *= (dp[i][1] + dp[i][2]);
            val2 *= (dp[i][0] + dp[i][1] + 2ll * dp[i][2]);
        }
        val1 %= mod;
        val2 %= mod;
    }

    if (C[pos] == 'a') {
        dp[pos][0] = val1;
        dp[pos][2] = (val2 - val1 + mod) % mod;
    }
    else {
        dp[pos][1] = val1;
        dp[pos][2] = (val2 - val1 + mod) % mod;
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        C.push_back(c);
    }
    vector<ll> A(N), B(N);
    G.resize(N);
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    dp.resize(N, vector<ll>(3, 0));
    dfs(0, -1);
    cout << dp[0][2] << endl;
}
