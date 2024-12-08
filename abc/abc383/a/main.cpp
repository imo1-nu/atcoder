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
    vector<int> T(N), V(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> V[i];
    }

    int ans = V[0];
    for (int i = 1; i < N; i++) {
        ans = max(ans + V[i] - T[i] + T[i - 1], V[i]);
    }
    cout << ans << endl;
}
