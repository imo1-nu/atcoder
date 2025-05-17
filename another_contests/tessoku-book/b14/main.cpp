#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n / 2), b(n - n / 2);
    vector<int> suma(1 << (n / 2)), sumb(1 << (n - n / 2));
    for (int i = 0; i < n / 2; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - n / 2; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < (1 << (n / 2)); i++) {
        bitset<16> B = i;
        for (int j = 0; j < n / 2; j++) {
            if (B.test(j)) suma[i] += a[j];
        }
    }
    for (int i = 0; i < (1 << (n - n / 2)); i++) {
        bitset<16> B = i;
        for (int j = 0; j < n - n / 2; j++) {
            if (B.test(j)) sumb[i] += b[j];
        }
    }

    sort(sumb.begin(), sumb.end());
    bool ans = false;
    for (int i = 0; i < 1 << (n / 2); i++) {
        auto l = lower_bound(sumb.begin(), sumb.end(), k - suma[i]);
        if (suma[i] + sumb[l - sumb.begin()] == k) ans = true;
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}
