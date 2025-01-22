#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    string S;
    cin >> N >> S;

    vector<mint> pow2(N + 1);
    pow2[0] = 1;
    for (int i = 1; i <= N; i++) pow2[i] = pow2[i - 1] * 2;

    vector<mint> A(N), M(N);
    for (int i = 1; i < N; i++) {
        if (N % i != 0) continue;
        vector<bool> v(i, true);
        for (int j = 0; j < N; j++) if (S[j] == '.') v[j % i] = false;
        int cnt = count(v.begin(), v.end(), true);
        A[i] = pow2[cnt];
        M[i] = A[i];
        for (int j = 1; j < i; j++) if (i % j == 0) M[i] -= M[j];
    }

    mint ans = 0;
    for (int i = 1; i < N; i++) ans += M[i];
    cout << ans.val() << endl;
}
