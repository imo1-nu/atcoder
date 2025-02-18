#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

const int maxA = 1000000;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    vector<int> cntA(maxA + 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        cntA[A[i]]++;
    }

    vector<int> cnt(maxA + 1);
    for (int i = 1; i <= maxA; i++) {
        for (int j = i; j <= maxA; j += i) {
            cnt[i] += cntA[j];
        }
    }

    vector<int> ans(maxA + 1);
    for (int i = 1; i <= maxA; i++) {
        if (cnt[i] < K) continue;
        for (int j = i; j <= maxA; j += i) {
            ans[j] = i;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[A[i]] << endl;
    }
}
