#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (auto& a : A) {
        cin >> a;
        a--;
    }

    vector<int> C(K);
    for (auto a : A) C[a]++;
    int mx = 0;
    for (auto c : C) mx = max(c, mx);
    int ans = 0;
    for (auto c : C) {
        if (c >= mx - 1) ans++;
    }
    cout << ans << endl;
}
