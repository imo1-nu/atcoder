#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll mod = 998244353;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        int t, x;
        cin >> t;
        for (int j = 0; j < t; j++) {
            cin >> x;
            A[i][x - 1] = 1;
        }
    }
    vector<int> S(M);
    for (int i = 0; i < M; i++) {
        cin >> S[i];
    }

    int pos = 0;
    for (int i = 0; i < M; i++) {
        bool ok = false;
        for (int j = pos; j < N; j++) {
            if (A[j][i] == 1) {
                swap(A[j], A[pos]);
                ok = true;
                break;
            }
        }

        if (ok) {
            for (int j = 0; j < N; j++) {
                if (j != pos && A[j][i] == 1) {
                    for (int k = 0; k < M; k++) {
                        A[j][k] ^= A[pos][k];
                    }
                }
            }
            if (S[i] == 1) {
                for (int j = 0; j < M; j++) {
                    S[j] ^= A[pos][j];
                }
            }
            pos++;
        }
    }

    if (S == vector<int>(M, 0)) {
        int ans = 1;
        for (int i = pos; i < N; i++) {
            ans *= 2;
            ans %= mod;
        }
        cout << ans << endl;
    }
    else {
        cout << 0 << endl;
    }
}