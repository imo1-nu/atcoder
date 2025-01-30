#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W, A, B;
    cin >> H >> W >> A >> B;

    int ans = 0;
    function<void(int, int, int, int)> dfs = [&](int i, int bit, int a, int b) {
        if (i == H * W) {
            ans++;
            return;
        }
        if (bit >> i & 1) return dfs(i + 1, bit, a, b);
        if (b) dfs(i + 1, bit | 1 << i, a, b - 1);
        if (a) {
            if (i % W != W - 1 && (bit >> (i + 1) & 1) == 0) dfs(i + 1, bit | 1 << i | 1 << (i + 1), a - 1, b);
            if (i + W < H * W) dfs(i + 1, bit | 1 << i | 1 << (i + W), a - 1, b);
        }
    };
    dfs(0, 0, A, B);
    cout << ans << endl;
}
