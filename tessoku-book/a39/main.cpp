#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first; //firstにr, secondにl
    }
    sort(a.begin(), a.end());
    int cnt = 1;
    for (int i = 0; i < n;) {
        int j;
        for (j = i + 1; j < n; j++) {
            if (a[i].first <= a[j].second) {
                cnt++;
                break;
            }
        }
        i = j;
    }
    
    cout << cnt << endl;
}
