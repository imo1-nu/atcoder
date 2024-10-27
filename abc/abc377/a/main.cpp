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
    vector<int> A(26);
    for (char c : S) {
        A[c - 'A']++;
    }

    bool ans = true;
    for (int i = 0; i < 3; ++i) {
        if (A[i] != 1) {
            ans = false;
            break;
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}
