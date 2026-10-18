#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<string> S(N), T(M);
    for (auto& s : S) cin >> s;
    for (auto& t : T) cin >> t;

    vector<int> ans(N);
    for (auto t : T) {
        bool ok = false;
        for (int i = 0; i < N; i++) {
            if (S[i] == t) {
                ans[i]++;
                ok = true;
                break;
            }
        }
        if (ok) continue;
        vector<int> candidates;
        for (int i = 0; i < N; i++) {
            if (S[i].length() != t.length()) continue;
            int diff = 0;
            for (int j = 0; j < t.length(); j++) {
                if (S[i][j] != t[j]) diff++;
            }
            if (diff == 1) candidates.push_back(i);
        }
        if (candidates.size() == 1) ans[candidates[0]]++;
    }

    for (auto x : ans) cout << x << endl;
}
