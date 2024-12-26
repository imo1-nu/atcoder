#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int sum = 0;
    map<int, int> cnt;
    for (int i = 0; i < N; ++i) {
        sum ^= A[i];
        cnt[A[i]]++;
    }
    if (sum != 0) {
        cout << -1 << endl;
        return 0;
    }

    int mx = 1;
    for (auto [a, b] : cnt) {
        if (b % 2 == 1) {
            mx = max(mx, a);
        }
    }
    cout << mx - 1 << endl;
}
