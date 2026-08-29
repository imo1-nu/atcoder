#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    for (int i = N - 1; i >= 0; i--) {
        X[i] -= X[0];
        Y[i] -= Y[0];
    }

    while (Q--) {
        int u, v;
        u--; v--;
        
    }
}
