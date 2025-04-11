#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<int> A(2 * N);
    vector<vector<int>> pos(N);
    for (int i = 0; i < 2 * N; i++) {
        cin >> A[i];
        A[i]--;
        pos[A[i]].push_back(i);
    }
    set<pair<int, int>> S;
    for (int i = 0; i < 2 * N - 1; i++) {
        int a = A[i];
        int b = A[i + 1];
        if (pos[a][0] + 1 == pos[a][1] || pos[b][0] + 1 == pos[b][1]) continue;
        vector<int> v = {pos[a][0], pos[a][1], pos[b][0], pos[b][1]};
        sort(v.begin(), v.end());
        if (v[0] + 1 == v[1] && v[2] + 1 == v[3]) S.emplace(minmax(a, b));
    }
    cout << S.size() << '\n';
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
