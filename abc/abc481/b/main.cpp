#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

// https://github.com/imo1-nu/atcoder/tree/main/lib

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (auto& a : A) cin >> a;

    int ans = 0;
    if (A[0] == K) ans++;
    for (int i = 0; i < N - 1; i++) {
        if (A[i] < K && A[i + 1] >= K || A[i] > K && A[i + 1] <= K) ans++;
    }
    cout << ans << endl;
}
