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
    vector<vector<int>> A(N, vector<int>(M));
    vector<int> V;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
            V.push_back(A[i][j]);
        }
    }
    sort(V.begin(), V.end());

    vector<vector<int>> idx(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            idx[i][j] = lower_bound(V.begin(), V.end(), A[i][j]) - V.begin();
        }
    }

    ll ans = (ll)M * (M + 1) / 2 * N * (N - 1) / 2;
    atcoder::fenwick_tree<int> fw(N * M);
    for (int i = 0; i < M; i++) fw.add(idx[N - 1][i], 1);
    for (int i = N - 2; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            ans += fw.sum(0, idx[i][j]);
        }
        for (int j = 0; j < M; j++) fw.add(idx[i][j], 1);
    }
    cout << ans << endl;
}
