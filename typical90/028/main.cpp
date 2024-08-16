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
    vector<vector<int>> A(1002, vector<int>(1002, 0));
    for (int i = 0; i < N; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        A[lx][ly]++;
        A[rx][ry]++;
        A[lx][ry]--;
        A[rx][ly]--;
    }
    
    vector<vector<int>> S(1002, vector<int>(1002, 0));
    for (int i = 1; i <= 1001; i++) {
        for (int j = 1; j <= 1001; j++) {
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + A[i - 1][j - 1];
        }
    }

    vector<int> ans(N + 1, 0);
    for (int i = 1; i <= 1001; i++) {
        for (int j = 1; j <= 1001; j++) {
            ans[S[i][j]]++;
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << endl;
    }
}
