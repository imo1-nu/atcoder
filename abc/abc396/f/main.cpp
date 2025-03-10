#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

// vをソートしながら転倒数を数える
ll inversion_number(vector<int> &v) {
    int N = v.size();
    if (N == 1) return 0;
    vector<int> v1(v.begin(), v.begin() + N / 2);
    vector<int> v2(v.begin() + N / 2, v.end());
    ll res = inversion_number(v1) + inversion_number(v2);
    int p = 0, q = 0;
    for (int i = 0; i < N; i++) {
        if (q == v2.size() || (p < v1.size() && v1[p] <= v2[q])) {
            v[i] = v1[p++];
        }
        else {
            v[i] = v2[q++];
            res += v1.size() - p;
        }
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<vector<int>> pos(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        pos[A[i]].push_back(i);
    }

    ll ans = inversion_number(A);
    cout << ans << '\n';
    for (int i = M - 1; i > 0; i--) {
        ll cnt1 = 0, cnt2 = 0;
        for (int j = 0; j < (int)pos[i].size(); j++) {
            cnt1 += pos[i][j] - j;
            cnt2 += N - pos[i][j] - (int)pos[i].size() + j;
        }
        ans += cnt1 - cnt2;
        cout << ans << '\n';
    }
}
