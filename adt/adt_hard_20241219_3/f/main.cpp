#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    int ans = N;
    for (int i = 0; i < (1 << N); ++i) {
        int cnt = __builtin_popcount(i);
        vector<bool> ok(M);
        for (int j = 0; j < N; ++j) {
            if ((i >> j & 1) == 0) continue;
            for (int k = 0; k < M; ++k) {
                if (S[j][k] == 'o') ok[k] = true;
            }
        }
        for (int j = 0; j < M; ++j) {
            if (!ok[j]) {
                cnt = N;
                break;
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}
