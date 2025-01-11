#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, D;
    cin >> N >> D;
    vector<int> T(N), L(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> L[i];
    }

    for (int i = 1; i <= D; i++) {
        int ans = 0;
        for (int j = 0; j < N; j++) {
            ans = max(ans, T[j] * (i + L[j]));
        }
        cout << ans << endl;
    }
}
