#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll l = 0, r = 1e12 + 1;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        ll cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += min(A[i], mid);
        }
        if (cnt <= K) {
            l = mid;
        } else {
            r = mid;
        }
    }

    for (int i = 0; i < N; i++) {
        ll a = min(A[i], l);
        A[i] -= a;
        K -= a;
    }

    for (int i = 0; i < N && K > 0; i++) {
        if (A[i] > 0) {
            A[i]--;
            K--;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
