#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    while (1) {
        int M, T, P, R;
        cin >> M >> T >> P >> R;
        if (M == 0 && T == 0 && P == 0 && R == 0) break;
        vector<pair<int, set<int>>> results(T);
        vector<vector<int>> cnt(T, vector<int>(11, 0));
        for (int i = 0; i < R; i++) {
            int m, t, p, j;
            cin >> m >> t >> p >> j;
            t--;
            if (j != 0) {
                if (!results[t].second.count(p)) cnt[t][p]++;
                continue;
            }
            if (results[t].second.count(p)) continue;
            results[t].first += m;
            results[t].second.insert(p);
        }

        vector<tuple<int, int, int>> A(T);
        for (int i = 0; i < T; i++) {
            int num = 0;
            for (int j = 0; j < 11; j++) {
                if (results[i].second.count(j)) num += cnt[i][j];
            }
            A[i] = {-results[i].second.size(), results[i].first + 20 * num, -(i + 1)};
        }
        sort(A.begin(), A.end());
        cout << -get<2>(A[0]);
        for (int i = 1; i < T; i++) {
            if (get<0>(A[i - 1]) == get<0>(A[i]) && get<1>(A[i - 1]) == get<1>(A[i])) cout << '=' << -get<2>(A[i]);
            else cout << ',' << -get<2>(A[i]);
        }
        cout << endl;
    }
}
