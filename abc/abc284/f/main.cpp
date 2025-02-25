#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint1000000007;

ll b = 100;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    string T;
    cin >> N >> T;
    vector<mint> B(2 * N + 1);
    B[0] = 1;
    for (int i = 1; i <= 2 * N; i++) {
        B[i] = B[i - 1] * b;
    }

    vector<mint> H1(N + 1), H2(N + 1);
    for (int i = 0; i < N; i++) {
        H1[0] = (H1[0] * b + (T[N + i] - 'a' + 1));
    }
    for (int i = 1; i <= N; i++) {
        H1[i] = H1[i - 1] + (T[i - 1] - T[N + i - 1]) * B[N - i];
    }

    for (int i = 0; i < N; i++) {
        H2[N] = (H2[N] * b + (T[2 * N - i - 1] - 'a' + 1));
    }
    for (int i = N - 1; i >= 0; i--) {
        H2[i] = H2[i + 1] - (T[N + i] - 'a' + 1) * B[N - 1];
        H2[i] *= b;
        H2[i] += (T[i] - 'a' + 1);
    }

    for (int i = 0; i <= N; i++) {
        if (H1[i] == H2[i]) {
            cout << T.substr(0, i) + T.substr(N + i, N - i) << '\n' << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}
