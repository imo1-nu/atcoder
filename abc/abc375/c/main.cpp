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
    vector<string> G(N);
    for (int i = 0; i < N; i++) {
        cin >> G[i];
    }

    vector<string> G2 = G;
    
    for (int i = 0; i < N / 2; i++) {
        int cnt = (i + 1) % 4;

        vector<vector<char>> A(4);
        for (int j = i; j < N - i; j++) {
            A[0].push_back(G[i][j]);
        }

        for (int j = i; j < N - i; j++) {
            A[1].push_back(G[j][N - i - 1]);
        }
        
        for (int j = N - i - 1; j >= i; j--) {
            A[2].push_back(G[N - i - 1][j]);
        }
        
        for (int j = N - i - 1; j >= i; j--) {
            A[3].push_back(G[j][i]);
        }

        for (int j = i; j < N - i; j++) {
            G[i][j] = A[(-cnt + 4) % 4][j - i];
        }

        for (int j = i; j < N - i; j++) {
            G[j][N - i - 1] = A[(-cnt + 5) % 4][j - i];
        }

        for (int j = N - i - 1; j >= i; j--) {
            G[N - i - 1][j] = A[(-cnt + 6) % 4][N - j - 1 - i];
        }

        for (int j = N - i - 1; j >= i; j--) {
            G[j][i] = A[(-cnt + 7) % 4][N - j - 1 - i];
        }
    }
    for (int i = 0; i < N; i++) {
        cout << G[i] << endl;
    }
}
