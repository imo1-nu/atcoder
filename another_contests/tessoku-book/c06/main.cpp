#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    cout << n << endl;
    for (int i = 1; i < n; i++) {
        cout << i << ' ' << i + 1 << endl;
    }
    cout << n << ' ' << 1 << endl;
}
