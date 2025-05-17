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
    vector<int> W(N), B(N);
    for (int i = 0; i < N; i++) cin >> W[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    vector<vector<int>> grundy(51, vector<int>(1326));
    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j <= 1325; j++) {
            vector<bool> Transit(700);
            if (i >= 1) Transit[grundy[i - 1][j + i]] = true;
            if (j >= 2) {
                for (int k = 1; k <= j / 2; k++) {
                    Transit[grundy[i][j - k]] = true;
                }
            }
            for (int k = 0; k < 700; k++) {
                if (!Transit[k]) {
                    grundy[i][j] = k;
                    break;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans ^= grundy[W[i]][B[i]];
    }
    cout << (ans ? "First" : "Second") << endl;
}
    
