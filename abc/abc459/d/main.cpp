#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

void solve() {
    string S;
    cin >> S;

    vector<int> cnt(26);
    for (auto c : S) cnt[c - 'a']++;
    int mx = 0;
    for (int i = 0; i < 26; i++) mx = max(mx, cnt[i]);
    if (mx > ((int)S.length() + 1) / 2) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;

    int prev = -1;
    string T;
    for (int i = 0; i < (int)S.length(); i++) {
        int idx = -1;
        int num = 0;
        for (int i = 0; i < 26; i++) {
            if (i == prev) continue;
            if (cnt[i] > num) {
                idx = i;
                num = cnt[i];
            }
        }
        T += idx + 'a';
        cnt[idx]--;
        prev = idx;
    }
    cout << T << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) solve();
}
