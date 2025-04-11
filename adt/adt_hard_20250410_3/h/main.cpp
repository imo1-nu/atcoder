#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> S(N - 1), X(M);
    for (int i = 0; i < N - 1; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> X[i];
    }
    vector<ll> A(N);
    for (int i = 1; i < N; i++) {
        A[i] = S[i - 1] - A[i - 1];
    }
    map<ll, int> mp;
    for (int i = 0; i < N; i++) {
        for (auto x : X) {
            if (i % 2 == 0) mp[x - A[i]]++;
            else mp[A[i] - x]++;
        }
    }
    int ans = 0;
    for (auto [x, c] : mp) {
        ans = max(ans, c);
    }
    cout << ans << endl;
}
