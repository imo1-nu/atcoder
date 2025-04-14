#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    if (N < K) {
        cout << 1 << endl;
        return 0;
    }

    vector<int> A(N + 1);
    for (int i = 0; i < K; i++) {
        A[i] = 1;
    }
    ll S = K;
    int M = 1e9;
    for (int i = K; i < N; i++) {
        A[i] = S;
        S += M - A[i - K];
        S %= M;
        S += A[i];
        S %= M;
    }
    cout << S << endl;
}
