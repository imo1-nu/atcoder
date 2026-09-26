#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int Q;
    string S, T;
    cin >> Q >> S >> T;
    int N = S.length();
    int M = T.length();
    vector<int> A(N), sum(N + 1);
    for (int i = 0; i < N - M + 1; i++) {
        bool ok = true;
        for (int j = 0; j < M; j++) {
            if (S[i + j] != T[j]) ok = false;
        }
        if (ok) A[i] = 1;
    }
    for (int i = 1; i <= N; i++) sum[i] = sum[i - 1] + A[i - 1];

    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--;
        if (r - M + 1 < 0) {
            cout << "No" << endl;
            continue;
        }
        if (sum[r - M + 1] - sum[l] > 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
