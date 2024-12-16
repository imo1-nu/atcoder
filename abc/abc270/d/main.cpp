#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    for (int i = 0; i < K; ++i) {
        cin >> A[i];
    }

    vector<pair<int, int>> ans(N + 1, {0, 0});
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < K; ++j) {
            if (i - A[j] < 0) continue;
            if (ans[i].first < ans[i - A[j]].second + A[j]) {
                ans[i] = {ans[i - A[j]].second + A[j], ans[i - A[j]].first};
            }
        }
    }
    cout << ans[N].first << endl;
}
