#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> P(N, vector<int>(2));
    // P[inv[i]] = i;
    for (int i = 0; i < N; i++) {
        cin >> P[i][0];
        P[i][0]--;
        P[P[i][0]][1] = i;
    }
    bool flip = false;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            swap(P[x][flip], P[y][flip]);
            swap(P[P[x][flip]][!flip], P[P[y][flip]][!flip]);
        }
        else flip = !flip;
        // for (auto p : P) cout << p[flip] + 1 << ' ';
        // cout << endl;
        // for (auto p : P) cout << p[!flip] + 1 << ' ';
        // cout << endl << endl;

    }
    for (auto p : P) cout << p[flip] + 1 << ' ';
    cout << endl;
}
