#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<vector<int>> D(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> D[i][j];
        }
    }
    int Q;
    cin >> Q;
    vector<int> P(Q);
    for (int i = 0; i < Q; i++) {
        cin >> P[i];
    }

    vector<vector<int>> S(N+1, vector<int>(N+1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + D[i-1][j-1];
        }
    }

    vector<int> MAX(N * N + 1);
    for (int x1 = 0; x1 < N; x1++) {
        for (int x2 = x1 + 1; x2 <= N; x2++) {
            for (int y1 = 0; y1 < N; y1++) {
                for (int y2 = y1 + 1; y2 <= N; y2++) {
                    int S1 = S[x2][y2] - S[x1][y2] - S[x2][y1] + S[x1][y1];
                    MAX[(x2-x1)*(y2-y1)] = max(MAX[(x2-x1)*(y2-y1)], S1);
                }
            }
        }
    }

    vector<int> ans(N * N + 1);
    for (int i = 1; i <= N * N; i++) {
        ans[i] = max(ans[i-1], MAX[i]);
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[P[i]] << endl;
    }
}
