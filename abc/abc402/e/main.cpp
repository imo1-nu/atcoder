#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N, X;
    cin >> N >> X;
    vector<int> S(N), C(N);
    vector<double> P(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> C[i] >> P[i];
        P[i] /= 100;
    }

    vector<vector<double>> dp(1 << N, vector<double>(X + 1));
    for (int x = 0; x <= X; x++) {
        for (int s = 0; s < (1 << N); s++) {
            for (int i = 0; i < N; i++) {
                int nx = x - C[i];
                int ns = s | (1 << i);
                if (nx < 0 || s == ns) continue;
                double val = P[i] * (dp[ns][nx] + S[i]) + (1 - P[i]) * dp[s][nx];
                dp[s][x] = max(dp[s][x], val);
            }
        }
    }
    cout << fixed << setprecision(10) << dp[0][X] << endl;
}
