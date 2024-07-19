#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S = "AtCoder", T = "Land";
    string s, t;
    cin >> s >> t;

    bool ans = false;
    if (S == s && T == t) ans = true;
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}
