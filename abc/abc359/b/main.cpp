#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < n * 2; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0; i < 2 * n - 2; i++) {
        if (a[i] == a[i + 2]) cnt++;
    }
    cout << cnt << endl;
}
