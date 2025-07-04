#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll L, R;
    cin >> L >> R;
    int mx = 10000000;
    vector<int> A(mx + 1);
    vector<int> cnt(R - L + 1);
    for (int i = 2; i <= mx; i++) {
        if (A[i] != 0) continue;
        for (int j = i; j <= mx; j += i) {
            A[j]++;
        }

        ll j = L;
        if (L % i > 0) j += i - L % i;
        for (; j <= R; j += i) {
            cnt[j - L]++;
        }
        for (ll j = i; j <= R; j *= i) {
            if (j < L) continue;
            cnt[j - L] = 0;
        }
    }

    int ans = 1;
    for (int i = 1; i <= R - L; i++) {
        if (cnt[i] == 0) ans++;
    }
    cout << ans << endl;
}
