#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;



int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    ll K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    K %= 16384;
    while (K--) {
        vector<int> S(N + 1);
        for (int i = 1; i <= N; i++) {
            S[i] = S[i - 1] ^ A[i - 1];
        }
        for (int i = 0; i < N; i++) {
            A[i] = S[i + 1];
        }
    }
    for (int i = 0; i < N; i++) {
        if (i < N - 1) cout << A[i] << ' ';
        else cout << A[i] << '\n';
    }
}
