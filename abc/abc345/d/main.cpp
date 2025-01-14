#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, H, W;
    cin >> N >> H >> W;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    vector<int> pow3(N + 1);
    pow3[0] = 1;
    for (int i = 1; i <= N; i++) {
        pow3[i] = pow3[i - 1] * 3;
    }

    auto check = [&](vector<pair<int, int>> &tiles) {
        set<pair<int, int>> st;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                st.insert({i, j});
            }
        }
        pair<int, int> mn = {0, 0};
        bool res = true;
        for (auto [a, b] : tiles) {
            int x = mn.first, y = mn.second;
            if (x + a > H || y + b > W) {
                res = false;
                break;
            }
            for (int i = x; i < x + a; i++) {
                for (int j = y; j < y + b; j++) {
                    if (!st.count({i, j})) {
                        res = false;
                        break;
                    }
                    st.erase({i, j});
                }
            }
            mn = *st.begin();
        }
        return res;
    };

    bool ans = false;
    for (int i = 0; i < pow3[N]; i++) {
        vector<pair<int, int>> tiles;
        int S = 0;
        for (int j = 0; j < N; j++) {
            if ((i / pow3[j]) % 3 == 1) tiles.push_back({A[j], B[j]});
            if ((i / pow3[j]) % 3 == 2) tiles.push_back({B[j], A[j]});
            if ((i / pow3[j]) % 3 > 0) S += A[j] * B[j];
        }
        if (S != H * W) continue;
        sort(tiles.begin(), tiles.end());

        do {
            if (check(tiles)) {
                ans = true;
                break;
            }
        } while (next_permutation(tiles.begin(), tiles.end()));
        if (ans) break;
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
