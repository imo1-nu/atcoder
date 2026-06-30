#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, D;
    cin >> N >> D;
    vector<pair<int, int>> P(N);
    for (auto& p : P) {
        cin >> p.first >> p.second;
        p.first--; p.second--;
    }
    sort(P.begin(), P.end());

    atcoder::fenwick_tree<ll> fw_sum(2000000), fw_cnt(2000000);
    ll ans = 0;
    for (auto p : P) {
        if (p.first + D > p.second) continue;
        ans += fw_sum.sum(p.first + D, p.second) - (p.first + D - 1) * fw_cnt.sum(p.first + D, p.second);
        ans += (p.second - p.first - D + 1) * fw_cnt.sum(p.second, 2000000);
        fw_sum.add(p.second, p.second);
        fw_cnt.add(p.second, 1);
    }
    cout << ans << endl;
}
