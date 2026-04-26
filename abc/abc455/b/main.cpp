#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (auto& s : S) cin >> s;
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int i2 = i; i2 < H; i2++) {
                for (int j2 = j; j2 < W; j2++) {
                    bool ok = true;
                    for (int i3 = i; i3 <= i2; i3++) {
                        for (int j3 = j; j3 <= j2; j3++) {
                            if (S[i3][j3] != S[i + i2 - i3][j + j2 - j3]) ok = false;
                        }
                    }
                    if (ok) ans++;
                }
            }
        }
    }
    cout << ans << endl;
}
