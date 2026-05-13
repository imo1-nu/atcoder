#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    map<pair<int, int>, vector<int>> cloths;
    map<int, vector<int>> L, R;
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        cloths[{-l, r}].push_back(i);
        L[l].push_back(r);
        R[r].push_back(l);
    }
    for (auto& [_, v] : L) sort(v.begin(), v.end());
    for (auto& [_, v] : R) sort(v.begin(), v.end());

    vector<bool> naihou(M, false);
    set<int> checked;
    for (auto& [k, v] : cloths) {
        int l = -k.first, r = k.second;
        for (auto idx : v) {
            auto itr = checked.upper_bound(r);
            if (itr != checked.begin()) naihou[idx] = true;
        }
        checked.insert(r);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int s, t;
        cin >> s >> t;
        s--;
        // cout << '[' << s << ", " << t << ") ";
        if (cloths[{-s, t}].size() > 1) {
            cout << "Yes" << endl;
            continue;
        }
        else if (cloths[{-s, t}].size() == 1) {
            cout << (naihou[cloths[{-s, t}][0]] ? "Yes" : "No") << endl;
            continue;
        }
        // cout << "i: ";
        if (L[s].empty() || R[t].empty()) {
            cout << "No" << endl;
            continue;
        }
        int r = upper_bound(L[s].begin(), L[s].end(), t) - L[s].begin() - 1;
        int l = lower_bound(R[t].begin(), R[t].end(), s) - R[t].begin();

        // if (r >= 0) cout << '[' << s << ',' << L[s][r] << ')' << ", ";
        // if (l < R[t].size()) cout << '[' << R[t][l] << ',' << t << ')' << endl;

        if (r < 0 || l == R[t].size() || L[s][r] < R[t][l]) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
}
