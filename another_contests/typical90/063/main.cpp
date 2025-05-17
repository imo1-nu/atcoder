#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int maximum_same(vector<int> R) {
    map<int, int> mp;
    int ret = 0;
    for (int i = 0; i < R.size(); i++) {
        mp[R[i]]++;
        ret = max(ret, mp[R[i]]);
    }
    return ret;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W;
    cin >> H >> W;
    vector<vector<int>> P(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> P[i][j];
            P[i][j]--;
        }
    }

    int ans = 0;
    for (int i = 1; i < (1 << H); i++) {
        vector<int> R;
        for (int j = 0; j < W; j++) {
            int idx = -1;
            bool flag = false;
            for (int k = 0; k < H; k++) {
                if ((i & (1 << k)) == 0) continue;
                if (idx == -1) idx = P[k][j];
                else if (idx != P[k][j]) flag = true;
            }
            if (!flag) R.push_back(idx);
        }

        int cntH = 0, cntW = maximum_same(R);
        for (int j = 0; j < H; j++) {
            if ((i & (1 << j)) != 0) cntH++;
        }
        ans = max(ans, cntH * cntW);
    }
    cout << ans << endl;
}
