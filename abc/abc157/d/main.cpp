#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M, K;
    cin >> N >> M >> K;

    atcoder::dsu d(N);
    vector<int> A(M) ,B(M), C(K), D(K), ans(N);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        ans[A[i]]--;
        ans[B[i]]--;
        d.merge(A[i], B[i]);
    }

    for (int i = 0; i < K; i++) {
        cin >> C[i] >> D[i];
        C[i]--; D[i]--;
        if (d.same(C[i], D[i])) {
            ans[C[i]]--;
            ans[D[i]]--;
        }
    }

    for (int i = 0; i < N; i++) {
        ans[i] += d.size(i) - 1;
        cout << ans[i];
        if (i < N - 1) cout << " ";
    }
    cout << endl;
}
