#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int y;
    cin >> y;
    int ans = 365;
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) ans = 366;
    cout << ans << endl;
}
