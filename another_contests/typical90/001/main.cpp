#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, L, K;
    cin >> N >> L >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int l = 0, r = L;
    while (r - l > 1) {
        int m = (l + r) / 2;
        int cnt = 0, pre = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] - pre >= m && L - A[i] >= m) {
                cnt++;
                pre = A[i];
            }
        }
        if (cnt >= K) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << endl;
}
