#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    int N = S.size();
    for (int i = N - 2; i >= 0; i--) {
        if (S[i] == 'W' && S[i + 1] == 'A') {
            S[i] = 'A';
            S[i + 1] = 'C';
        }
    }
    cout << S << endl;
}
