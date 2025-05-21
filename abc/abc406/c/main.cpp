#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    vector<pair<int, int>> idx;
    idx.push_back({0, 0});
    for (int i = 1; i < N - 1; i++) {
        if (P[i - 1] < P[i] && P[i] > P[i + 1]) idx.push_back({i, 1});
        else if (P[i - 1] > P[i] && P[i] < P[i + 1]) idx.push_back({i, -1});
    }
    idx.push_back({N - 1, 0});
    ll ans = 0;
    for (int i = 1; i < idx.size() - 2; i++) {
        if (idx[i].second == -1 || idx[i + 1].second == 1) continue;
        ll l = idx[i].first - idx[i - 1].first;
        ll r = idx[i + 2].first - idx[i + 1].first;
        ans += l * r;
    }
    cout << ans << endl;
}
