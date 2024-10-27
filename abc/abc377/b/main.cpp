#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N = 8;
    vector<string> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    vector<bool> row(N), col(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (S[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; j++) {
            if (!row[i] && !col[j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
