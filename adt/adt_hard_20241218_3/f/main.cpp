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
    vector<int> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        int cnt = H[i] / 5;
        ans += cnt * 3;
        H[i] %= 5;
        while (H[i] > 0) {
            ans++;
            if (ans % 3 == 0) H[i] -= 3;
            else H[i]--;
        }
    }
    cout << ans << endl;
}
