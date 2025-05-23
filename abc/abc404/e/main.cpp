#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N), C(N);
    for (int i = 1; i < N; i++) {
        cin >> C[i];
    }
    for (int i = 1; i < N; i++) {
        cin >> A[i];
    }
    A[0] = 1;

    int ans = 0;
    for (int i = N - 1; i > 0; i--) {
        if (A[i] == 0) continue;
        int mn = i - C[i], mx = i - 1;
        int cnt = 1;
        while (1) {
            int mn2 = 1e9, mx2 = 0;
            bool ok = false;
            for (int j = mn; j <= mx; j++) {
                if (A[j] > 0) {
                    ok = true;
                    break;
                }
                mn2 = min(mn2, j - C[j]);
                mx2 = max(mx2, j - 1);
            }
            if (ok) break;
            mn = mn2;
            mx = mx2;
            cnt++;
        }
        ans += cnt;
    }
    cout << ans << endl;
}
