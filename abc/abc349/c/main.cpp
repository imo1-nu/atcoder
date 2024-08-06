#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S, T;
    cin >> S >> T;

    int step = 0;
    for (int i = 0; i < S.length(); i++) {
        if (step == 0 && S[i] == T[0] - 'A' + 'a') {
            step++;
            continue;
        }
        if (step == 1 && S[i] == T[1] - 'A' + 'a') {
            step++;
            continue;
        }
        if (step == 2 && S[i] == T[2] - 'A' + 'a') {
            step++;
            continue;
        }
    }
    if (step == 3 || step == 2 && T[2] == 'X') cout << "Yes" << endl;
    else cout << "No" << endl;
}
