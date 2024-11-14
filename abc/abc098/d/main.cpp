#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

#define MAXBIT 20

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll ans = 0;
    int sum = A[0];
    int l = 0, r = 1;
    while (l < N) {
        if (r < N && int(A[r] & sum) == 0) {
            sum += A[r];
            r++;
        }
        else {
            ans += r - l;
            sum -= A[l];
            l++;
        }
    }
    cout << ans << endl;
}
