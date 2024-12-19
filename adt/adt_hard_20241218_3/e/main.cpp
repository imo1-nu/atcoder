#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

#define INF 1e9

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> Q(N), A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> Q[i];
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    vector<vector<int>> cntB(N, vector<int>(1000001, -INF));
    for (int i = 0; i < N; ++i) {
        for (ll j = 0; j <= 1000000; ++j) {
            ll q = Q[i] - j * A[i];
            if (q < 0) break;
            if (B[i] == 0) {
                cntB[i][j] = INF;
                continue;
            }
            cntB[i][j] = q / B[i];
        }
    }

    int ans = 0;
    for (int i = 0; i <= 1000000; ++i) {
        int cnt = INF;
        for (int j = 0; j < N; ++j) {
            cnt = min(cnt, cntB[j][i]);
        }
        ans = max(ans, i + cnt);
    }
    cout << ans << endl;
}
