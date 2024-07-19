#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, m, ans, flag = 0;
    cin >> n >> m;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        m -= h[i];
        //cout << m << endl;
        if (flag == 0) {
            if (m == 0) {
                ans = i + 1;
                flag = 1;
            }
            else if (m < 0) {
                ans = i;
                flag = 1;
            }
            
        }
    }
    if (flag == 0) ans = n;
    cout << ans << endl;
    
}
