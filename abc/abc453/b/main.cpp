#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T, X;
    cin >> T >> X;
    vector<int> A(T + 1);
    for (int i = 0; i <= T; i++) cin >> A[i];

    queue<pair<int, int>> ans;
    ans.push({0, A[0]});
    for (int i = 1; i <= T; i++) {
        if (abs(A[i] - ans.back().second) >= X) ans.push({i, A[i]});
    }

    while (!ans.empty()) {
        cout << ans.front().first << ' ' << ans.front().second << endl;
        ans.pop();
    }
}
