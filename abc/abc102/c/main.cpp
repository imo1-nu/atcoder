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
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] -= i + 1;
    }

    sort(A.begin(), A.end());
    int b = A[N / 2];
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(A[i] - b);
    }
    cout << ans << endl;
}
