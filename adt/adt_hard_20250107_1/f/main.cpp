#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    vector<int> H(3), W(3);
    for (int i = 0; i < 3; i++) cin >> H[i];
    for (int i = 0; i < 3; i++) cin >> W[i];

    int ans = 0;
    for (int i0 = 1; i0 <= H[0] - 2; i0++) {
        for (int i1 = 1; i1 <= H[0] - i0 - 1; i1++) {
            for (int i2 = 1; i2 <= H[1] - 2; i2++) {
                for (int i3 = 1; i3 <= H[1] - i2 - 1; i3++) {
                    vector<vector<int>> A(2, vector<int>(3));
                    A[0][0] = i0;
                    A[0][1] = i1;
                    A[0][2] = H[0] - i0 - i1;
                    A[1][0] = i2;
                    A[1][1] = i3;
                    A[1][2] = H[1] - i2 - i3;

                    bool ok = true;
                    if (W[0] - A[0][0] - A[1][0] <= 0) ok = false;
                    if (W[1] - A[0][1] - A[1][1] <= 0) ok = false;
                    if (W[2] - A[0][2] - A[1][2] <= 0) ok = false;
                    if ((W[0] - A[0][0] - A[1][0]) + (W[1] - A[0][1] - A[1][1]) + (W[2] - A[0][2] - A[1][2]) != H[2]) ok = false;
                    if (ok) ans++;
                }
            }
        }
    }

    cout << ans << endl;
}
