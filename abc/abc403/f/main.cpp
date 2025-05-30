#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<string> dp1(2001), dp2(2001);
    dp1[1] = dp2[1] = "1";
    dp1[11] = dp2[11] = "11";
    dp1[111] = dp2[111] = "111";
    dp1[1111] = dp2[1111] = "1111";
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i / 2; j++) {
            if (dp1[i].length() > dp1[j].length() + dp1[i - j].length() + 1 || dp1[i].empty()) {
                dp1[i] = dp1[j] + "+" + dp1[i - j];
            }
            if (dp2[i].length() > dp1[j].length() + dp1[i - j].length() + 3 || dp2[i].empty()) {
                dp2[i] = "(" + dp1[j] + "+" + dp1[i - j] + ")";
            }
        }
        for (int j = 2; j * j <= i; j++) {
            if (i % j != 0) continue;
            int k = i / j;
            if (dp1[i].length() > dp2[j].length() + dp2[k].length() + 1) {
                dp1[i] = dp2[j] + "*" + dp2[k];
            }
            if (dp2[i].length() > dp2[j].length() + dp2[k].length() + 1) {
                dp2[i] = dp2[j] + "*" + dp2[k];
            }
        }
    }
    cout << dp1[N] << endl;
}
