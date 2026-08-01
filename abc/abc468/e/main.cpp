#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<mint> A(N);
    for (auto& a : A) {
        int x;
        cin >> x;
        a = x;
    }
    vector<mint> inv(N + 1), sum(N + 1);
    for (int i = 1; i <= N; i++) {
        inv[i] = mint(1) / i;
    }
    for (int i = 1; i <= N; i++) {
        sum[i] = sum[i - 1] + inv[i];
    }

    mint add = 0;
    mint ans = 0;
    for (int i = 0; i < N; i++) {
        add += sum[N - i] - sum[i];
        ans += A[i] * add;
    }
    cout << ans.val() << endl;
}
