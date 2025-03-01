#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    map<int, pair<int, int>> list;
    for (int i = 0; i < N; i++) {
        if (i > 0) list[A[i]].first = A[i - 1];
        if (i < N - 1) list[A[i]].second = A[i + 1];
    }
    list[A[0]].first = -1;
    list[A[N - 1]].second = -1;
    int Q;
    cin >> Q;
    while (Q--) {
        int t, x, y;
        cin >> t;
        if (t == 1) {
            cin >> x >> y;
            if (list[x].second != -1) list[list[x].second].first = y;
            list[y].first = x;
            list[y].second = list[x].second;
            list[x].second = y;
        }
        else {
            cin >> x;
            if (list[x].first == -1) list[list[x].second].first = -1;
            else if (list[x].second == -1) list[list[x].first].second = -1;
            else {
                list[list[x].first].second = list[x].second;
                list[list[x].second].first = list[x].first;
            }
            list.erase(x);
        }
    }

    int cur = 0;
    for (auto [key, val] : list) {
        if (val.first == -1) {
            cur = key;
            break;
        }
    }
    while (cur != -1) {
        cout << cur << " ";
        cur = list[cur].second;
    }
    cout << '\n';
}
