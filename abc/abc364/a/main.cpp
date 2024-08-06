#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    bool ans = true;
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == "sweet" && s[i + 1] == "sweet") {
            ans = false;
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}
