#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N * 2);
    for (int i = 0; i < N * 2; i++) {
        cin >> A[i];
    }
    priority_queue<int> pq;
    ll ans = 0;
    for (int i = 0; i < N * 2; i++) {
        pq.push(A[i]);
        if (pq.size() > (i + 1) / 2) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
