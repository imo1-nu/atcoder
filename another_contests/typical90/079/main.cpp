#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W)), B(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> B[i][j];
        }
    }

    ll ans = 0;
    for (int i = 0; i < H-1; ++i) {
        for (int j = 0; j < W-1; ++j) {
            int diff = B[i][j] - A[i][j];
            A[i][j] += diff;
            A[i+1][j] += diff;
            A[i][j+1] += diff;
            A[i+1][j+1] += diff;
            ans += abs(diff);
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] != B[i][j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    cout << ans << endl;
}
