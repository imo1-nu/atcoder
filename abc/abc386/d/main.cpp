#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, int>> T;
    for (int i = 0; i < M; ++i) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        int z;
        if (c == 'W') z = 0;
        else z = 1;
        T.emplace_back(x, y, z);
    }
    sort(T.begin(), T.end());

    multiset<int> s;
    for (auto [x, y, z] : T) {
        if (z == 0) s.insert(y);
        else {
            auto it = s.upper_bound(y);
            if (it != s.begin()) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
