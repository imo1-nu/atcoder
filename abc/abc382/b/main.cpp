#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, D;
    string S;
    cin >> N >> D >> S;

    for (int i = N - 1; i >= 0 && D > 0; i--) {
        if (S[i] == '@') {
            S[i] = '.';
            D--;
        }
    }

    cout << S << endl;
}
