#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;
    bool ans = false;
    if (s[0] == 'R' || s[1] == 'R' && s[2] == 'M') ans = true;
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}
