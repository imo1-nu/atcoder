#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<bool> covered(N, false);
    vector<char> color(N, 'a');
    vector<int> opened_at(N, -1);

    pair<char, int> last = {'a', -1};
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            x--;
            if (!covered[x] && opened_at[x] < last.second) color[x] = last.first;
            if (covered[x]) opened_at[x] = i;
            covered[x] = !covered[x];
        }
        else {
            char c;
            cin >> c;
            last = {c, i};
        }
    }
    for (int i = 0; i < N; i++) {
        if (!covered[i] && opened_at[i] < last.second) color[i] = last.first;
        cout << color[i];
    }
    cout << endl;
}
