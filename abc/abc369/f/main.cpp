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
    vector<pair<int, int>> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i].first >> C[i].second;
        C[i].first--;
        C[i].second--;
    }
    sort(C.begin(), C.end());
    vector<int> L(N + 1, 1e9);
    vector<int> id(N + 1, -1), pre(N + 1, -1);
    L[0] = 0;
    int len = 0;
    for (int i = 0; i < N; i++) {
        int pos = upper_bound(L.begin(), L.end(), C[i].second) - L.begin();
        L[pos] = C[i].second;
        id[pos] = i;
        pre[i] = id[pos - 1];
        if (pos > len) {
            len++;
        }
    }
    cout << len << endl;
    stack<int> ans;
    for (int i = id[len]; i != -1; i = pre[i]) {
        ans.push(i);
    }
    
    int x = 0, y = 0;
    while (!ans.empty()) {
        int i = ans.top();
        ans.pop();
        int nx = C[i].first, ny = C[i].second;
        while (x < nx) {
            cout << "D";
            x++;
        }
        while (y < ny) {
            cout << "R";
            y++;
        }
        x = nx;
        y = ny;
    }
    while (x < H - 1) {
        cout << "D";
        x++;
    }
    while (y < W - 1) {
        cout << "R";
        y++;
    }
    cout << endl;
}
