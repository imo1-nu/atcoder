#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector<int> dp(N + 1, INF);
    dp[0] = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int j = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
        dp[j] = A[i];
        ans = max(ans, j);
    }
    cout << ans << endl;
}
