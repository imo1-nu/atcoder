#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using Graph = vector<vector<int>>;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    vector<vector<int>> dp(1 << N, vector<int>(26));
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            if (!(i >> j & 1)) continue;
            dp[i][S[j].front() - 'a'] |= !dp[i ^ (1 << j)][S[j].back() - 'a'];
        }
    }

    bool ans = false;
    for (int i = 0; i < N; i++) {
        ans |= dp[(1 << N) - 1][S[i].front() - 'a'];
    }
    if (ans) cout << "First" << endl;
    else cout << "Second" << endl;
}
