#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct box {
    int x;
    int y;
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<pair<int, int>> box(n);
    for (int i = 0; i < n; i++) {
        cin >> box[i].first >> box[i].second;
        box[i].second *= -1;
    }
    sort(box.begin(), box.end());

    for (int i = 0; i < n; i++) {
        box[i].second *= -1;
    }

    int ans = 0;
    vector<int> len(n + 1);
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(len.begin() + 1, len.begin() + ans + 1, box[i - 1].second) - len.begin();
        len[pos] = box[i - 1].second;
        if (pos > ans) ans++;
    }
    
    cout << ans << endl;
}
