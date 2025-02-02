#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using T = tuple<ll, int, int, int>;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) cin >> C[i];
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());
    auto f = [&](int i, int j, int k) {
        return A[i] * B[j] + B[j] * C[k] + C[k] * A[i];
    };

    vector<ll> dp(K + 1);
    int cur = 0;
    priority_queue<T> pq;
    pq.emplace(f(0, 0, 0), 0, 0, 0);
    set<tuple<int, int, int>> S;
    S.emplace(0, 0, 0);
    while (cur < K) {
        auto [val, i, j, k] = pq.top();
        pq.pop();
        dp[++cur] = val;
        if (i + 1 < N && !S.count({i + 1, j, k})) {
            pq.emplace(f(i + 1, j, k), i + 1, j, k);
            S.emplace(i + 1, j, k);
        }
        if (j + 1 < N && !S.count({i, j + 1, k})) {
            pq.emplace(f(i, j + 1, k), i, j + 1, k);
            S.emplace(i, j + 1, k);
        }
        if (k + 1 < N && !S.count({i, j, k + 1})) {
            pq.emplace(f(i, j, k + 1), i, j, k + 1);
            S.emplace(i, j, k + 1);
        }
    }
    cout << dp[K] << endl;
}
