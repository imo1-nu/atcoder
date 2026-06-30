#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<pair<int, int>> P(N);
    for (auto& p : P) {
        cin >> p.first >> p.second;
    }
    sort(P.begin(), P.end());

    atcoder::fenwick_tree<int> fw(N + 1);
    int ans = 0;
    for (auto p : P) {
        if (fw.sum(0, p.second) == 0) ans++;
        fw.add(p.second, 1);
    }
    cout << ans << endl;
}
