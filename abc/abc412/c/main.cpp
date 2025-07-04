#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<int> S(N - 2);
    int s1, sn;
    cin >> s1;
    for (int i = 0; i < N - 2; i++) {
        cin >> S[i];
    }
    cin >> sn;
    sort(S.begin(), S.end());

    int mx = s1;
    int ans = 2;
    while (mx * 2 < sn) {
        int idx = upper_bound(S.begin(), S.end(), mx * 2) - S.begin();
        if (idx == 0) break;
        idx--;
        if (mx >= S[idx]) break;
        mx = S[idx];
        ans++;
    }
    if (mx * 2 >= sn) cout << ans << endl;
    else cout << -1 << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) solve();
}
