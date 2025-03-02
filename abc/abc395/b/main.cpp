#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<string> S(N, string(N, '.'));
    string s = "#.";
    for (int i = 0; i < N; i++) {
        int j = N - i - 1;
        for (int k = i; k <= j; k++) {
            for (int l = i; l <= j; l++) {
                S[k][l] = s[i % 2];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << S[i] << endl;
    }
}
