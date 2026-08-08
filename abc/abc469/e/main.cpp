#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    string S;
    cin >> N >> K >> S;

    vector<int> sum(N + 1);
    for (int i = 0; i < N; i++) {
        sum[i + 1] = sum[i];
        if (S[i] == 'o') sum[i + 1]++;
    }

    int l = 0, r = 0, cnt = 0;
    while (r <= N) {
        
    }

    int len = N;
    for (int i = 0; i < N; i++) {
        int idx = lower_bound(sum.begin(), sum.end(), K + sum[i]) - sum.begin();
        if (idx == N + 1) continue;
        len = min(len, idx - i);
    }
    cout << fixed << setprecision(15) << (double)K / len << endl;
}
