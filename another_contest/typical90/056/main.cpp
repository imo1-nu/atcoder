#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, S;
    cin >> N >> S;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }

    vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= S; ++j) {
            if (j - A[i - 1] >= 0) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - A[i - 1]];
            }
            if (j - B[i - 1] >= 0) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - B[i - 1]];
            }
        }
    }

    if (dp[N][S]) {
        stack<char> ans;
        int i = N, j = S;
        while (i > 0) {
            if (j - A[i - 1] >= 0 && dp[i - 1][j - A[i - 1]]) {
                ans.push('A');
                j -= A[i - 1];
            }
            else {
                ans.push('B');
                j -= B[i - 1];
            }
            i--;
        }
        while (!ans.empty()) {
            cout << ans.top();
            ans.pop();
        }
        cout << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
}
