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
    vector<int> X(26);
    for (int i = 0; i < 26; ++i) {
        X[S[i] - 'A'] = i;
    }
    int ans = 0;
    for (int i = 0; i < 25; ++i) {
        ans += abs(X[i] - X[i + 1]);
    }
    cout << ans << endl;
}
