#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    pair<int, int> ans = {100 * A, 0};
    for (int i = 0; A * i * 100 <= F; i++) {
        for (int j = 0; A * i * 100 + B * j * 100 <= F; j++) {
            for (int k = 0; A * i * 100 + B * j * 100 + C * k <= F; k++) {
                for (int l = 0; A * i * 100 + B * j * 100 + C * k + D * l <= F; l++) {
                    int water = A * i * 100 + B * j * 100;
                    int sugar = C * k + D * l;
                    int all = water + sugar;
                    if (all > F) continue;
                    if (water * E < sugar * 100) continue;
                    if (ans.second * all < sugar * ans.first) {
                        ans = {all, sugar};
                    }
                }
            }
        }
    }
    cout << ans.first << " " << ans.second << endl;
}
