#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K, T;
    cin >> N >> K >> T;
    vector<int> A(N);
    for (auto& a : A) cin >> a;
    A.push_back(-K);
    A.push_back(T);
    sort(A.begin(), A.end());
    ll ans = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == T) break;
        int dist = A[i + 1] - A[i] - K;
        if (dist < 0) continue;
        ans += (dist + K - 1) / K;
    }
    cout << ans << endl;
}
