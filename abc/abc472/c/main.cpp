#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    for (auto& a : A) cin >> a;
    ll sum = 0;
    vector<bool> ans(N);
    for (int i = 0; i < N; i++) {
        if (i >= M) sum -= A[i - M] * ans[i - M];
        if (sum + A[i] <= K) {
            sum += A[i];
            ans[i] = true;
        }
    }
    for (auto ok : ans) {
        cout << (ok ? "Yes" : "No") << endl;
    }
}
