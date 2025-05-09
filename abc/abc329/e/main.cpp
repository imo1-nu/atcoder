#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    vector<vector<bool>> dp(N + 1, vector<bool>(M + 1));
    dp[0][0] = true;
    for (int i = 0; i < N; i++) {
        if (i + M <= N) {
            for (int j = 0; j < M + 1; j++) {
                if (dp[i][j]) dp[i][0] = true;
            }
        }
        if (dp[i][M]) {
            for (int j = 0; j < M + 1; j++) {
                dp[i][j] = true;
            }
        }
        for (int j = 0; j < M; j++) {
            if (dp[i][j] && S[i] == T[j]) dp[i + 1][j + 1] = true;
        }
    }
    if (dp[N][M]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
