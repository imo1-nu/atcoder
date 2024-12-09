#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S, T;
    cin >> S >> T;
    int N = S.size();
    string S2 = S + S;
    vector<vector<int>> next(2 * N + 1, vector<int>(26, -1e8));
    for (int i = 2 * N - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            next[i][j] = next[i + 1][j] + 1;
        }
        next[i][S2[i] - 'a'] = 0;
    }

    ll cur = 0;
    for (int i = 0; i < (int)T.length(); i++) {
        if (next[cur % N][T[i] - 'a'] < 0) {
            cout << -1 << endl;
            return 0;
        }
        cur += next[cur % N][T[i] - 'a'] + 1;
    }
    cout << cur << endl;
}
