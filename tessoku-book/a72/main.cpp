#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> c(h);
    for (int i = 0; i < h; i++) {
        cin >> c[i];
    }

    string t = "#", s = "#";
    for (int i = 1; i < w; i++) {
        s += t;
    }
    
    int ans = 0;
    for (int i = 0; i < (1 << h); i++) {
        bitset<10> b = i;
        int wcnt = k - b.count();
        if (wcnt < 0) continue;

        vector<string> c2 = c;
        for (int j = 0; j < h; j++) {
            if (b.test(j)) {
                c2[j] = s;
            }
        }

        int sum = 0;
        for (int j = 0; j < h; j++) {
            for (int l = 0; l < w; l++) {
                if (c2[j][l] == '#') sum++;
            }
        }
        
        vector<int> cnt(w);
        for (int l = 0; l < w; l++) {
            for (int j = 0; j < h; j++) {
                if (c2[j][l] == '.') cnt[l]++;
            }
        }
        sort(cnt.rbegin(), cnt.rend());
        for (int j = 0; j < wcnt; j++) {
            sum += cnt[j];
        }
        
        ans = max(ans, sum);
    }
    
    cout << ans << endl;
}
