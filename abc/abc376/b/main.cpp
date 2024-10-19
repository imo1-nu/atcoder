#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    int l = 0, r = 1;
    int ans = 0;

    for (int i = 0; i < Q; i++) {
        char h;
        int t;
        cin >> h >> t;
        t--;

        int j, cnt = 0;
        if (h == 'L') {
            for (j = l; j != r && j != t; j = (j + 1) % N) {
                cnt++;
            }
            if (j == t) {
                l = t;
                ans += cnt;
                continue;
            }

            cnt = 0;
            for (j = l; j != r && j != t; j = (j + N - 1) % N) {
                cnt++;
            }
            if (j == t) {
                l = t;
                ans += cnt;
                continue;
            }
        } else {
            for (j = r; j != l && j != t; j = (j + N - 1) % N) {
                cnt++;
            }
            if (j == t) {
                r = t;
                ans += cnt;
                continue;
            }

            cnt = 0;
            for (j = r; j != l && j != t; j = (j + 1) % N) {
                cnt++;
            }
            if (j == t) {
                r = t;
                ans += cnt;
                continue;
            }
        }
    }
    
    cout << ans << endl;
}
