#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, V;
    cin >> N >> V;
    vector<int> W(N);
    for (auto& w : W) cin >> w;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (i + j + k + 3 <= V) ans = max(ans, W[i] + W[j] + W[k]);
            }
        }
    }
    cout << ans << endl;
}
