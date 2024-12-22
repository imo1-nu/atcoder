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
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    int ans = 1;
    for (int d = 1; d < N; ++d) {
        for (int i = 0; i < N; ++i) {
            int cnt = 0;
            for (int j = i; j < N; j += d) {
                if (H[j] == H[i]) cnt++;
                else break;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
}
