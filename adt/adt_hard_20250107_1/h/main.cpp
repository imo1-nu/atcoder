#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> R(N), C(N), A(N);
    map<int, vector<int>> mp;
    for (int i = 0; i < N; i++) {
        cin >> R[i] >> C[i] >> A[i];
        R[i]--; C[i]--;
        mp[A[i]].push_back(i);
    }

    vector<int> ans(N);
    vector<int> rmax(H), cmax(W);
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        for (int i : it->second) {
            ans[i] = max(rmax[R[i]], cmax[C[i]]);
        }
        for (int i : it->second) {
            rmax[R[i]] = max(rmax[R[i]], ans[i] + 1);
            cmax[C[i]] = max(cmax[C[i]], ans[i] + 1);
        }
    }

    for (int i = 0; i < N; i++) cout << ans[i] << endl;
}
