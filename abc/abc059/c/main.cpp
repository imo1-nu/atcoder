#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) cin >> A[i];
    ll ans1 = 0, ans2 = 0;
    ll sum = 0;
    for (ll i = 0; i < N; i++) {
        sum += A[i];
        if (i % 2 == 0) {
            if (sum <= 0) {
                ans1 += 1 - sum;
                sum = 1;
            }
        }
        else {
            if (sum >= 0) {
                ans1 += sum + 1;
                sum = -1;
            }
        }
    }

    sum = 0;
    for (ll i = 0; i < N; i++) {
        sum += A[i];
        if (i % 2 == 0) {
            if (sum >= 0) {
                ans2 += sum + 1;
                sum = -1;
            }
        }
        else {
            if (sum <= 0) {
                ans2 += 1 - sum;
                sum = 1;
            }
        }
    }

    cout << min(ans1, ans2) << endl;
}
