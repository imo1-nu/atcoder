#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        A[a][b] = A[b][a] = 1;
    }

    int ans = 1e9;
    vector<int> P(N);
    iota(P.begin(), P.end(), 0);
    do {
        bool ok = true;
        vector<vector<int>> S(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            if (P[i] == i || P[P[i]] == i) ok = false;
            S[i][P[i]] = S[P[i]][i] = 1;
        }
        if (!ok) continue;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                sum += abs(A[i][j] - S[i][j]);
            }
        }
        ans = min(ans, sum);
    } while (next_permutation(P.begin(), P.end()));
    cout << ans << endl;
}
