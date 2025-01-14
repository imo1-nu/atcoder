#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, X;
    cin >> N >> X;
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        C[i] = B[i] - A[i];
        X -= A[i];
    }

    if (X < 0) {
        cout << "No" << endl;
        return 0;
    }

    vector<vector<bool>> dp(N + 1, vector<bool>(X + 1));
    dp[0][0] = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= X; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= C[i - 1]) dp[i][j] = dp[i][j] || dp[i - 1][j - C[i - 1]];
        }
    }

    if (dp[N][X]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
