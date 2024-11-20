#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    string s, t1, t2;
    cin >> n >> s;
    bool ans = false;
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            ans = true;
            break;
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}
