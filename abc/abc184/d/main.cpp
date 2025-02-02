#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int A, B, C;
    cin >> A >> B >> C;

    vector<vector<vector<double>>> dp(101, vector<vector<double>>(101, vector<double>(101, 0)));
    dp[A][B][C] = 1;
    double ans = 0;
    for (int a = A; a <= 100; a++) {
        for (int b = B; b <= 100; b++) {
            for (int c = C; c <= 100; c++) {
                if (a == 100 || b == 100 || c == 100) {
                    ans += dp[a][b][c] * (a + b + c - A - B - C);
                    continue;
                }
                double p = dp[a][b][c];
                dp[a + 1][b][c] += p * a / (a + b + c);
                dp[a][b + 1][c] += p * b / (a + b + c);
                dp[a][b][c + 1] += p * c / (a + b + c);
            }
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
}
