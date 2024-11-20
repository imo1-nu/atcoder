#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;

    int m = (N - 1) * (N - 2) / 2;
    if (K > m) {
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int, int>> ans;
    for (int i = 2; i <= N; i++) {
        ans.push_back({1, i});
    }

    for (int i = 2; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (K == m) {
                break;
            }
            ans.push_back({i, j});
            m--;
        }
    }

    cout << ans.size() << endl;
    for (auto [a, b] : ans) {
        cout << a << " " << b << endl;
    }
}
