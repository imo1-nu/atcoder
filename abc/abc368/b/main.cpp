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
    }
    int ans = 0;
    while (true) {
        sort(A.rbegin(), A.rend());
        if (A[1] <= 0) {
            break;
        }
        A[0]--;
        A[1]--;
        ans++;
    }
    cout << ans << endl;
}
