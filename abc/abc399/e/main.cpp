#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    string S, T;
    cin >> N >> S >> T;
    vector<vector<int>> idxS(26), idxT(26);
    for (int i = 0; i < N; i++) {
        idxS[S[i] - 'a'].push_back(i);
        idxT[T[i] - 'a'].push_back(i);
    }

    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (idxT[i].size() > 0) cnt++;
    }
    if (cnt == 26 && S != T) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < idxS[i].size(); j++) {
            int x = T[idxS[i][0]] - 'a';
            auto it = lower_bound(idxT[x].begin(), idxT[x].end(), idxS[i][j]);
            if (it == idxT[x].end()) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (idxS[i].size() == 0) continue;
        if (S[idxS[i][0]] != T[idxS[i][0]]) ans++;
    }

    cout << ans << endl;
}
