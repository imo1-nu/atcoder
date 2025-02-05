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
        if (q == (int)v2.size() || (p < (int)v1.size() && v1[p] <= v2[q])) {
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
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> B = A;
    ll ans = inversion_number(B);
    cout << ans << endl;
    for (int k = 1; k < N; k++) {
        ans += N - 1 - 2 * A[k - 1];
        cout << ans << endl;
    }
}
