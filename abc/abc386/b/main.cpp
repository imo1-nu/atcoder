#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;

    int ans = 0;
    for (int i = 0; i < (int)S.length(); ++i) {
        if (i + 1 < (int)S.length() && S[i] == '0' && S[i + 1] == '0') {
            i++;
        }
        ans++;
    }
    cout << ans << endl;
}
