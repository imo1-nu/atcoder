#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    while (1) {
        int N;
        cin >> N;
        if (N == 0) break;
        string S;
        cin >> S;
        for (int i = 0; i < N; i++) {
            string T = S.substr(0, i + 1);
            T += S;
            if (T.substr(0, N) == S && T.substr(i + 1, N) == S) {
                cout << T << endl;
                break;
            }
        }
    }
}