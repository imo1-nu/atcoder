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
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    atcoder::fenwick_tree<mint> fw1(200001), fw2(200001);
    vector<mint> dp(N + 1);
    for (int i = 1; i <= N; i++) {
        mint d = fw1.sum(0, A[i - 1] + 1) * mint(A[i - 1]) + fw2.sum(A[i - 1] + 1, 200001);
        dp[i] = dp[i - 1] + mint(2) * d + mint(A[i - 1]);
        cout << (dp[i] / (mint(i).pow(2))).val() << endl;
        
        fw1.add(A[i - 1], mint(1));
        fw2.add(A[i - 1], mint(A[i - 1]));
    }
}
