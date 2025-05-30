#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int maxA = *max_element(A.begin(), A.end());
    vector<vector<int>> pos(maxA + 1);
    for (int i = 0; i < N; i++) {
        pos[A[i]].push_back(i);
    }
    set<int> S = {-1, N};
    vector<ll> ans(N + 3);
    for (int i = maxA; i >= 0; i--) {
        for (int j : pos[i]) {
            auto itr = S.lower_bound(j);
            int r = *itr - j - 1;
            itr--;
            int l = j - *itr - 1;
            int mn = min(l, r);
            int mx = max(l, r);
            ans[1] += i;
            ans[mn + 2] -= i;
            ans[mx + 2] -= i;
            ans[mn + mx + 3] += i;
            S.insert(j);
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= N; j++) {
            ans[j] += ans[j - 1];
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << endl;
    }
}
