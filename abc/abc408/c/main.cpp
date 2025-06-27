#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        A[l]++;
        A[r]--;
    }
    vector<int> B(N + 1);
    for (int i = 1; i <= N; i++) {
        B[i] = B[i - 1] + A[i - 1];
    }
    int ans = *min_element(B.begin() + 1, B.end());
    cout << ans << endl;
}
