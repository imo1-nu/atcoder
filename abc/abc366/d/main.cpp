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
    vector<vector<vector<int>>> A(N, vector<vector<int>>(N, vector<int>(N)));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                cin >> A[i][j][k];
            }
        }
    }
    vector<vector<vector<int>>> S(N + 1, vector<vector<int>>(N + 1, vector<int>(N + 1)));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                S[i][j][k] = S[i - 1][j][k] + S[i][j - 1][k] + S[i][j][k - 1] - S[i - 1][j - 1][k] - S[i - 1][j][k - 1] - S[i][j - 1][k - 1] + S[i - 1][j - 1][k - 1] + A[i - 1][j - 1][k - 1];
            }
        }
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        x1--;
        y1--;
        z1--;
        cout << S[x2][y2][z2] - S[x1][y2][z2] - S[x2][y1][z2] - S[x2][y2][z1] + S[x1][y1][z2] + S[x1][y2][z1] + S[x2][y1][z1] - S[x1][y1][z1] << endl;
    }
}
