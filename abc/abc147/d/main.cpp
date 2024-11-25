#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint1000000007;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<ll> cnt(60, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 60; j++) {
            if (A[i] >> j & 1) {
                cnt[j]++;
            }
        }
    }

    vector<mint> pow2(60);
    pow2[0] = 1;
    for (int i = 1; i < 60; i++) {
        pow2[i] = pow2[i - 1] * 2;
    }

    mint ans = 0;
    for (int i = 0; i < 60; i++) {
        mint x = pow2[i] * cnt[i] * (N - cnt[i]);
        ans += x;
    }
    cout << ans.val() << endl;
}
