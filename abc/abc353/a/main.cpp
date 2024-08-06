#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int a0, a, ans, N, flag = 0;
    cin >> N;
    cin >> a0;
    for (int i = 1; i < N; i++) {
        cin >> a;
        if (a > a0 && flag == 0) {
            ans = i + 1;
            flag++;
        }
    }
    if (flag == 0) cout << -1 << endl;
    else cout << ans << endl;
    
}
