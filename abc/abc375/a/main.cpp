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
    string S;
    cin >> S;
    int ans = 0;
    for (int i = 0; i < N - 2; i++) {
        if (S[i] == '#' && S[i + 1] == '.' && S[i + 2] == '#') ans++;
    }
    cout << ans << endl;
}
