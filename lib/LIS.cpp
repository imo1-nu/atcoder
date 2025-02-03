#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;

// 最長増加部分列の長さを求める
int LIS(const vector<ll> &a) {
    int N = (int)a.size();
    vector<ll> dp(N, INF);
    for (int i = 0; i < N; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        *it = a[i];
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main() {
    int N; cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    cout << LIS(a) << endl;
}   
