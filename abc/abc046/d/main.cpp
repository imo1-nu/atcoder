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
    int N = S.length();

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0 && S[i] == 'p') ans--;
        if (i % 2 == 1 && S[i] == 'g') ans++;
    }
    cout << ans << endl;
}
