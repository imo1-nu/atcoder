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
    vector<ll> A(N), B(N);
    ll maxA = -1e9, maxB = -1e9;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        maxA = max(maxA, A[i]);
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
        maxB = max(maxB, B[i]);
    }
    cout << maxA + maxB << endl;
}
