#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n.size(); i++) {
        if (n[i] == '1') ans += 1 << (n.size() - 1 - i);
    }
    cout << ans << endl;
}
