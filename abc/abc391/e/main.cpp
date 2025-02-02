#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    string A;
    cin >> A;

    function<pair<int, int>(int, int)> dfs = [&](int depth, int i) {
        if (depth == 0) return make_pair(A[i] - '0', 1);
        auto [val1, cnt1] = dfs(depth - 1, 3 * i);
        auto [val2, cnt2] = dfs(depth - 1, 3 * i + 1);
        auto [val3, cnt3] = dfs(depth - 1, 3 * i + 2);
        if (val1 == val2 && val2 == val3) return make_pair(val1, cnt1 + cnt2 + cnt3 - max({cnt1, cnt2, cnt3}));
        else if (val1 == val2) return make_pair(val1, min(cnt1, cnt2));
        else if (val2 == val3) return make_pair(val2, min(cnt2, cnt3));
        else return make_pair(val3, min(cnt3, cnt1));
    };

    cout << dfs(N, 0).second << endl;
}
