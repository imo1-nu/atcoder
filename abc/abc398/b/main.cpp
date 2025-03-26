#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    vector<int> cnt(14);
    for (int i = 0; i < 7; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    sort(cnt.rbegin(), cnt.rend());
    if (cnt[0] >= 3 && cnt[1] >= 2) cout << "Yes" << endl;
    else cout << "No" << endl;
}
