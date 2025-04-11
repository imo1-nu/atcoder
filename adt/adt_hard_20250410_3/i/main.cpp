#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using T = tuple<int, int, int>;
using P = pair<ll, T>;

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
        return P(A[i] * B[j] + B[j] * C[k] + C[k] * A[i], T(i, j, k));
    };

    priority_queue<P> pq;
    set<T> S;
    pq.emplace(f(0, 0, 0));
    S.insert(T(0, 0, 0));
    vector<ll> ans;
    while (!pq.empty() && ans.size() < K) {
        auto [s, t] = pq.top();
        pq.pop();
        ans.push_back(s);
        auto [i, j, k] = t;
        if (i + 1 < N && !S.count(T(i + 1, j, k))) {
            pq.emplace(f(i + 1, j, k));
            S.insert(T(i + 1, j, k));
        }
        if (j + 1 < N && !S.count(T(i, j + 1, k))) {
            pq.emplace(f(i, j + 1, k));
            S.insert(T(i, j + 1, k));
        }
        if (k + 1 < N && !S.count(T(i, j, k + 1))) {
            pq.emplace(f(i, j, k + 1));
            S.insert(T(i, j, k + 1));
        }
    }
    cout << ans.back() << endl;
}
