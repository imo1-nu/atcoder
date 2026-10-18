#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (auto& a : A) cin >> a;
    
    vector<ll> S(N + 1), length(N + 1), sum_B(N + 1);

    for (int i = 1; i <= N; i++) {
        S[i] = S[i - 1] + A[i - 1];
        length[i] = length[i - 1] + i;
        sum_B[i] = sum_B[i - 1] + S[i];
    }

    auto culc = [&](ll idx) {
        int i = upper_bound(length.begin(), length.end(), idx) - length.begin();
        i--;
        ll res = sum_B[i];
        res += S[idx - length[i]];
        return res;
    };

    while (Q--) {
        ll l, r;
        cin >> l >> r;
        l--;
        cout << culc(r) - culc(l) << endl;
    }
}
