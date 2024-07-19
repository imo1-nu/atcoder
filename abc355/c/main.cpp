#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, T;
    cin >> N >> T;
    

    vector<vector<int>> B(N, vector<int>(N));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) B[i][j] = N * i + j + 1;
    vector<int> G(N + 1, N);
    vector<int> R(N + 1, N);
    vector<int> M(2, N);

    int ans = -1;
    vector<int> A(T);
    for (int i = 0; i < T; i++) cin >> A[i];
    for (int i = 0; i < T; i++) {
        int a;
        a = A[i];
        int b, c;
        b = (a - 1) / N + 1;
        c = (a - 1) % N + 1;
        B[b - 1][c - 1] = 0;
        /*for (int k = 0; k < N; k++) {
            for (int l = 0; l < N; l++) {
                cout << B[k][l];
            }
            cout << endl;
        }
        cout << endl;*/
        G[b]--;
        R[c]--;
        if (b == c) M[0]--;
        if (b + c == N + 1) M[1]--;
        //cout << M[0] << ' ' << M[1] << endl;
        if (G[b] == 0 || R[c] == 0 || M[0] == 0 || M[1] == 0) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;
}
