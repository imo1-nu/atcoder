#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> cnt(100);
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        cnt[b % 100]++;
    }

    int ans = 0;
    for (int i = 1; i < 50; i++) {
        ans += cnt[i] * cnt[100 - i];
    }
    ans += cnt[50] * (cnt[50] - 1) / 2;
    ans += cnt[0] * (cnt[0] - 1) / 2;
    cout << ans << endl;
}
