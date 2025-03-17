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
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    map<int, int> mp;
    vector<int> L(N), R(N);
    for (int i = 1; i < N; i++) {
        mp[A[i - 1]]++;
        L[i] = mp.size();
    }
    mp.clear();
    for (int i = N - 1; i > 0; i--) {
        mp[A[i]]++;
        R[i] = mp.size();
    }
    int ans = 0;
    for (int i = 1; i < N; i++) {
        ans = max(ans, L[i] + R[i]);
    }
    cout << ans << endl;
}
