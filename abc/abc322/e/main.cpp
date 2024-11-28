#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K, P;
    cin >> N >> K >> P;
    vector<int> C(N);
    vector<vector<int>> A(N, vector<int>(K));
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        for (int j = 0; j < K; j++) {
            cin >> A[i][j];
        }
    }

    vector<int> PowP(K + 1, 1);
    for (int i = 1; i <= K; i++) {
        PowP[i] = PowP[i - 1] * (P + 1);
    }

    vector<vector<ll>> dp(N + 1, vector<ll>(PowP[K], 1e18));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < PowP[K]; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            int nj = j;
            for (int k = 0; k < K; k++) {
                int p = (j / PowP[k]) % (P + 1);
                nj += PowP[k] * min(P, p + A[i][k]) - PowP[k] * p;
                dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + C[i]);
            }
        }
    }

    if (dp[N][PowP[K] - 1] == 1e18) cout << -1 << endl;
    else cout << dp[N][PowP[K] - 1] << endl;
}
