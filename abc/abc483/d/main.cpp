#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

// https://github.com/imo1-nu/atcoder/tree/main/lib

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& a : A) cin >> a;

    vector<ll> pos(N + 1), l1(N + 1), r1(N + 1), l2(N + 1), r2(N + 1);
    for (int i = 0; i < N; i++) {
        pos[i + 1] = pos[i] + A[i];
        l1[i + 1] = min(l1[i], pos[i + 1]);
        r1[i + 1] = max(r1[i], pos[i + 1]);
    }

    l2[N] = r2[N] = pos[N];
    for (int i = N - 1; i >= 0; i--) {
        l2[i] = min(l2[i + 1], pos[i]);
        r2[i] = max(r2[i + 1], pos[i]);
    }

    ll ans = r1[N] - l1[N];
    for (int i = 0; i < N; i++) {
        ans = max(ans, max(r2[i + 1] - 2 * A[i], r1[i]) - min(l2[i + 1] - 2 * A[i], l1[i]));
    }
    cout << ans + 1 << endl;
}
