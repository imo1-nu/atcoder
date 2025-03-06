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
    vector<pair<int, int>> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i].first >> P[i].second;
        if (P[i].first > P[i].second) swap(P[i].first, P[i].second);
    }
    sort(P.begin(), P.end());
    set<int> S;
    bool ans = false;
    for (auto [a, b] : P) {
        auto it = S.lower_bound(b);
        if (it != S.begin() && a < *(--it)) ans = true;
        S.insert(b);
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
