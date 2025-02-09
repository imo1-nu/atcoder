#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> K(N);
    vector<map<int, int>> mp(N);
    for (int i = 0; i < N; i++) {
        cin >> K[i];
        for (int j = 0; j < K[i]; j++) {
            int a;
            cin >> a;
            mp[i][a]++;
        }
    }

    double ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ll cnt = 0;
            for (auto [a, b] : mp[i]) {
                if (mp[j].count(a)) {
                    cnt += (ll)b * mp[j][a];
                }
            }
            ans = max(ans, (double)cnt / K[i] / K[j]);
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
}
