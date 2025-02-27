#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> L(N + 2), R(N + 2);
    for (int i = 1; i <= N; i++) L[i] = min(L[i - 1] + 1, A[i - 1]);
    for (int i = N; i >= 1; i--) R[i] = min(R[i + 1] + 1, A[i - 1]);
    int ans = 0;
    for (int i = 1; i <= N; i++) ans = max(ans, min(L[i], R[i]));
    cout << ans << '\n';
}
