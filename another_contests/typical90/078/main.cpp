#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        --A, --B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j : G[i]) {
            if (i > j) cnt++;
        }
        if (cnt == 1) ans++;
    }

    cout << ans << endl;
}
