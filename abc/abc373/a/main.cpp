#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N = 12;
    vector<string> S(N);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
        if (S[i].length() == i + 1) {
            ans++;
        }
    }
    cout << ans << endl;
}
