#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, K;
    cin >> N >> K;
    K--;
    vector<vector<int>> A(N);
    for (auto& a : A) {
        int l;
        cin >> l;
        for (int i = 0; i < l; i++) {
            int t;
            cin >> t;
            a.push_back(t);
        }
    }
    vector<int> C(N);
    for (auto& c : C) cin >> c;

    for (int i = 0; i < N; i++) {
        ll l = A[i].size();
        if (K < C[i] * l) {
            K %= l;
            cout << A[i][K] << endl;
            return 0;
        }
        K -= C[i] * l;
    }
}
