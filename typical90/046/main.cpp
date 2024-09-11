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
    vector<ll> A(46), B(46), C(46);
    int a, b, c;
    for (int i = 0; i < N; i++) {
        cin >> a;
        A[a % 46]++;
    }
    for (int i = 0; i < N; i++) {
        cin >> b;
        B[b % 46]++;
    }
    for (int i = 0; i < N; i++) {
        cin >> c;
        C[c % 46]++;
    }
    ll ans = 0;
    for (int i = 0; i < 46; i++) {
        for (int j = 0; j < 46; j++) {
            for (int k = 0; k < 46; k++) {
                if ((i + j + k) % 46 == 0) {
                    ans += A[i] * B[j] * C[k];
                }
            }
        }
    }
    cout << ans << endl;
}
