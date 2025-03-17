#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> B(200001);
    iota(B.begin(), B.end(), 0);
    for (int i = 2; i * i <= 200000; i++) {
        for (int j = 1; j * i * i <= 200000; j++) {
            B[j * i * i] = j;
        }
    }

    unordered_map<int, int> cnt;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) ans += i;
        else ans += cnt[B[A[i]]] + cnt[0];
        cnt[B[A[i]]]++;
    }
    cout << ans << endl;
}
