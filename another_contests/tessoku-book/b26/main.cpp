#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<bool> b(n + 1, true);
    for (int i = 2; i < n; i++) {
        if (b[i]) {
            int now = i * 2;
            while (now <= n) {
                b[now] = false;
                now += i;
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        if (b[i]) cout << i << endl;
    }
    
}
