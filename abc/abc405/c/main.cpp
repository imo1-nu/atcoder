#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    atcoder::fenwick_tree<ll> fw(N);
    for (int i = 0; i < N; i++) {
        fw.add(i, A[i]);
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += A[i] * fw.sum(i + 1, N);
    }
    cout << ans << endl;
}
