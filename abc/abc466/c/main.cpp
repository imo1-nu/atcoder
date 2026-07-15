#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;

    ll ans = 0;
    int l = 1, r = 2;
    while (l < N && r <= N) {
        cout << "? " << l << ' ' << r << endl;
        string res;
        cin >> res;
        if (res == "Yes") {
            r++;
        }
        else {
            ans += (r - l - 1);
            l++;
            if (l == r) r++;
        }
    }
    while (l < N) {
        ans += (r - l - 1);
        l++;
    }
    cout << "! " << ans << endl;
}
