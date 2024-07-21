#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, t, p;
    cin >> n >> t >> p;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    int i = 0;
    for (i = 0; 1; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (l[j] >= t) cnt++;
            l[j]++;
        }
        if (cnt >= p) break;
    }
    cout << i << endl;
}
