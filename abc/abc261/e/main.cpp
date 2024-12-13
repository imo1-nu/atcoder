#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, X;
    cin >> N >> X;
    vector<int> T(N), A(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i] >> A[i];
    }

    vector<int> ans(N + 1);
    for (int i = 0; i < 30; ++i) {
        vector<int> func = {0, 1};
        int cur = X >> i & 1;
        for (int j = 0; j < N; ++j) {
            vector<int> next(2);
            int x = A[j] >> i & 1;
            if (T[j] == 1) next = {0 & x, 1 & x};
            if (T[j] == 2) next = {0 | x, 1 | x};
            if (T[j] == 3) next = {0 ^ x, 1 ^ x};
            func = {next[func[0]], next[func[1]]};
            cur = func[cur];
            ans[j] |= cur << i;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << endl;
    }
}
