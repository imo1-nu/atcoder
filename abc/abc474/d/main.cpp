#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (auto& a : A) cin >> a;
    for (auto& b : B) cin >> b;

    vector<int> diff(N);
    int idx = -1;
    for (int i = 0; i < N; i++) {
        diff[i] = A[i] - B[i];
        if (diff[i] > 0) idx = i;
    }

    vector<ll> W(N, 1);
    if (idx == -1) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        W[idx] = 1000000000000000000ll;
        for (auto w : W) cout << w << " ";
        cout << endl;
    }
}
