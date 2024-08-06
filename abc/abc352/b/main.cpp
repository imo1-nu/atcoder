#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string S, T;
    cin >> S >> T;

    int i = 0, j = 0;
    for (i = 0; i < S.length(); i++, j++) {
        while (S[i] != T[j]) {
            j++;
        }
        if (i == S.length() - 1) cout << j + 1 << endl;
        else cout << j + 1 << ' ';
    }
    
}
