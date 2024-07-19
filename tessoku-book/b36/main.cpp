#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i]== '1') cnt++;
    }
    bool ans = false;
    if (cnt % 2 == k % 2) ans = true;
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}
