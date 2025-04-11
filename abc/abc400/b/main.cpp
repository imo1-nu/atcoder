#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(M + 1);
    A[0] = 1;
    for (int i = 1; i <= M; i++) {
        if (A[i - 1] > int(1e9) / N) {
            cout << "inf" << endl;
            return 0;
        }
        A[i] = A[i - 1] * N;
    }
    int ans = 0;
    for (int i = 0; i <= M; i++) {
        ans += A[i];
        if (ans > int(1e9)) {
            cout << "inf" << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
