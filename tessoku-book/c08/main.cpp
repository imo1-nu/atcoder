#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
    }

    bool flag = true;
    string ans;
    for (int i = 0; i < 10000; i++) {
        bool ok = true;
        string a = to_string(i);
        while (a.length() < 4) a = "0" + a;
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                if (a[k] != s[j][k]) cnt++;
            }
            if (t[j] == 1 && cnt != 0) {
                ok = false;
                break;
            }
            if (t[j] == 2 && cnt != 1) {
                ok = false;
                break;
            }
            if (t[j] == 3 && cnt <= 1) {
                ok = false;
                break;
            }
        }
        if (ok && flag) {
            ans = a;
            flag = false;
        }
        else if (ok && !flag) {
            ans = "Can't Solve";
            break;
        }
    }

    cout << ans << endl;
}
