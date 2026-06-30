#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> P(N);
    for (auto& p : P) cin >> p.second >> p.first;
    sort(P.begin(), P.end());

    int INF = 1000000000;
    int ok = 0, ng = INF;
    while (ng - ok > 1) {
        int mid = (ok + ng) / 2;
        auto Q = P;
        for (auto& q : Q) q.first += mid;
        int cnt = 0;
        int r = -1;
        for (auto& q : Q) {
            if (r <= q.second) {
                cnt++;
                r = q.first;
            }
        }
        if (cnt >= K) ok = mid;
        else ng = mid;
    }
    if (ok == 0) cout << -1 << endl;
    else cout << ok  << endl;
}
