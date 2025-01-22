#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int op(int a, int b) { return min(a, b); }
int e() { return INT_MAX; }

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<map<int, int>> mp(3), idx(3);
    vector<vector<int>> boxes(N, vector<int>(3));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) cin >> boxes[i][j];
        sort(boxes[i].begin(), boxes[i].end());
        for (int j = 0; j < 3; j++) mp[j][boxes[i][j]]++;
        boxes[i][1] *= -1;
    }
    sort(boxes.begin(), boxes.end());
    for (int i = 0; i < 3; i++) {
        int cnt = 0;
        for (auto& p : mp[i]) {
            idx[i][p.first] = cnt++;
        }
    }

    atcoder::segtree<int, op, e> seg(N);
    for (auto &box : boxes) {
        box[1] *= -1;
        for (int i = 0; i < 3; i++) {
            box[i] = idx[i][box[i]];
        }
        if (seg.prod(0, box[1]) < box[2]) {
            cout << "Yes" << endl;
            return 0;
        }
        if (box[2] < seg.get(box[1])) seg.set(box[1], box[2]);
    }
    cout << "No" << endl;
}
