#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> A(N);
    for (auto& a : A) cin >> a;

    ll ok = 1, ng = 3e18;
    while (ok + 1 < ng) {
        ll mid = (ok + ng) / 2;
        __int128_t count = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] >= mid) continue;
            count += (mid - A[i] + i) / (i + 1);
        }
        if (count <= K) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}
