#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    vector<bool> can(N);
    for (int i = 0; i < N; i++) {
        int j;
        for (j = i; j < min(N, i + K); j++) {
            if (S[j] == 'X') break;
        }
        if (j == i + K) can[i] = true;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (can[i] && S[i] != 'X') {
            ans++;
            for (int j = i; j < min(N, i + K); j++) {
                S[j] = 'X';
            }
        }
    }

    cout << ans << endl;
}
