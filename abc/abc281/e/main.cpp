#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> B(M);
    for (int i = 0; i < M; i++) B[i] = A[i];
    sort(B.begin(), B.end());
    multiset<int> S1, S2;
    ll ans = 0;
    for (int i = 0; i < K; i++) {
        S1.insert(B[i]);
        ans += B[i];
    }
    for (int i = K; i < M; i++) {
        S2.insert(B[i]);
    }
    cout << ans << ' ';
    for (int i = 1; i < N - M + 1; i++) {
        if (S1.count(A[i - 1])) {
            S1.erase(S1.find(A[i - 1]));
            ans -= A[i - 1];
        }
        else {
            S2.erase(S2.find(A[i - 1]));
        }
        S2.insert(A[i + M - 1]);
        if (S1.size() < K) {
            S1.insert(*S2.begin());
            ans += *S2.begin();
            S2.erase(S2.begin());
        }
        else if (*S1.rbegin() > *S2.begin()) {
            int x = *S1.rbegin();
            int y = *S2.begin();
            S1.erase(S1.find(x));
            S2.erase(S2.find(y));
            S1.insert(y);
            S2.insert(x);
            ans += y - x;
        }
        cout << ans << ' ';
    }
    cout << endl;
}
