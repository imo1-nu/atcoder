#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

#define INF 1e9

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<string> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    vector<vector<int>> A(N, vector<int>(N, 1e9));
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        q.push({i, i});
        A[i][i] = 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j || C[i][j] == '-') continue;
            q.push({i, j});
            A[i][j] = 1;
        }
    }

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < N; k++) {
            for (int l = 0; l < N; l++) {
                if (C[k][i] != '-' && C[j][l] != '-' && C[k][i] == C[j][l] && A[k][l] == INF) {
                    A[k][l] = A[i][j] + 2;
                    q.push({k, l});
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] == INF) cout << -1 << " ";
            else cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
