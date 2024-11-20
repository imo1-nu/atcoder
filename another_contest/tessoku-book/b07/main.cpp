#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int t, n;
    cin >> t >> n;
    vector<int> a(t + 1), s(t + 1);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a[l]++;
        a[r]--;
    }

    for (int i = 1; i <= t + 1; i++) {
        s[i] = s[i - 1] + a[i - 1];
    }

    for (int i = 1; i <= t; i++) {
        cout << s[i] << endl;
    }
    
}
