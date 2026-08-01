#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    int N = S.length();

    int ans = 0;
    for (int m = 0; m < N; m++) {
        int r = 0;
        int cnt = 0;
        while (m - r >= 0 && m + r < N) {
            if (S[m - r] != S[m + r]) {
                cnt++;
                if (cnt > 1) break;
            }
            r++;
        }
        ans += r;
        r = 0;
        cnt = 0;
        while (m - r >= 0 && m + r + 1 < N) {
            if (S[m - r] != S[m + r + 1]) {
                cnt++;
                if (cnt > 1) break;
            }
            r++;
        }
        ans += r;
    }
    cout << ans << endl;
}
