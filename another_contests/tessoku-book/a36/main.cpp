#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    bool ans = true;
    if (2 * n - 2 > k || k % 2 == 1) ans = false;
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}
