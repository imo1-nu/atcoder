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
    string S;
    cin >> S;

    for (int i = 0; i < N && D > 0; i++) {
        if (S[i] == '@') {
            S[i] = '.';
            D--;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '.') {
            ans++;
        }
    }
    cout << ans << endl;
}
