#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& a : A) cin >> a;

    int ans = 0;
    for (int i = N / 2; i < N; i++) ans += A[i];
    cout << ans << endl;
}
