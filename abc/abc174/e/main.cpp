#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int l = 0, r = 1e9 + 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += (A[i] + mid - 1) / mid - 1;
        }
        if (cnt <= K) r = mid;
        else l = mid;
    }
    cout << r << endl;
}
