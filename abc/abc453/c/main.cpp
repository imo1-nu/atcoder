#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> L(N);
    for (auto& l : L) cin >> l;

    int ans = 0;
    for (int i = 0; i < (1 << N); i++) {
        int count = 0;
        ll cur = 1;
        for (int j = 0; j < N; j++) {
            int add = ((i >> j) % 2) ? 2 * L[j] : -2 * L[j];
            ll next = cur + add;
            if (cur / abs(cur) * next < 0) count++;
            cur = next;
        }
        ans = max(ans, count);
    }
    cout << ans << endl;
}
