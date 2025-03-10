#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> B(N), W(M);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> W[i];
    }
    sort(B.rbegin(), B.rend());
    sort(W.rbegin(), W.rend());
    int i = 0, j = 0;
    ll ans = 0;
    while (i < N && B[i] > 0) {
        ans += B[i];
        i++;
    }
    while (j < M && j < i && W[j] > 0) {
        ans += W[j];
        j++;
    }
    while (i < N && j < M && B[i] + W[j] > 0) {
        ans += B[i] + W[j];
        i++;
        j++;
    }
    cout << ans << '\n';
}
