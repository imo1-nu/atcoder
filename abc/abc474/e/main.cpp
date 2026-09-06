#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    vector<pair<int, int>> diff(N);
    ll minA = 2e9;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        diff[i] = {A[i] - B[i], i};
        minA = min(minA, (ll)A[i]);
    }
    sort(diff.begin(), diff.end());

    ll sum = 0;
    for (int i = 0; i < (N + 1) / 2; i++) sum += A[diff[i].second];
    for (int i = (N + 1) / 2; i < N; i++) sum += B[diff[i].second];

    int idx;
    int cnt = N % 2;
    for (int idx = (N + 1) / 2; idx >= 0; idx--) {
        cnt -= 2;
        if (-cnt * minA > diff[idx - 1].first) break;
        sum -= diff[idx - 1].first + cnt * minA;
        cnt = 0;
    }
    cout << sum << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) solve();
}
