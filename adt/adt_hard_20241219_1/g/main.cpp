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
    vector<pair<int, int>> P(2 * N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i].first >> P[i + N].first;
        P[i + N].first += P[i].first;
        P[i].second = 1;
        P[i + N].second = -1;
    }
    sort(P.begin(), P.end());
    map<int, int> mp;
    mp[0] = 0;
    int last = 0;
    for (auto [x, t] : P) {
        if (!mp.count(x)) {
            mp[x] = mp[last];
            last = x;
        }
        mp[x] += t;
    }
    
    vector<int> ans(N + 1);
    for (auto [x, t] : mp) {
        if (x == last) break;
        auto [x2, t2] = *mp.upper_bound(x);
        ans[t] += x2 - x;
    }
    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
