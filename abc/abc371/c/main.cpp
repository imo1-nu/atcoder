#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Mg, Mh;
    cin >> N;
    vector<vector<bool>> G(N, vector<bool>(N, false));
    cin >> Mg;
    for (int i = 0; i < Mg; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a][b] = G[b][a] = true;
    }

    cin >> Mh;
    vector<int> a(Mh), b(Mh);
    for (int i = 0; i < Mh; i++) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            cin >> A[i][j];
        }
    }

    int ans = 1e9;
    vector<int> perm(N);
    for (int i = 0; i < N; i++) {
        perm[i] = i;
    }
    
    do {
        vector<vector<bool>> H(N, vector<bool>(N, false));
        for (int i = 0; i < Mh; i++) {
            H[a[i]][b[i]] = H[b[i]][a[i]] = true;
        }

        int sum = 0;
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                if (G[perm[i]][perm[j]] != H[i][j]) {
                    sum += A[i][j];
                }
            }
        }
        ans = min(ans, sum);
    } while (next_permutation(perm.begin(), perm.end()));
    
    cout << ans << endl;
}
