#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, C;
    cin >> N >> C;
    vector<int> T(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }

    int prev = -1e9;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (T[i] - prev >= C) {
            prev = T[i];
            ans++;
        }
    }
    cout << ans << endl;
}
