#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int A, B, C;
    cin >> A >> B >> C;
    bool ans = false;
    if (B > C && (A <= B && A >= C) || B < C && (A <= B || A >= C)) ans = true;
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}
