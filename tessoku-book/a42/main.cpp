#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    int M = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            int cnt = 0;
            for (int l = 0; l < n; l++) {
                if (i <= a[l] && a[l] <= i + k && j <= b[l] && b[l] <= j + k) cnt++;
            }
            M = max(M, cnt);
        }
    }
    
    cout << M << endl;
}
