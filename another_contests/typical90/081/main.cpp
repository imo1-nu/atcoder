#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<vector<int>> A(5000, vector<int>(5000)), S(5001, vector<int>(5001));
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        A[x][y]++;
    }

    for (int i = 1; i <= 5000; i++) {
        for (int j = 1; j <= 5000; j++) {
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i-1][j-1];
        }
    }

    int ans = 0;
    for (int i = 0; i < 5000-K; i++) {
        for (int j = 0; j < 5000-K; j++) {
            ans = max(ans, S[i+K+1][j+K+1] - S[i][j+K+1] - S[i+K+1][j] + S[i][j]);
        }
    }
    cout << ans << endl;
}
