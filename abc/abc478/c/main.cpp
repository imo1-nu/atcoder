#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (auto& a : A) cin >> a;

    auto sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    int mn = N, mx = -1;
    for (int i = 0; i < N; i++) {
        if (A[i] != sorted_A[i]) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }
    if (mx - mn < K) cout << "Yes" << endl;
    else cout << "No" << endl;
}
