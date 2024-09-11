#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S, T;
    cin >> S >> T;
    vector<string> ans(1000);
    int cnt = 0;
    while (S != T) {
        int i;
        for (i = 0; i < S.size(); i++) {
            if (S[i] > T[i]) break;
        }
        if (i < S.size()) {
            S[i] = T[i];
            ans[cnt++] = S;
        }
        else {
            for (i = S.size() - 1; i >= 0; i--) {
                if (S[i] < T[i]) break;
            }
            if (i >= 0) {
                S[i] = T[i];
                ans[cnt++] = S;
            }
            else {
                ans[cnt++] = S;
            }
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << ans[i] << endl;
    }
}
