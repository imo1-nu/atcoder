#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

vector<pair<int, int>> encode(const vector<int>& v) {
    int N = (int)v.size();
    vector<pair<int, int>> ret;
    for (int l = 0; l < N;) {
        int r = l + 1;
        for (; r < N && v[l] == v[r]; r++) {};
        ret.push_back({v[l], r - l});
        l = r;
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> B(N - 1);
    for (int i = 0; i < N - 1; i++) {
        B[i] = A[i + 1] - A[i];
    }
    vector<pair<int, int>> C = encode(B);
    ll ans = N;
    for (auto [_, l] : C) {
        ans += ll(l + 1) * l / 2;
    }
    cout << ans << endl;
}
