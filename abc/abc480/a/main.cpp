#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    vector<string> S(2);
    cin >> S[0] >> S[1];
    if (S[0][0] == 'A' && S[1][1] == 'D' || S[0][0] == 'D' && S[1][1] == 'A' || S[0][1] == 'A' && S[1][0] == 'D' || S[0][1] == 'D' && S[1][0] == 'A') cout << "No" << endl;
    else cout << "Yes" << endl;
}
