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
    vector<int> A(N);
    vector<vector<int>> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        x[i].resize(A[i]);
        y[i].resize(A[i]);
        for (int j = 0; j < A[i]; j++) {
            cin >> x[i][j] >> y[i][j];
            x[i][j]--;
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << N); i++) {
        bitset<15> bs(i);
        bool ok = true;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < A[j]; k++) {
                if (bs[j] && y[j][k] == 0) {
                    if (bs[x[j][k]]) {
                        ok = false;
                    }
                }
                if (bs[j] && y[j][k] == 1) {
                    if (!bs[x[j][k]]) {
                        ok = false;
                    }
                }
                if (!bs[j] && y[j][k] == 1) {
                    if (bs[x[j][k]]) {
                        ok = false;
                    }
                }
                if (!bs[j] && y[j][k] == 0) {
                    if (!bs[x[j][k]]) {
                        ok = false;
                    }
                }
            }
        }

        if (ok) {
            ans = max(ans, (int)bs.count());
        }
    }
    
    cout << ans << endl;
}
