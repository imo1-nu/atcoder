#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    vector<vector<bool>> Z(N, vector<bool>(M));
    for (int i = 0; i < M; i++) {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++) {
            int x;
            cin >> x;
            x--;
            Z[x][i] = true;
        }
    }

    vector<int> pow3(N + 1);
    pow3[0] = 1;
    for (int i = 1; i <= N; i++) {
        pow3[i] = pow3[i - 1] * 3;
    }
    ll ans = 1e18;
    for (int i = 0; i < pow3[N]; i++) {
        vector<int> cnt(M);
        ll cost = 0;
        for (int j = 0; j < N; j++) {
            int k = (i / pow3[j]) % 3;
            cost += C[j] * k;
            for (int l = 0; l < M; l++) {
                if (Z[j][l]) cnt[l] += k;
            }
        }
        bool ok = true;
        for (int i = 0; i < M; i++) {
            if (cnt[i] < 2) ok = false;
        }
        if (ok) ans = min(ans, cost);
    }
    cout << ans << endl;
}
