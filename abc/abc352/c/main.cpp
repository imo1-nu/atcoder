#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    ll sum = 0, max = 0;
    for (ll i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        if (B[i] - A[i] > max) max = B[i] - A[i];
        sum += A[i];
    }
    cout << sum + max << endl;
}
