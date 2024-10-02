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
    for (int i = 0; i < S.length(); i++) {
        if (S[i] != '.') cout << S[i];
    }
    cout << endl;
}
