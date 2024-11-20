#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    int M;
    cin >> M;
    vector<vector<int>> NG(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        NG[x].push_back(y);
        NG[y].push_back(x);
    }

    string S = "0123456789";
    S = S.substr(0, N);
    int ans = 1e9;
    do {
        bool ok = true;
        for (int i = 0; i < N - 1; i++) {
            if (!ok) break;
            for (int j : NG[S[i] - '0']) {
                if (S[i + 1] == j + '0') {
                    ok = false;
                    break;
                }
            }
        }
        
        if (ok) {
            int sum = 0;
            for (int i = 0; i < N; i++) {
                sum += A[S[i] - '0'][i];
            }
            ans = min(ans, sum);
        }
    } while (next_permutation(S.begin(), S.end()));
    if (ans == 1e9) ans = -1;
    cout << ans << endl;
}
