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
    for (int i = 0; i < N; i++) {
        cin >> P[i].first;
        P[i].second = i;
    }
    sort(P.rbegin(), P.rend());
    vector<int> ans(N);
    ans[P[0].second] = 1;
    for (int i = 1; i < N; i++) {
        if (P[i].first == P[i - 1].first) {
            ans[P[i].second] = ans[P[i - 1].second];
        }
        else {
            ans[P[i].second] = i + 1;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
}
