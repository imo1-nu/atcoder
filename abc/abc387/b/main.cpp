#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int X;
    cin >> X;
    int ans = 0;
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            if (i * j != X) {
                ans += i * j;
            }
        }
    }
    cout << ans << endl;
}
