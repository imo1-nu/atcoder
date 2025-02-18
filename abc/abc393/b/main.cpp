#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    int N = S.length();

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (S[i] == 'A' && S[j] == 'B' && S[k] == 'C' && j - i == k - j) ans++;
            }
        }
    }
    cout << ans << endl;
}
